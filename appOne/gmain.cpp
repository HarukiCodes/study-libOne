#include "color_def.h"
#include "libOne.h"

void gmain()
{
    const float wnd_w = 1280, wnd_h = 720;
    window(wnd_w, wnd_h, full);

    // Data
    COLOR green = {0, 255, 0};
    COLOR yellow = {255, 255, 0};
    COLOR red = {255, 0, 0};
    COLOR color = green;
    int hp_max = 500;
    int hp = hp_max;
    int hp_warning = hp_max * 0.3f;
    int hp_danger = hp_max * 0.1f;
    float px = 400;
    float py = 140;
    float h = 60;  // height
    float ts = 100;

    while (notQuit)
    {
        if (isTrigger(KEY_SPACE))
        {
            hp = hp_max;
        }
        if (hp > 0)
        {
            hp -= 2;
        }
        if (hp > hp_warning)
        {
            color = green;
        }
        else if (hp > hp_danger)
        {
            color = yellow;
        }
        else
        {
            color = red;
        }
        clear(BGCOLOR);
        fill(128);
        rect(px, py, hp_max, h);
        fill(color);
        rect(px, py, hp, h);
        if (hp <= 0)
        {
            textSize(ts);
            fill(RED);
            text("Game Over", px, wnd_h / 2);
        }
    }
}