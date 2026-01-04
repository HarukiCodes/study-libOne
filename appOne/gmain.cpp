#include "libOne.h"

void gmain()
{
    const float wnd_w = 1920, wnd_h = 1080;
    window(wnd_w, wnd_h, full);
    struct Player
    {
        float px, py, w, h, vx, offset_y;
    };
    struct Bullet
    {
        float px, py, w, h, vy;
        int hp;
    };
    Player p;
    p.px = width / 2;
    p.py = height - 150;
    p.w = 100;
    p.h = 200;
    p.vx = 10;
    p.offset_y = -100;
    const int num_bullets = 10;
    Bullet b[num_bullets];
    for (int i = 0; i < num_bullets; i++)
    {
        b[i].px = p.px;
        b[i].py = p.py;
        b[i].w = 20;
        b[i].h = 40;
        b[i].vy = -10;
        b[i].hp = 0;
    }

    while (notQuit)
    {
        if (isPress(KEY_A))
        {
            p.px += -p.vx;
        }
        if (isPress(KEY_D))
        {
            p.px += p.vx;
        }
        if (isTrigger(KEY_SPACE))
        {
            for (int i = 0; i < num_bullets; i++)
            {
                if (b[i].hp == 0)
                {
                    b[i].hp = 1;
                    b[i].px = p.px;
                    b[i].py = p.py + p.offset_y;
                    break;
                }
            }
        }
        for (int i = 0; i < num_bullets; i++)
        {
            if (b[i].hp > 0)
            {
                b[i].py += b[i].vy;
                // Out of window
                if (b[i].py < -b[i].h)
                {
                    b[i].hp = 0;
                }
            }
        }
        clear();
        rectMode(CENTER);
        rect(p.px, p.py, p.w, p.h);
        for (int i = 0; i < num_bullets; i++)
        {
            if (b[i].hp > 0)
            {
                rect(b[i].px, b[i].py, b[i].w, b[i].h);
            }
        }
    }
}