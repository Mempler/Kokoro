set(RequiredComponents
	Kokoro::Config
	Kokoro::Exception
)

add_library(kokoro_filesystem INTERFACE)
    target_include_directories(kokoro_filesystem INTERFACE include)
    target_link_libraries(kokoro_filesystem INTERFACE ${RequiredComponents})
    
add_library(Kokoro::FileSystem ALIAS kokoro_filesystem)

# Testing
if (KOKORO_TESTING)
	add_executable(Kokoro_FileSystemTest tests/FileSystem.cc)
		target_link_libraries(Kokoro_FileSystemTest PRIVATE Kokoro::FileSystem gtest gmock gtest_main)
endif()
