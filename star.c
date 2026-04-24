#include "star.h"
#include "raylib.h"


float pulsationRange = 1.3f; 
float pulsationSpeed = 0.2f;



void updateStar(Star *star) {
    star->accumulator += star->pulseSpeed;
     if (star->growing && star->color.a < 255 && star->accumulator >= 1.0f) {
            star->color.a += 1;
            star->accumulator = 0; // Reset accumulator
        if (star->color.a >= 255) {
            star->growing = 0;
        }
    } else {
        if(star->accumulator >= 1.0f) {
            star->color.a -= 1;
            star->accumulator = 0; // Reset accumulator
        }
        if (star->color.a  <= 180) {
            star->growing = 1;
        }
    }
}




void setGrowingStatus(Star *star) {
    star->growing = GetRandomValue(0, 1);
}

Star createStar(float x, float y, float diameter, float pulseSpeed) {
    Star star;
    star.x = x;
    star.y = y;
    star.diameter = diameter;
    star.pulseSpeed = pulsationSpeed; // Example pulse speed based on diameter
    star.color = (Color){255, 255, 255, 180};
    star.accumulator = 0;
    return star;
}