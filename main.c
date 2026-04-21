#include "raylib.h"
#include "star.h"

// Uses raylib library to create a simple animation of pulsating stars on the screen. 




int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Pulsating Stars");

    const int numStars = 100;
    Star stars[numStars];

    for (int i = 0; i < numStars; i++) {
        stars[i].x = GetRandomValue(0, screenWidth);
        stars[i].y = GetRandomValue(0, screenHeight);
        stars[i].diameter = GetRandomValue(5, 20);
        stars[i].pulseSpeed = GetRandomValue(1, 3) * 0.1f;
        stars[i].growing = GetRandomValue(0, 1);
    }

    while (!WindowShouldClose()) {
        for (int i = 0; i < numStars; i++) {
            setGrowingStatus(&stars[i]);
            updateStar(&stars[i]);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < numStars; i++) {
            DrawCircle(stars[i].x, stars[i].y, stars[i].diameter / 2, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}