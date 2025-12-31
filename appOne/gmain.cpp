#include "color_def.h"
#include "libOne.h"

void gmain()
{
    const float wnd_w = 1280, wnd_h = 720;
    window(wnd_w, wnd_h, full);
    float px = wnd_w / 2;
    float py = wnd_h / 2;
    float vx = 5;
    float radius = 100;
    float rect_len = radius * Sqrt(2);
    float sw = radius / 8;  // strokeWeight
    float angle = 0;
    float angle_speed = 0.03f;

    rectMode(CENTER);
    stroke(RED);

    while (notQuit)
    {
        px += vx;
        angle += angle_speed;
        if (px < 0 || px > wnd_w)
        {
            vx = -vx;
            angle_speed = -angle_speed;
        }
        clear(GRAY);
        strokeWeight(sw);
        circle(px, py, radius * 2);
        rect(px, py, rect_len, rect_len, angle);
        line(wnd_w / 2, 0, px, py);
        strokeWeight(sw * 3);
        point(px, py);
    }
}