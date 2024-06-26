#include "Screen.h"
#include "Console.h"
#include "Types.h"
#include "Graphic/font/CGxStringBatch.h"
#include "Graphic/Screen.h"
#include "Graphic/RenderState.h"
#include "Graphic/CGxDevice.h"
#include "Graphic/Draw.h"
#include "Graphic/Gx.h"
#include "Graphic/Coordinate.h"
#include "Graphic/Font.h"
#include "Handlers.h"
#include <algorithm>

static CGxStringBatch *s_batch;
static float s_caretpixwidth;
static float s_caretpixheight;
static float s_consoleLines = 10.0f;
static float s_fontHeight = 0.02f;
static float s_consoleHeight = s_consoleLines * s_fontHeight;
static char s_fontName[STORM_MAX_PATH];
static int32_t s_highlightState;
static HLAYER s_layerBackground;
static HLAYER s_layerText;
static RECTF s_rect = {0.0f, 1.0f, 1.0f, 1.0f};
static HTEXTFONT s_textFont;

static CImVector s_colorArray[] = {
        {0xFF, 0xFF, 0xFF, 0xFF}, // DEFAULT_COLOR
        {0xFF, 0xFF, 0xFF, 0xFF}, // INPUT_COLOR
        {0x80, 0x80, 0x80, 0xFF}, // ECHO_COLOR
        {0x00, 0x00, 0xFF, 0xFF}, // ERROR_COLOR
        {0x00, 0xFF, 0xFF, 0xFF}, // WARNING_COLOR
        {0xFF, 0xFF, 0xFF, 0xFF}, // GLOBAL_COLOR
        {0xFF, 0xFF, 0xFF, 0xFF}, // ADMIN_COLOR
        {0xFF, 0xFF, 0xFF, 0x80}, // HIGHLIGHT_COLOR
        {0x00, 0x00, 0x00, 0xC0}, // BACKGROUND_COLOR
};

void DrawBackground() {
    uint16_t indices[] = {
            0, 1, 2, 3
    };

    C3Vector position[] = {
            {s_rect.left,  s_rect.bottom, 0.0f},
            {s_rect.right, s_rect.bottom, 0.0f},
            {s_rect.left,  s_rect.top,    0.0f},
            {s_rect.right, s_rect.top,    0.0f}
    };

    GxRsPush();

    GxRsSet(GxRs_Lighting, 0);
    GxRsSet(GxRs_Fog, 0);
    GxRsSet(GxRs_DepthTest, 0);
    GxRsSet(GxRs_DepthWrite, 0);
    GxRsSet(GxRs_Culling, 0);
    GxRsSet(GxRs_PolygonOffset, 0.0f);
    GxRsSet(GxRs_BlendingMode, GxBlend_Alpha);
    GxRsSet(GxRs_AlphaRef, CGxDevice::s_alphaRef[GxBlend_Alpha]);

    GxPrimLockVertexPtrs(4, position, sizeof(C3Vector), nullptr, 0, &s_colorArray[BACKGROUND_COLOR], 0, nullptr, 0,
                         nullptr, 0, nullptr, 0);
    GxDrawLockedElements(GxPrim_TriangleStrip, 4, indices);
    GxPrimUnlockVertexPtrs();

    GxRsPop();
}

void DrawHighLight() {
    // TODO
}

void PaintBackground(void *param, const RECTF *rect, const RECTF *visible, float elapsedSec) {
    if (s_rect.bottom < 1.0f) {
        DrawBackground();

        if (s_highlightState) {
            DrawHighLight();
        }
    }
}

void PaintText(void *param, const RECTF *rect, const RECTF *visible, float elapsedSec) {
    // TODO
}

void ConsoleScreenAnimate(float elapsedSec) {
    auto finalPos = ConsoleGetActive() ? (std::min)(1.0f - s_consoleHeight, 1.0f) : 1.0f;
    finalPos = (std::max)(finalPos, 0.0f);

    if (s_rect.bottom == finalPos) {
        return;
    }

    auto currentPos = finalPos;

    if (ConsoleGetResizeState() == CS_NONE) {
        auto direction = s_rect.bottom <= finalPos ? 1.0f : -1.0f;

        currentPos = s_rect.bottom + direction * elapsedSec * 5.0f;
        currentPos = ConsoleGetActive() ? (std::max)(currentPos, finalPos) : (std::min)(currentPos, finalPos);
    }

    s_rect.bottom = currentPos;

    ScrnLayerSetRect(s_layerBackground, &s_rect);
    ScrnLayerSetRect(s_layerText, &s_rect);
}

void ConsoleScreenInitialize(const char *title) {
    CRect windowSize;
    GxCapsWindowSize(windowSize);

    auto width = windowSize.maxX - windowSize.minX;
    auto height = windowSize.maxY - windowSize.minY;
    s_caretpixwidth = width == 0.0f ? 1.0f : 1.0f / width;
    s_caretpixheight = height == 0.0f ? 1.0f : 1.0f / height;

    SStrCopy(s_fontName, "Fonts\\ARIALN.ttf", sizeof(s_fontName));
    s_textFont = TextBlockGenerateFont(s_fontName, 0, NDCToDDCHeight(s_fontHeight));

    ScrnLayerCreate(&s_rect, 6.0f, 0x1 | 0x2, nullptr, PaintBackground, &s_layerBackground);
    ScrnLayerCreate(&s_rect, 7.0f, 0x1 | 0x2, nullptr, PaintText, &s_layerText);

    RegisterHandlers();

    // TODO register commands

    // TODO EventSetConfirmCloseCallback(EventCloseCallback, 0);

    // TODO ConsoleCommandExecute("ver", 1);

    s_batch = GxuFontCreateBatch(false, false);
}
