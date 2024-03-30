// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

#include "CGxDevice.h"

void CGxDevice::XformViewport(float &, float &, float &, float &, float &, float &) {

}

void CGxDevice::XformView(C44Matrix &) {

}

void CGxDevice::XformSetViewport(float, float, float, float, float, float) {

}

void CGxDevice::XformSet(EGxXform xf, const C44Matrix &matrix) {

}

void CGxDevice::XformPush(EGxXform xf) {

}

void CGxDevice::XformProjNative(C44Matrix &) {

}

void CGxDevice::XformProjection(C44Matrix &) {

}

void CGxDevice::XformPop(EGxXform xf) {

}

void CGxDevice::TexSetWrap(CGxTex *texId, EGxTexWrapMode wrapU, EGxTexWrapMode wrapV) {

}

void CGxDevice::TexMarkForUpdate(CGxTex *, const CiRect &, int32_t) {

}

void CGxDevice::ShaderConstantsUnlock(EGxShTarget target, uint32_t index, uint32_t count) {

}

char *CGxDevice::ShaderConstantsLock(EGxShTarget target) {
    return nullptr;
}

void CGxDevice::ShaderConstantsClear(void) {

}

void CGxDevice::RsPush(void) {

}

void CGxDevice::RsPop(void) {

}

void CGxDevice::RsSetAlphaRef(void) {

}

void CGxDevice::RsSet(EGxRenderState, void *) {

}

void CGxDevice::RsSet(EGxRenderState, int32_t) {

}

void CGxDevice::RsGet(EGxRenderState, int32_t &) {

}

void CGxDevice::PrimVertexPtr(CGxBuf *, EGxVertexBufferFormat) {

}

void CGxDevice::PrimVertexMask(uint32_t) {

}

void CGxDevice::PrimVertexFormat(CGxBuf *, CGxVertexAttrib *, uint32_t) {

}

void CGxDevice::PrimIndexPtr(CGxBuf *) {

}

CGxPool *CGxDevice::PoolCreate(EGxPoolTarget, EGxPoolUsage, uint32_t, EGxPoolHintBits, const char *) {
    return nullptr;
}

int32_t CGxDevice::MasterEnable(EGxMasterEnables) {
    return 0;
}

void CGxDevice::ITexWHDStartEnd(CGxTex *, uint32_t &, uint32_t &, uint32_t &, uint32_t &) {

}

void CGxDevice::ITexBind(void) {

}

void CGxDevice::IShaderLoad(CGxShader **, EGxShTarget, const char *, const char *, int32_t) {

}

void CGxDevice::IShaderBind(void) {

}

void CGxDevice::IRsSync(int32_t) {

}

void CGxDevice::IRsInit(void) {

}

void CGxDevice::IRsForceUpdate(EGxRenderState) {

}

void CGxDevice::IRsForceUpdate(void) {

}

void CGxDevice::IRsDirty(EGxRenderState) {

}

int32_t CGxDevice::IDevIsWindowed() {
    return 0;
}

const CRect &CGxDevice::DeviceDefWindow(void) {
    return <#initializer#>;
}

void CGxDevice::DeviceSetDefWindow(const CRect &) {

}

void CGxDevice::DeviceSetCurWindow(const CRect &) {

}

const CRect &CGxDevice::DeviceCurWindow(void) {
    return <#initializer#>;
}

void CGxDevice::DeviceCreateStreamBufs(void) {

}

void CGxDevice::DeviceCreatePools(void) {

}

CGxBuf *CGxDevice::BufStream(EGxPoolTarget, uint32_t, uint32_t) {
    return nullptr;
}

CGxBuf *CGxDevice::BufCreate(CGxPool *, uint32_t, uint32_t, uint32_t) {
    return nullptr;
}

const CGxCaps &CGxDevice::Caps() const {
    return <#initializer#>;
}

CGxDevice::CGxDevice() {

}
