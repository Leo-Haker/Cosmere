#include "star.h"
#include "raylib.h"


float pulsationRange = 1.3f; 
float pulsationSpeed = 0.01f;



void updateStar(Star *star, int i) {
     if (star->pulse.growing && star->color <= {255, 255, 255, 255}) {
            star->color.a += 10;
        if (star->color.a >= 255) {
            star->growing = 0;
        }
    } else {
        star->color.a -= 10;
        if (star->color.a <= 180) {
            star->growing = 1;
        }
    }
}




void setGrowingStatus(Star *star) {
    star->pulse.growing = GetRandomValue(0, 1);
}

Star createStar(float x, float y, float diameter, float pulseSpeed) {
    Star star;
    star.x = x;
    star.y = y;
    star.diameter = diameter;
    star.growing;
    star.pulseSpeed = pulsationSpeed; // Example pulse speed based on diameter
    star.color = {255, 255, 255, 180};
    return star;
}