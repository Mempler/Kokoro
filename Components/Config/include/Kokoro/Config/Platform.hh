#pragma once

#ifdef __linux__
    #define KOKORO_LINUX 1
#else
    #define KOKORO_LINUX 0
#endif

#ifdef _WIN32
    #define KOKORO_WIN32 1
#else
    #define KOKORO_WIN32 0
#endif

#ifdef __EMSCRIPTEN__
    #define KOKORO_EMSCRIPTEN 1
#else
    #define KOKORO_EMSCRIPTEN 0
#endif

#ifdef __ANDROID__
    #define KOKORO_ANDROID 1
#else
    #define KOKORO_ANDROID 0
#endif
