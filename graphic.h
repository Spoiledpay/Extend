#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <windows.h>

void gwindows(int width, int height, COLORREF color);
void setcolor(COLORREF color);
void line(int x1, int y1, int x2, int y2);
void circle(int x, int y, int radius);
void closegraph();
void process_messages();

#endif // GRAPHIC_H
