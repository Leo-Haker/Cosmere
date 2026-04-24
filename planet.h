#ifdef PLANET_H
#ifndef PLANET_H
#define PLANET_H

typedef struct orbit{
    float radius; 
    float speed; 
    float angle; 
} Orbit;

typedef struct solarSystem {
    char* name; 
    Planet* planets; 
    int numPlanets; 
} SolarSystem;
 
typedef struct planet {
    float x, y; 
    float diameter; 
    Color color; 
    char* name; 
    float orbit; 
    SolarSystem* solarSystem;
} Planet;

Planet createPlanet(float x, float y, float diameter, Color color, char* name, float orbit, SolarSystem* solarSystem);

#endif