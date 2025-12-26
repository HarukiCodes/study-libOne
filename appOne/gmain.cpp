#include "libOne.h"

#define RED 255, 0, 0
#define GREEN 0, 255, 0
#define BLUE 0, 0, 255
#define CYAN 0, 255, 255
#define MAGENTA 255, 0, 255
#define YELLOW 255, 255, 0

void gmain()
{
    const float wnd_w = 800;
    const float wnd_h = 600;
    window(wnd_w, wnd_h);
    clear(200);
    strokeWeight(10);
    stroke(GREEN);
    // ˆÊ’u‚ğ•Ï”‚Å’u‚¢‚Ä‚í‚©‚è‚â‚·‚­‚·‚é
    float sx = 100, sy = 400, ex = 700, ey = 400;
    line(sx, sy, ex, ey);
    line(wnd_w / 2, 100, wnd_w / 2, 500);
    pause();
}