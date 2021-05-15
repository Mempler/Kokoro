set(RequiredComponents
)

add_library(kokoro_memory INTERFACE)
    target_include_directories(kokoro_memory INTERFACE include)
    target_link_libraries(kokoro_memory INTERFACE ${RequiredComponents})
    
add_library(Kokoro::Memory ALIAS kokoro_memory)


# Testing
if (KOKORO_TESTING)
	add_executable(Kokoro_MemoryTest tests/Buffer.cc)
		target_link_libraries(Kokoro_MemoryTest PRIVATE Kokoro::Memory gtest gmock gtest_main)
endif()
