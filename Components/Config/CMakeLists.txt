set(RequiredComponents
)

add_library(kokoro_config INTERFACE)
    target_include_directories(kokoro_config INTERFACE include)
    target_link_libraries(kokoro_config ${RequiredComponents})
    
add_library(Kokoro::Config ALIAS kokoro_config)
