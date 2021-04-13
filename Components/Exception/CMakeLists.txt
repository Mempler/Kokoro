cmake_minimum_required(VERSION 3.15)

project(kokoro_exception VERSION "1.0" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third-party/fmt)

add_library(${PROJECT_NAME} INTERFACE)
    target_include_directories(${PROJECT_NAME} INTERFACE include)
    target_link_libraries(${PROJECT_NAME} INTERFACE fmt)
    
add_library(Kokoro::Exception ALIAS ${PROJECT_NAME})
