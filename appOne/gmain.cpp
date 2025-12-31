#include "color_def.h"
#include "libOne.h"

#define BGCOLOR 74, 84, 89

void gmain()
{
    const float wnd_w = 1280, wnd_h = 720;
    window(wnd_w, wnd_h, full);

    // Data
    int life = 5;
    float px = 500;
    float py = 140;
    float radius = 50;
    float space = 100;
    float sw = 20;
    while (notQuit)
    {
        // Update data
        if (isTrigger(KEY_A))
        {
            life--;
        }
        if (isTrigger(KEY_D))
        {
            life++;
        }
        // Drawing
        clear(BGCOLOR);
        fill(YELLOW);
        print((let) "life=" + life);
        strokeWeight(sw);
        stroke(WHITE);

        // while-version
        int i = 0;
        fill(255, 200, 200);
        while (i < life)
        {
            // offset: Šî€‚©‚ç‚Ì‚¸‚ê
            float offset_x = space * i;
            circle(px + offset_x, py, radius * 2);
            i++;
        }

        // for-version
        fill(160, 200, 240);
        for (int i = 0; i < life; i++)
        {
            float offset_x = space * i;
            float offset_y = space * 2;
            circle(px + offset_x, py + offset_y, radius * 2);
        }
    }
}