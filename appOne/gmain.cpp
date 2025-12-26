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

    // window‚ğì¬‚µ‚Ä‚©‚çclear()‚ğŒÄ‚Ô
    clear(YELLOW);

    pause();
}