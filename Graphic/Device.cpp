#include "Device.h"
#include "CGxDevice.h"
#include "Gx.h"

CGxDevice *g_theGxDevicePtr = nullptr;

CGxDevice *
GxDevCreate(EGxApi api, int32_t (*windowProc)(void *window, uint32_t message, uintptr_t wparam, intptr_t lparam),
            const CGxFormat &format) {
    CGxDevice *device;


    if (api == GxApi_GLL) {
        device = CGxDevice::NewGLL();
    } else if (api == GxApi_OpenGl) {
        device = CGxDevice::NewOpenGl();
    } else {

    }


    g_theGxDevicePtr = device;

    if (g_theGxDevicePtr->DeviceCreate(windowProc, format)) {
        return g_theGxDevicePtr;
    } else {
        if (g_theGxDevicePtr) {
            delete g_theGxDevicePtr;
        }

        return nullptr;
    }
}

EGxApi GxDevApi() {
    return g_theGxDevicePtr->m_api;
}

void *GxDevWindow() {
    return g_theGxDevicePtr->DeviceWindow();
}

int32_t GxMasterEnable(EGxMasterEnables state) {
    return g_theGxDevicePtr->MasterEnable(state);
}
