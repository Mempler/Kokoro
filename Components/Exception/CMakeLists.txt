set(RequiredComponents
    Kokoro::fmt
)

add_library(kokoro_exception INTERFACE)
    target_include_directories(kokoro_exception INTERFACE include)
    target_link_libraries(kokoro_exception INTERFACE ${RequiredComponents})
    
add_library(Kokoro::Exception ALIAS kokoro_exception)
