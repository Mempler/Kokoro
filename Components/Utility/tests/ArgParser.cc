#include "Kokoro/Utility/ArgParser.hh"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST( ArgParser, HasArg )
{
    std::vector<const char*> _args { "-server" };

    Kokoro::Utility::ArgParser args( _args.size( ), _args.data( ) );

    ASSERT_TRUE( args.HasArg( "server" ) );
    ASSERT_FALSE( args.HasArg( "port" ) );
}

TEST( ArgParser, HasConfig )
{
    std::vector<const char*> _args { "+port", "27015" };

    Kokoro::Utility::ArgParser args( _args.size( ), _args.data( ) );

    ASSERT_TRUE( args.HasConfig( "port" ) );
    ASSERT_FALSE( args.HasConfig( "server" ) );
}

TEST( ArgParser, GetConfig )
{
    std::vector<const char*> _args { "+port", "27015" };

    Kokoro::Utility::ArgParser args( _args.size( ), _args.data( ) );

    std::string port;

    ASSERT_TRUE( args.GetConfig( "port", &port ) );
    ASSERT_EQ( port, "27015" );

    ASSERT_FALSE( args.GetConfig( "server", &port ) );
    ASSERT_EQ( port, "27015" );
}
