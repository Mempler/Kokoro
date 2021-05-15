cmake_minimum_required(VERSION 3.0.0)
project(Kokoro VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

option(KOKORO_TESTING "Enable Testing" OFF)

# Testing
if (KOKORO_TESTING)
	include(FetchContent)
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG release-1.10.0
	)
	FetchContent_MakeAvailable(googletest)
endif()

add_subdirectory(Components)
