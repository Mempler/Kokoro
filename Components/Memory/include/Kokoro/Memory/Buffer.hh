#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>
#include <new>
#include <string>
#include <vector>

namespace Kokoro::Memory
{
    template <typename _Alloc = std::allocator<uint8_t>>
    class Buffer
    {
      public:
        typedef uint8_t value_type;
        typedef std::vector<value_type, _Alloc> vector_type;

        Buffer( ) = default;
        Buffer( uint8_t* pData, size_t sSize ) :
            m_vInnerBuffer( pData, pData + sSize )
        {
        }
        Buffer( const vector_type& vData ) : m_vInnerBuffer( vData )
        {
        }

        void Append( const vector_type& vData )
        {
            // preallocate memory
            m_vInnerBuffer.reserve( m_vInnerBuffer.size( ) );
            m_vInnerBuffer.insert( m_vInnerBuffer.end( ), vData.begin( ),
                                   vData.end( ) );
        }

        /*****************************************************
         * Push
         *
         * Pushes a value onto the buffer
         *
         * @param tVal Value
         *
         * @return Self
         *****************************************************/
        template <typename T>
        Buffer* Push( T tVal )
        {
            size_t vSz = sizeof( T );
            prealloc( vSz );

            uint8_t* vPtr;
            if ( std::is_pointer<T>::value )  // This is fine if we're on an x86
                                              // CPU as it uses little endian by
                                              // default!
                vPtr = *(uint8_t**) &tVal;
            else
                vPtr = (uint8_t*) &tVal;

            if ( std::is_same<T, std::string>::value )  // Implementation for
                                                        // wrapping strings
            {
                auto inner = *(std::string*) ( &tVal );
                vPtr = nullptr;
                vSz = 0;

                this->Push( inner.c_str( ) );
            }

            if ( std::is_same<T, const char*>::value )  // Implementation for
                                                        // wrapping const char*
            {
                vPtr = *(uint8_t**) &tVal;
                vSz = strlen( (const char*) vPtr );

                prealloc( vSz );
            }

            std::copy( vPtr, vPtr + vSz, std::back_inserter( m_vInnerBuffer ) );

            return this;
        }

        /*****************************************************
         * Pop
         *
         * Pops and returns a value from the buffer
         *
         * NOTE: It wont be removed! it'll just increase
         *       an internal value
         *
         * @param tVal Value
         *
         * @return Self
         *****************************************************/
        template <typename T>
        T Pop( size_t sSize )
        {
            T* vPtr = (T*) ( m_vInnerBuffer.data( ) + m_sPos );
            m_sPos += sSize;

            if ( std::is_same<T, std::string>::value )  // Implementation for
                                                        // wrapping strings
            {
                std::string empty = std::string( (const char*) vPtr,
                                                 (const char*) vPtr + sSize );

                return *(T*) &empty;
            }

            if ( std::is_same<T, const char*>::value )  // Implementation for
                                                        // wrapping const char*
            {
                auto buff = new char [ sSize + 1 ];
                std::copy( (char*) vPtr, (char*) vPtr + sSize, buff );
                buff [ sSize ] = 0;  // Set null terminator
                vPtr = (T*) buff;
                return *( (T*) &vPtr );
            }

            return *vPtr;
        }

        /*****************************************************
         * Data
         *
         * if called, Returns it's inner data
         *
         * @return Written data
         *****************************************************/
        const vector_type& data( )
        {
            return this->m_vInnerBuffer;
        }

      private:
        void prealloc( size_t l )
        {
            if ( m_vInnerBuffer.capacity( ) < m_vInnerBuffer.size( ) + l )
                m_vInnerBuffer.reserve( m_vInnerBuffer.capacity( ) + 1024 );
        }

        size_t m_sPos { };
        vector_type m_vInnerBuffer { };
    };
}  // namespace Kokoro::Memory
