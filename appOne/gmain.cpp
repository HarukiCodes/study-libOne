#include "color_def.h"
#include "libOne.h"

void roundFace(float px, float py)
{
    // face
    fill(YELLOW);
    circle(px, py, 300);
    // eyes
    fill(WHITE);
    circle(px - 50, py, 80);
    circle(px + 50, py, 80);
    fill(BLACK);
    circle(px - 50, py, 30);
    circle(px + 50, py, 30);
    // mouth
    fill(255, 200, 200);
    circle(px, py + 80, 80);
}

void squareFace(float px, float py, float angle)
{
    rectMode(CENTER);
    // face
    fill(YELLOW);
    rect(px, py, 300, 300, angle);
    // eyes
    fill(WHITE);
    rect(px - 50, py, 80, 80, angle);
    rect(px + 50, py, 80, 80, angle);
    fill(BLACK);
    rect(px - 50, py, 30, 30, angle);
    rect(px + 50, py, 30, 30, angle);
    // mouth
    fill(255, 200, 200);
    rect(px, py + 80, 80, 80, angle);
}

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