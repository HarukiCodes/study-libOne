#include "libOne.h"
#include "color_def.h"

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
