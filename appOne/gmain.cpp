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
    strokeWeight(30);  // ïMà≥
    stroke(RED);       // êF
    point(400, wnd_h / 2);
    stroke(YELLOW);
    point(560, wnd_h / 2);
    stroke(BLUE);
    point(720, wnd_h / 2);
    pause();
}