#pragma once

#include <unordered_map>

#include "BaseEvent.hh"

#include <memory>
#include <string>
#include <tuple>
#include <vector>

#define ImplementEventStuff( NAME )                                            \
  public:                                                                      \
    static std::unique_ptr<Kokoro::BaseEvent> create( )                        \
    {                                                                          \
        return std::unique_ptr<Kokoro::BaseEvent>( (BaseEvent*) new NAME );    \
    }

#define RegisterEvent( NAME )                                                  \
    namespace                                                                  \
    {                                                                          \
        Kokoro::BaseEvent::Registrar<NAME> registrar( #NAME );                 \
    }

namespace Kokoro
{
    class EventPipeline
    {
      private:
      public:
        template <typename... Args>
        void Execute( std::string const& sName, Args&&... tVal )
        {
            std::unique_ptr<BaseEvent> event = BaseEvent::instantiate( sName );

            if ( event == nullptr )
            {
                // TODO: throw an error? maybe just log if this event
                // doesn't exists
                return;
            }

            event->Execute( std::vector<void*> { (void*) tVal... } );
        }
    };
}  // namespace Kokoro
