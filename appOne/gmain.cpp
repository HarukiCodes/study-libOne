#include "libOne.h"
#include "face.h"

void gmain()
{
    const float wnd_w = 1920, wnd_h = 1080;
    window(wnd_w, wnd_h, full);
    float px = width / 2;
    float py = height / 2;
    float angle = 0;
    float offset_x = 60;
    float offset_y = 60;
    float sw = 10;
    int faceType = 1;
    strokeWeight(sw);
    while (notQuit)
    {
        offset_x = width / 2 - mouseX;
        offset_y = height / 2 - mouseY;
        if (isTrigger(KEY_SPACE))
        {
            faceType = 1 - faceType;
        }
        angle += 0.01f;
        clear(60, 120, 240);
        for (int i = -5; i <= 5; i++)
        {
            if (faceType == 1)
            {
                roundFace(px + offset_x * i, py + offset_y * i);
            }
            else
            {
                squareFace(px + offset_x * i, py + offset_y * i, angle);
            }
        }
    }
}