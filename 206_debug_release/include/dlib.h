#pragma once

#ifdef _WIN32
    #ifdef dlib_EXPORTS
        #define XCPP_API __declspec(dllexport)
    #else
        #define XCPP_API __declspec(dllimport)
    #endif
#else
    #define XCPP_API
#endif

XCPP_API void DLib();
