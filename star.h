#ifndef STAR_H
#define STAR_H
void updateStar(Star *star);
void setGrowingStatus(Star *star);

typedef struct star {   
    float x, y; // position
    float diameter; // size of the star
    pulseStar pulse; // nested structure to hold pulse-related properties
} Star;

typedef struct pulseStar {
    float x, y; // position
    float diameter; // size of the star
    float pulseSpeed; // speed at which the star pulses 
    int growing; // flag to indicate if the star is currently growing or shrinking
} pulseStar;
#endif 