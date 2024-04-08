#include "GLContext.h"

NSOpenGLContext *GLContext::s_MainContext;

GLContext::Context::~Context() {

}

NSOpenGLContext *GLContext::GetNSOpenGLCurrentContext(void) {
    return nullptr;
}

NSOpenGLContext *GLContext::GetCurrentContext(void) {
    return nullptr;
}

void GLContext::SetCurrentContext(NSOpenGLContext *) {

}

GLContext *GLContext::GetCurrentGLContext(void) {
    return nullptr;
}

void GLContext::SetCurrentGLContext(GLContext *) {

}

GLContext::GLContext(GLDevice *, const char *) {

}

int32_t GLContext::GetBackingWidth() {
    return 0;
}

int32_t GLContext::GetBackingHeight() {
    return 0;
}

int32_t GLContext::GetWidth(void) {
    return 0;
}

int32_t GLContext::GetHeight(void) {
    return 0;
}

bool GLContext::IsCurrentContext(void) {
    return false;
}

void GLContext::MakeCurrent(bool) {

}

void GLContext::SetContextFormat(GLTextureFormat, uint32_t) {

}

void GLContext::SetFullscreenMode(uint32_t, uint32_t, uint32_t, bool) {

}

void GLContext::SetWindow(GLAbstractWindow *, bool) {

}

void GLContext::Swap(void) {

}

void GLContext::Update(void) {

}
