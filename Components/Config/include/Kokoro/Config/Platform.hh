#pragma once

#ifdef __linux__
    #define KOKORO_LINUX 1
#endif

#ifdef _WIN32
    #define KOKORO_WIN32 1
#endif

#ifdef __EMSCRIPTEN__
    #define KOKORO_EMSCRIPTEN 1
#endif

#ifdef __ANDROID__
    #define KOKORO_ANDROID 1
#endif
