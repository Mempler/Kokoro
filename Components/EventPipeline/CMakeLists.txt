set(RequiredComponents
)

add_library(kokoro_eventpipeline INTERFACE)
    target_include_directories(kokoro_eventpipeline INTERFACE include)
	target_link_libraries(kokoro_eventpipeline INTERFACE ${RequiredComponents})
    
add_library(Kokoro::EventPipeline ALIAS kokoro_eventpipeline)

# Testing
if (KOKORO_TESTING)
	add_executable(Kokoro_EventPipelineTest tests/EventPipeline.cc)
		target_link_libraries(Kokoro_EventPipelineTest PRIVATE Kokoro::EventPipeline gtest gtest_main)
endif()
