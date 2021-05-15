#include "Kokoro/Memory/Buffer.hh"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST( Buffer, PushI8 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<int8_t>( 0x0F );

    ASSERT_THAT( buffer.data( ), testing::ElementsAre( 0x0F ) );
}

TEST( Buffer, PushI16 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<int16_t>( 0xFFFA );

    ASSERT_THAT( buffer.data( ), testing::ElementsAre( 0xFA, 0xFF ) );
}

TEST( Buffer, PushI32 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<int32_t>( 0xFFFFFFFA );

    ASSERT_THAT( buffer.data( ),
                 testing::ElementsAre( 0xFA, 0xFF, 0xFF, 0xFF ) );
}

TEST( Buffer, PushI64 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<int64_t>( 0xFFFFFFFFFFFFFFFA );

    ASSERT_THAT( buffer.data( ),
                 testing::ElementsAre( 0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                       0xFF ) );
}

TEST( Buffer, PushU8 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<uint8_t>( 0x0F );

    ASSERT_THAT( buffer.data( ), testing::ElementsAre( 0x0F ) );
}

TEST( Buffer, PushU16 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<uint16_t>( 0xFFFA );

    ASSERT_THAT( buffer.data( ), testing::ElementsAre( 0xFA, 0xFF ) );
}

TEST( Buffer, PushU32 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<uint32_t>( 0xFFFFFFFA );

    ASSERT_THAT( buffer.data( ),
                 testing::ElementsAre( 0xFA, 0xFF, 0xFF, 0xFF ) );
}

TEST( Buffer, PushU64 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<uint64_t>( 0xFFFFFFFFFFFFFFFA );

    ASSERT_THAT( buffer.data( ),
                 testing::ElementsAre( 0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                       0xFF ) );
}

TEST( Buffer, PushFloat )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<float>( 0.12345f );

    ASSERT_THAT( buffer.data( ),
                 testing::ElementsAre( 0x5B, 0xD3, 0xFC, 0x3D ) );
}

TEST( Buffer, PushDouble )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<double>( 0.12345 );

    ASSERT_THAT( buffer.data( ),
                 testing::ElementsAre( 0x7C, 0xF2, 0xB0, 0x50, 0x6B, 0x9A, 0xBF,
                                       0x3F ) );
}

TEST( Buffer, PushCString )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<const char*>( "Hello World!" );

    ASSERT_THAT( buffer.data( ),
                 testing::ElementsAre( 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o',
                                       'r', 'l', 'd', '!' ) );
}

TEST( Buffer, PushCPPString )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<std::string>( "Hello World!" );

    ASSERT_THAT( buffer.data( ),
                 testing::ElementsAre( 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o',
                                       'r', 'l', 'd', '!' ) );
}

TEST( Buffer, PopI8 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<int8_t>( 0x0F );

    ASSERT_EQ( buffer.Pop<int8_t>( 1 ), 0x0F );
}

TEST( Buffer, PopI16 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<int16_t>( 0xFFFA );

    ASSERT_EQ( buffer.Pop<int16_t>( 2 ), -6 );
}

TEST( Buffer, PopI32 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<int32_t>( 0xFFFFFFFA );

    ASSERT_EQ( buffer.Pop<int32_t>( 4 ), 0xFFFFFFFA );
}

TEST( Buffer, PopI64 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<int64_t>( 0xFFFFFFFFFFFFFFFA );

    ASSERT_EQ( buffer.Pop<int64_t>( 8 ), 0xFFFFFFFFFFFFFFFA );
}

TEST( Buffer, PopU8 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<uint8_t>( 0x0F );

    ASSERT_EQ( buffer.Pop<uint8_t>( 1 ), 0x0F );
}

TEST( Buffer, PopU16 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<uint16_t>( 0xFFFA );

    ASSERT_EQ( buffer.Pop<uint16_t>( 2 ), 0xFFFA );
}

TEST( Buffer, PopU32 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<uint32_t>( 0xFFFFFFFA );

    ASSERT_EQ( buffer.Pop<uint32_t>( 4 ), 0xFFFFFFFA );
}

TEST( Buffer, PopU64 )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<uint64_t>( 0xFFFFFFFFFFFFFFFA );

    ASSERT_EQ( buffer.Pop<uint64_t>( 8 ), 0xFFFFFFFFFFFFFFFA );
}

TEST( Buffer, PopFloat )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<float>( 0.12345f );

    ASSERT_EQ( buffer.Pop<float>( 4 ), 0.12345f );
}

TEST( Buffer, PopDouble )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<double>( 0.12345 );

    ASSERT_EQ( buffer.Pop<double>( 8 ), 0.12345 );
}

TEST( Buffer, PopCString )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<const char*>( "Hello World!" );

    ASSERT_STREQ( buffer.Pop<const char*>( 12 ), "Hello World!" );
}

TEST( Buffer, PopCPPString )
{
    Kokoro::Memory::Buffer buffer;

    buffer.Push<std::string>( "Hello World!" );

    ASSERT_EQ( buffer.Pop<std::string>( 12 ), "Hello World!" );
}
