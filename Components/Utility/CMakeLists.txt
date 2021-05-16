set(RequiredComponents
    Kokoro::Memory
)

add_library(kokoro_utility INTERFACE)
    target_include_directories(kokoro_utility INTERFACE include)
    target_link_libraries(kokoro_utility INTERFACE ${RequiredComponents})
    
add_library(Kokoro::Utility ALIAS kokoro_utility)


# Testing
if (KOKORO_TESTING)
	add_executable(Kokoro_UtilityTest tests/ArgParser.cc)
		target_link_libraries(Kokoro_UtilityTest PRIVATE Kokoro::Utility gtest gmock gtest_main)
endif()
