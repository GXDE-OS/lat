#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "wrapper.h"
#include "bridge.h"
#include "library_private.h"

#ifdef ANDROID
    const char* libxrenderName = "libXrender.so";
#else
    const char* libxrenderName = "libXrender.so.1";
#endif

#define LIBNAME libxrender

#ifdef ANDROID
    #define CUSTOM_INIT \
        setNeededLibs(lib, 4,           \
            "libX11.so",              \
            "libxcb.so",              \
            "libXau.so",              \
            "libXdmcp.so");
#else
    #define CUSTOM_INIT \
        setNeededLibs(lib, 4,           \
            "libX11.so.6",              \
            "libxcb.so.1",              \
            "libXau.so.6",              \
            "libXdmcp.so.6");
#endif

#include "wrappedlib_init.h"

