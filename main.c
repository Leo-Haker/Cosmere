#include "raylib.h"


typedef struct star {   
    float x, y; // position
    float diameter; // size of the star
    float pulseSpeed; // speed at which the star pulses
    int growing; // flag to indicate if the star is currently growing or shrinking
} Star;

void updateStar(Star *star) {
     if (star->growing) {
        star->diameter += star->pulseSpeed;
        if (star->diameter >= 50) {
            star->diameter -= star->pulseSpeed;
            if (star->diameter <= 5) {
                star->growing = 1; 
            }
        }
    }
}

void setGrowingStatus(Star *star) {
    star->growing = GetRandomValue(0, 1);
}


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