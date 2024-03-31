cmake_minimum_required(VERSION 3.27)
project(warden)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    add_compile_options(/wd4819)
endif ()

file(GLOB_RECURSE dir_src
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
        "Glue/*.h"
        "Glue/*.cpp"
        "Event/*.h"
        "Event/*.cpp"
        "Net/*.h"
        "Net/*.cpp"
)
find_package(OpenGL REQUIRED)
add_executable(warden main.cpp ${dir_src})

target_include_directories(warden PRIVATE "/")
target_include_directories(warden PRIVATE "externel/freetype-2.0.9/include")
target_include_directories(warden PRIVATE "externel/")
include_directories(${OPENGL_INCLUDE_DIRS})

target_link_libraries(warden ${OPENGL_LIBRARIES})