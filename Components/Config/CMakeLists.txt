cmake_minimum_required(VERSION 3.0.0)

project(kokoro_config VERSION "1.0" LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)
    target_include_directories(${PROJECT_NAME} INTERFACE include)
    
add_library(Kokoro::Config ALIAS ${PROJECT_NAME})
