set(RequiredComponents
    fmt
)

add_library(kokoro_fmt INTERFACE)
    target_include_directories(kokoro_fmt INTERFACE include)
    target_link_libraries(kokoro_fmt INTERFACE ${RequiredComponents})
    
add_library(Kokoro::fmt ALIAS kokoro_fmt)

# Testing
if (KOKORO_TESTING)
endif()
