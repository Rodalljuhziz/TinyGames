###########################################################################
# GoogleTest
###########################################################################
if (MSVC)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries (DLLs)." FORCE)
endif()

include(FetchContent)
FetchContent_Declare( googletest
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)