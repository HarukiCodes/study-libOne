#include "libOne.h"

#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255
#define CYAN 0, 255, 255
#define MAGENTA 255, 0, 255
#define YELLOW 255, 255, 0

void gmain()
{
    const float wnd_w = 600;
    const float wnd_h = 600;
    window(wnd_w, wnd_h);
    clear(200);

    strokeWeight(20);
    stroke(128);
    fill(YELLOW);

    // 左上の位置を指定するMode
    // rectMode(RECT_MODE::CORNER);
    // rectの中心の位置を指定するMode
    rectMode(RECT_MODE::CENTER);

    // 角度形式を指定
    angleMode(ANGLE_MODE::DEGREES);
    float px = 300, py = 300, w = 200, h = 300, angle = 45;
    rect(px, py, w, h, angle);

    pause();
}