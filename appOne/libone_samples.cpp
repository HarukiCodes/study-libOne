#include "libOne.h"
#include "libone_samples.h"
#include "face.h"
#include "color_defines.h"

namespace libone_samples
{
    void _01_Intro()
    {
        const float wnd_w = 800;
        const float wnd_h = 600;
        window(wnd_w, wnd_h);

        const float cell_size = 50;
        for (int i = 0; i < wnd_w / cell_size; i++)
        {
            for (int j = 0; j < wnd_h / cell_size; j++)
            {
                if ((i + j) % 2 == 0)
                {
                    fill(0);
                }
                else
                {
                    fill(0, 100, 0);
                }
                rect(cell_size * i, cell_size * j, cell_size, cell_size);
            }
        }
        pause();
    }

    void _02_UseWindow_Clear()
    {
        const float wnd_w = 800;
        const float wnd_h = 600;
        window(wnd_w, wnd_h);
        clear(YELLOW);
        pause();
    }

    void _03_UsePoint()
    {
        const float wnd_w = 800;
        const float wnd_h = 600;
        window(wnd_w, wnd_h);
        clear(YELLOW);

        clear(200);
        strokeWeight(30);

        stroke(RED);
        point(400, wnd_h / 2);

        stroke(YELLOW);
        point(560, wnd_h / 2);

        stroke(BLUE);
        point(720, wnd_h / 2);
        pause();
    }

    void _04_UseLine()
    {
        const float wnd_w = 800;
        const float wnd_h = 600;
        window(wnd_w, wnd_h);
        clear(200);
        strokeWeight(10);
        stroke(GREEN);

        // ˆÊ’u‚ð•Ï”‚Å’u‚¢‚Ä‚í‚©‚è‚â‚·‚­‚·‚é
        float sx = 100, sy = 400, ex = 700, ey = 400;
        line(sx, sy, ex, ey);
        line(wnd_w / 2, 100, wnd_w / 2, 500);
        pause();
    }

    void _05_UseCircle()
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

    void _06_UseRect()
    {
        const float wnd_w = 600;
        const float wnd_h = 600;
        window(wnd_w, wnd_h);
        clear(200);

        strokeWeight(20);
        stroke(128);
        fill(YELLOW);

        // rectMode(RECT_MODE::CORNER);
        rectMode(RECT_MODE::CENTER);

        angleMode(ANGLE_MODE::DEGREES);
        float px = 300, py = 300, w = 200, h = 300, angle = 45;
        rect(px, py, w, h, angle);

        pause();
    }

    void _07_DrawWheel()
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
            clear(BGCOLOR);
            strokeWeight(sw);
            circle(px, py, radius * 2);
            rect(px, py, rect_len, rect_len, angle);
            line(wnd_w / 2, 0, px, py);
            strokeWeight(sw * 3);
            point(px, py);
        }
    }

    void _08_DrawLifeCircle()
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

    void _09_DrawHPGauge()
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

    void _10to12_DrawSquareOrRoundFaces()
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
}  // namespace libone_sample