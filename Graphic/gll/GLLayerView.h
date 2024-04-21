#pragma once


class GLWindow;

class GLLayerView {
public:
    CGDirectDisplayID m_display;
    GLWindow *m_GLWindow;
    NSOpenGLContext *m_savedContext;
    NSCursor *m_cursor;
public:
    bool acceptsFirstResponder();

    void drawRect(NSRect dirtyRect);

    int initWithFrame(NSRect frame, GLWindow window);

    void keyDown(NSEvent *event);

    void keyUp(NSEvent *event);

    void mouseDown(NSEvent *event);

    void mouseDragged(NSEvent *event);

    void mouseMoved(NSEvent *event);

    void mouseUp(NSEvent *event);

    void otherMouseDown(NSEvent *event);

    void otherMouseDragged(NSEvent *event);

    void otherMouseUp(NSEvent *event);

    void rightMouseDown(NSEvent *event);

    void rightMouseDragged(NSEvent *event);

    void rightMouseUp(NSEvent *event);

    void scrollWheel(NSEvent *event);

    void viewDidChangeBackingProperties();

    void viewDidEndLiveResize();

    void update();
};







