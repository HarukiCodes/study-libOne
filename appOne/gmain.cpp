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
    stroke(GREEN);  // Frame color
    fill(RED);      // Inner color
    float px = 300, py = 300, radius = 200;
    circle(px, py, radius * 2);
    pause();
}