#include "raylib.h"
#include "star.h"

// Uses raylib library to create a simple animation of pulsating stars on the screen. 
// raylib Color c =  {r, g, b, a}; where a is the alpha (transparency) value, ranging from 0 (fully transparent) to 255 (fully opaque).
Color starColor = {255, 255, 255, 255}; // White color for stars
Color pulseColor = {255, 255, 255, 180}; // Semi-transparent gray for pulse effect



int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pulsating Stars");

   
    const int numStars = 100;
    Star stars[numStars];

    for (int i = 0; i < numStars; i++) {
        stars[i] = createStar(GetRandomValue(0, screenWidth), GetRandomValue(0, screenHeight), GetRandomValue(5, 20), 1);
    }

    while (!WindowShouldClose()) {
        for (int i = 0; i < numStars; i++) {
            updateStar(&stars[i]);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < numStars; i++) {
            DrawCircle(stars[i].pulse.x, stars[i].pulse.y, stars[i].pulse.diameter / 2, pulseColor);
            DrawCircle(stars[i].x, stars[i].y, stars[i].diameter / 2, starColor);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}