#include "GL.h"
#include "GLTypes.h"


TextureFormatInfo k_TextureFormatInfo[GLTF_NUM_TEXTURE_FORMATS] = {
        {0, 0, 0,                                                                              0, 0,  "GLTF INVALID!!"},
        {GL_RGBA8,                         GL_BGRA,            GL_UNSIGNED_INT_8_8_8_8_REV,    0, 4,  "ARGB8888"},
        {GL_RGB8,                          GL_BGRA,            GL_UNSIGNED_INT_8_8_8_8_REV,    0, 4,  "XRGB8888"},
        {GL_RGBA8,                         GL_RGBA,            GL_UNSIGNED_INT_8_8_8_8,        0, 4,  "RGBA8888"},
        {GL_RGBA8,                         GL_RGBA,            GL_UNSIGNED_INT_8_8_8_8_REV,    0, 4,  "ABGR8888"},
        {GL_RGB8,                          GL_BGRA,            GL_UNSIGNED_INT_8_8_8_8_REV,    0, 4,  "ARGB0888"},
        {GL_RGB8,                          GL_RGB,             GL_UNSIGNED_BYTE,               0, 3,  "RGB888"},
        {GL_RGB8,                          GL_BGR,             GL_UNSIGNED_BYTE,               0, 3,  "BGR888"},
        {GL_RGBA32F_ARB,                   GL_RGBA,            GL_FLOAT,                       0, 16, "RGBA32F"},
        {GL_RGBA16F_ARB,                   GL_RGBA,            GL_HALF_FLOAT,                  0, 8,  "RGBA16F"},
        {GL_RGB16F_ARB,                    GL_RGB,             GL_HALF_FLOAT,                  0, 6,  "RG16F"},
        {GL_DEPTH_COMPONENT32,             GL_DEPTH_COMPONENT, GL_UNSIGNED_INT,                0, 4,  "D32"},
        {GL_DEPTH_COMPONENT24,             GL_DEPTH_COMPONENT, GL_UNSIGNED_INT,                0, 4,  "D24"},
        {GL_DEPTH_COMPONENT16,             GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT,              0, 2,  "D16"},
        {GL_DEPTH_COMPONENT32,             GL_DEPTH_COMPONENT, GL_HALF_FLOAT,                  0, 4,  "DF"},
        {GL_DEPTH24_STENCIL8,              GL_DEPTH_STENCIL,   GL_UNSIGNED_INT_24_8,           0, 4,  "D24S8"},
        {GL_ALPHA8,                        GL_STENCIL_INDEX,   GL_UNSIGNED_BYTE,               0, 1,  "S8"},
        {GL_RGBA4,                         GL_BGRA,            GL_UNSIGNED_SHORT_4_4_4_4_REV,  0, 2,  "ARGB4444"},
        {GL_RGB5_A1,                       GL_BGRA,            GL_UNSIGNED_SHORT_1_5_5_5_REV,  0, 2,  "ARGB1555"},
        {GL_RGB5,                          GL_BGRA,            GL_UNSIGNED_SHORT_1_5_5_5_REV,  0, 2,  "ARGB0555"},
        {GL_RGB,                           GL_RGB,             GL_UNSIGNED_SHORT_5_6_5,        0, 2,  "RGB565"},
        {GL_RGBA,                          GL_BGRA,            GL_UNSIGNED_INT_2_10_10_10_REV, 0, 4,  "A2RGB10"},
        {GL_RGB16,                         GL_RGB,             GL_UNSIGNED_SHORT,              0, 6,  "RGB16"},
        {GL_LUMINANCE8,                    GL_LUMINANCE,       GL_UNSIGNED_BYTE,               0, 1,  "L8"},
        {GL_ALPHA8,                        GL_ALPHA,           GL_UNSIGNED_BYTE,               0, 1,  "A8"},
        {GL_LUMINANCE8_ALPHA8,             GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE,               0, 2,  "A8L8"},
        {GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, GL_RGBA,            GL_UNSIGNED_BYTE,               1, 8,  "DXT1"},
        {GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, GL_RGBA,            GL_UNSIGNED_BYTE,               1, 16, "DXT3"},
        {GL_COMPRESSED_RGBA_S3TC_DXT5_EXT, GL_RGBA,            GL_UNSIGNED_BYTE,               1, 16, "DXT5"}
};

VertexTypeInfo k_VertexTypeInfo[GLVT_NUM_VERTEX_TYPES] = {
        {0,                 0, 0, 0,  "INVALID"},
        {GL_FLOAT,          1, 0, 4,  "FLOAT1"},
        {GL_FLOAT,          2, 0, 8,  "FLOAT2"},
        {GL_FLOAT,          3, 0, 12, "FLOAT3"},
        {GL_FLOAT,          4, 0, 16, "FLOAT4"},
        {GL_UNSIGNED_BYTE,  4, 0, 4,  "UBYTE4"},
        {GL_UNSIGNED_BYTE,  4, 1, 4,  "UBYTE4N"},
        {GL_SHORT,          1, 0, 2,  "SHORT"},
        {GL_SHORT,          2, 0, 4,  "SHORT2"},
        {GL_SHORT,          4, 0, 8,  "SHORT4"},
        {GL_SHORT,          2, 1, 4,  "SHORT2N"},
        {GL_SHORT,          4, 1, 8,  "SHORT4N"},
        {GL_UNSIGNED_SHORT, 2, 1, 4,  "USHORT2N"},
        {GL_UNSIGNED_SHORT, 4, 1, 8,  "USHORT4N"}
};
