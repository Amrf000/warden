#pragma once


#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include "Storm/Thread.h"
#include "GLTypes.h"
#include "GLAbstractWindow.h"


//typedef struct objc_object NSOpenGLContext;
typedef struct objc_object NSOpenGLPixelFormat;
typedef int CFDictionaryRef;

class GLDevice;

class GLContext {
public:
    // Types
    struct Context {
        HGLRC *context;// NSOpenGLContext
        int pixelFormat;//NSOpenGLPixelFormat *
        int32_t sampleCount;

        ~Context();
    };

    struct GammaFormula {
        float m_RedMin;
        float m_RedMax;
        float m_RedGamma;
        float m_GreenMin;
        float m_GreenMax;
        float m_GreenGamma;
        float m_BlueMin;
        float m_BlueMax;
        float m_BlueGamma;
    };

    // Static variables
    static HGLRC s_MainContext;// NSOpenGLContext *
    static Blizzard::Thread::TLSSlot s_CurrentContext;
    static Blizzard::Thread::TLSSlot s_CurrentGLContext;
    static CFDictionaryRef s_DesktopMode;

    // Static functions
    static HGLRC GetNSOpenGLCurrentContext(void);//NSOpenGLContext *

    static HGLRC GetCurrentContext(void);//NSOpenGLContext *

    static void SetCurrentContext(HGLRC);//NSOpenGLContext *

    static GLContext *GetCurrentGLContext(void);

    static void SetCurrentGLContext(GLContext *);

    // Member variables
    std::basic_string<char, std::char_traits<char>, std::allocator<char>> m_DebugName;
    std::map<uint32_t, GLContext::Context, std::less<uint32_t>, std::allocator<std::pair<const uint32_t, GLContext::Context>>> m_Contexts;
    Context *m_Context;
    GLDevice *m_Device;
    GLAbstractWindow *m_Window{nullptr};
    bool m_Windowed;
    bool m_MTGLEnabled;
    bool m_VSyncEnabled;
    bool m_CaptureDisplay;
    uint32_t m_Width;
    uint32_t m_Height;
    uint32_t m_RefreshRate;
    GammaFormula m_GammaFormula;
    bool m_GammaTablesSet;
    std::vector<uint16_t, std::allocator<uint16_t>> m_GammaTableR;
    std::vector<uint16_t, std::allocator<uint16_t>> m_GammaTableG;
    std::vector<uint16_t, std::allocator<uint16_t>> m_GammaTableB;
    std::vector<uint16_t, std::allocator<uint16_t>> m_OsGammaTableR;
    std::vector<uint16_t, std::allocator<uint16_t>> m_OsGammaTableG;
    std::vector<uint16_t, std::allocator<uint16_t>> m_OsGammaTableB;

    // Member functions
    GLContext(GLDevice *, const char *);

    int32_t GetBackingWidth();

    int32_t GetBackingHeight();

    int32_t GetWidth(void);

    int32_t GetHeight(void);

    bool IsCurrentContext(void);

    void MakeCurrent(bool);

    void SetContextFormat(GLTextureFormat, uint32_t);

    void SetFullscreenMode(uint32_t, uint32_t, uint32_t, bool);

    void SetWindow(GLAbstractWindow *, bool);

    void Swap(void);

    void Update(void);
};


