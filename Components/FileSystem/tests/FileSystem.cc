#include "Kokoro/FileSystem.hh"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST( FileSystem, CreateDirectory )
{
    Kokoro::FileSystem::CreateDirectory( "./TestDir" );

    ASSERT_TRUE( Kokoro::FileSystem::Exists( "./TestDir" ) );
    ASSERT_FALSE( Kokoro::FileSystem::Exists( "./TestDir2" ) );
}

TEST( FileSystem, Exists )
{
    Kokoro::FileSystem::CreateDirectory( "./TestDir" );

    ASSERT_TRUE( Kokoro::FileSystem::Exists( "./TestDir" ) );
    ASSERT_FALSE( Kokoro::FileSystem::Exists( "./TestDir2" ) );
}

TEST( FileSystem, JoinPath )
{
    ASSERT_EQ( "./test/dir", Kokoro::FileSystem::JoinPath( "./test/", "dir" ) );
}

TEST( FileSystem, IsDirectory )
{
    Kokoro::FileSystem::CreateDirectory( "./TestDir" );
    Kokoro::FileSystem::Touch( "./TestFile" );

    ASSERT_TRUE( Kokoro::FileSystem::IsDirectory( "./TestDir" ) );
    ASSERT_FALSE( Kokoro::FileSystem::IsDirectory( "./TestDir2" ) );
    ASSERT_FALSE( Kokoro::FileSystem::IsDirectory( "./TestFile" ) );
}

TEST( FileSystem, ReadDirectory )
{
    Kokoro::FileSystem::CreateDirectory( "./TestDir" );
    Kokoro::FileSystem::CreateDirectory( "./TestDir/Dir" );
    Kokoro::FileSystem::Touch( "./TestDir/File" );

    auto dir_info = Kokoro::FileSystem::ReadDirectory( "./TestDir" );

    ASSERT_THAT( dir_info,
                 testing::ElementsAre( "./TestDir/Dir", "./TestDir/File" ) );
}

TEST( FileSystem, ResolveFullPath )
{
    ASSERT_NE( Kokoro::FileSystem::ResolveFullPath( "." ),
               "" );  // there is no real way we could test it, other than it's
                      // not being empty
}

TEST( FileSystem, ReadBinaryFile )
{
    std::vector<uint8_t> data = { 'M', 'e', 'm', 'p', 'l', 'e', 'r', 17 };

    Kokoro::FileSystem::WriteBinaryFile( "./TestFile", data );

    ASSERT_THAT(
        Kokoro::FileSystem::ReadBinaryFile( "./TestFile" ),
        testing::ElementsAre( 'M', 'e', 'm', 'p', 'l', 'e', 'r', 17 ) );
}

TEST( FileSystem, WriteBinaryFile )
{
    std::vector<uint8_t> data = { 'M', 'e', 'm', 'p', 'l', 'e', 'r', 17 };

    Kokoro::FileSystem::WriteBinaryFile( "./TestFile", data );

    ASSERT_THAT(
        Kokoro::FileSystem::ReadBinaryFile( "./TestFile" ),
        testing::ElementsAre( 'M', 'e', 'm', 'p', 'l', 'e', 'r', 17 ) );
}

TEST( FileSystem, HasExtension )
{
    Kokoro::FileSystem::Touch( "./TestFile.test" );

    auto testFile = (const char*) malloc( 16 );
    memcpy( (void*) testFile, "./TestFile.test", 16 );

    ASSERT_TRUE( Kokoro::FileSystem::HasExtension( testFile, ".test" ) );
    ASSERT_TRUE(
        Kokoro::FileSystem::HasExtension( "./TestFile.test", ".test" ) );
    ASSERT_FALSE(
        Kokoro::FileSystem::HasExtension( "./TestFile.test", ".est" ) );
}

TEST( FileSystem, GetFileName )
{
    ASSERT_EQ( Kokoro::FileSystem::GetFileName( "TestFile" ), "TestFile" );
    ASSERT_EQ( Kokoro::FileSystem::GetFileName( "./TestFile" ), "TestFile" );
    ASSERT_EQ( Kokoro::FileSystem::GetFileName( "./test/TestFile" ),
               "TestFile" );
}

TEST( FileSystem, Touch )
{
    Kokoro::FileSystem::Touch( "./TestFile" );

    ASSERT_TRUE( Kokoro::FileSystem::Exists( "./TestFile" ) );
    ASSERT_FALSE( Kokoro::FileSystem::Exists( "./TestFile2" ) );
}
