cmake_minimum_required(VERSION 3.0.0)

project(kokoro_eventpipeline VERSION "1.0" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} INTERFACE)
    target_include_directories(${PROJECT_NAME} INTERFACE include)
    
add_library(Kokoro::EventPipeline ALIAS ${PROJECT_NAME})

# Testing
if (KOKORO_TESTING)
	include(FetchContent)
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG release-1.10.0
	)
	FetchContent_MakeAvailable(googletest)

	include(GoogleTest)

	add_executable(Kokoro_EventPipelineTest tests/EventPipeline.cc)
		target_link_libraries(Kokoro_EventPipelineTest PRIVATE Kokoro::EventPipeline gtest gtest_main)

	gtest_add_tests(TARGET Kokoro_EventPipelineTest)
endif()
