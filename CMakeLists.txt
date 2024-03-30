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
)

add_executable(warden main.cpp ${dir_src}
        Graphic/CGxFormat.h
        Graphic/CGxCaps.cpp
        Graphic/CGxCaps.h
        Graphic/CGxShader.cpp
        Graphic/CGxShader.h
        Graphic/CGxMatrixStack.cpp
        Graphic/CGxMatrixStack.h
        Graphic/CGxBuf.h
        Graphic/CGxPool.h
        Graphic/const/EGxPoolTarget.h
        Graphic/CGxVertexAttrib.cpp
        Graphic/CGxVertexAttrib.h
        Graphic/const/EGxPoolHintBits.h
        Graphic/const/EGxVertexBufferFormat.h
        Graphic/ShaderConstants.h
        Game/CBoundingBox.h
        NTempest/CRange.h
        Graphic/const/EGxPoolUsage.h
        Graphic/CGxPool.cpp
        Graphic/CGxString.cpp
        Graphic/CGxString.h
        Graphic/TEXTLINETEXTURE.h
        Graphic/VERT.h
        Graphic/TEXTLINETEXTURE.cpp
        Graphic/CGxFont.cpp
        Graphic/CGxFont.h
        Graphic/TEXTURECACHE.cpp
        Graphic/TEXTURECACHE.h
        Graphic/TEXTURECACHEROW.cpp
        Graphic/TEXTURECACHEROW.h
        Graphic/KERNNODE.cpp
        Graphic/KERNNODE.h
        Graphic/KERNINGHASHKEY.cpp
        Graphic/KERNINGHASHKEY.h
        Graphic/CHARCODEDESC.cpp
        Graphic/CHARCODEDESC.h
        Graphic/GLYPHBITMAPDATA.cpp
        Graphic/GLYPHBITMAPDATA.h)
target_include_directories(warden PRIVATE "include/")
