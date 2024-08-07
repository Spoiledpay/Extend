#include "graphic.h"
#include <stdlib.h>

#define MAX_SHAPES 100

static HWND hwnd = NULL;
static COLORREF current_color = RGB(0, 0, 0); // Cor preta como padrão
static COLORREF bgColor = RGB(255, 255, 255); // Cor de fundo padrão

typedef struct {
    int x1, y1, x2, y2;
    COLORREF color;
} Line;

typedef struct {
    int x, y, radius;
    COLORREF color;
} Circle;

static Line lines[MAX_SHAPES];
static int line_count = 0;

static Circle circles[MAX_SHAPES];
static int circle_count = 0;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, CreateSolidBrush(bgColor));

            // Desenhar linhas
            for (int i = 0; i < line_count; i++) {
                HPEN hPen = CreatePen(PS_SOLID, 1, lines[i].color);
                HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
                MoveToEx(hdc, lines[i].x1, lines[i].y1, NULL);
                LineTo(hdc, lines[i].x2, lines[i].y2);
                SelectObject(hdc, hOldPen);
                DeleteObject(hPen);
            }

            // Desenhar círculos
            for (int i = 0; i < circle_count; i++) {
                HPEN hPen = CreatePen(PS_SOLID, 1, circles[i].color);
                HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
                HBRUSH hBrush = CreateSolidBrush(circles[i].color);
                HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
                Ellipse(hdc, circles[i].x - circles[i].radius, circles[i].y - circles[i].radius, 
                        circles[i].x + circles[i].radius, circles[i].y + circles[i].radius);
                SelectObject(hdc, hOldPen);
                SelectObject(hdc, hOldBrush);
                DeleteObject(hPen);
                DeleteObject(hBrush);
            }

            EndPaint(hwnd, &ps);
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void update_graphics() {
    InvalidateRect(hwnd, NULL, TRUE);
    UpdateWindow(hwnd);
}

void process_messages() {
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void gwindows(int width, int height, COLORREF color) {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASS wc = { 0 };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "GraphicWindowClass";

    RegisterClass(&wc);

    hwnd = CreateWindowEx(
        0,
        wc.lpszClassName,
        "Graphic Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return;
    }

    bgColor = color;
    ShowWindow(hwnd, SW_SHOW);
}

void setcolor(COLORREF color) {
    current_color = color;
}

void line(int x1, int y1, int x2, int y2) {
    if (line_count < MAX_SHAPES) {
        lines[line_count].x1 = x1;
        lines[line_count].y1 = y1;
        lines[line_count].x2 = x2;
        lines[line_count].color = current_color;
        line_count++;
    }
    update_graphics(); // Solicitar redesenho
}

void circle(int x, int y, int radius) {
    if (circle_count < MAX_SHAPES) {
        circles[circle_count].x = x;
        circles[circle_count].y = y;
        circles[circle_count].radius = radius;
        circles[circle_count].color = current_color;
        circle_count++;
    }
    update_graphics(); // Solicitar redesenho
}

void closegraph() {
    if (hwnd != NULL) {
        SendMessage(hwnd, WM_CLOSE, 0, 0);
        hwnd = NULL;
    }
}
