#include "star.h"
#include "raylib.h"


float pulsationRange = 1.3f; 
float pulsationSpeed = 0.001f;



void updateStar(Star *star) {
     if (star->pulse.growing && star->pulse.diameter < star->diameter*3.0f) {
        star->pulse.diameter += star->pulse.pulseSpeed;
        if (star->pulse.diameter >= star->diameter*pulsationRange) {
            star->pulse.growing = 0;
        }
    } else {
        star->pulse.diameter -= star->pulse.pulseSpeed;
        if (star->pulse.diameter <= star->diameter) {
            star->pulse.growing = 1;
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
    star.pulse.x = x;
    star.pulse.y = y;
    star.pulse.diameter = diameter; // Example pulse diameter
    star.pulse.pulseSpeed = diameter * pulsationSpeed; // Example pulse speed based on diameter
    star.pulse.growing = 1;
    return star;
}