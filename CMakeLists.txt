cmake_minimum_required(VERSION 3.27)
project(warden)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    add_compile_options(/wd4819)
endif ()

file(GLOB dir_src
        "Agile/*.h"
        "Agile/*.cpp"
        "Common/*.h"
        "Common/*.cpp"
        "NIpse/*.h"
        "NIpse/*.cpp"
        "NTempest/*.h"
        "NTempest/*.cpp"
        "Graphic/*.h"
        "Graphic/*.cpp"
        "Storm/*.h"
        "Storm/*.cpp"
        "include/*.h"
        "Anim/*.h"
        "Anim/*.cpp"
        "Services/*.h"
        "Services/*.cpp"
        "Scrn/*.h"
        "Scrn/*.cpp"
)

add_executable(warden main.cpp ${dir_src}
        NTempest/C4iRect.h
        NTempest/CRandSeed.h
        NTempest/CDynParms.h
        Common/SoftFloat.cpp
        Common/SoftFloat.h)
target_include_directories(warden PRIVATE "include/")
