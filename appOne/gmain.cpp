#include "libOne.h"

void gmain()
{
    const float wnd_w = 800;
    const float wnd_h = 600;
    const float cell_size = 50;

    window(wnd_w, wnd_h);

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