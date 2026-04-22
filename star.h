#ifndef STAR_H
#define STAR_H

typedef struct pulseStar {
    float x, y; // position
    float diameter; // size of the star
    float pulseSpeed; // speed at which the star pulses 
    int growing; // flag to indicate if the star is currently growing or shrinking
} pulseStar;

typedef struct star {   
    float x, y; // position
    float diameter; // size of the star
    pulseStar pulse; // nested structure to hold pulse-related properties
} Star;

void updateStar(Star *star);
void setGrowingStatus(Star *star);
Star createStar(float x, float y, float diameter, float pulseSpeed);

#endif