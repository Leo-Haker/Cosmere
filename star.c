void updateStar(Star *star) {
     if (star->growing) {
        star->diameter += star->pulseSpeed;
        if (star->diameter >= 50) {
            star->diameter -= star->pulseSpeed;
            star->growing = 0;
        }
    } else {
        if (star->diameter <= 5) {
                star->growing = 1; 
            }
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
    star.pulse.x = x;
    star.pulse.y = y;
    star.pulse.diameter = diameter + 10; // Example pulse diameter
    star.pulse.pulseSpeed = pulseSpeed;
    star.pulse.growing = 1;
    return star;
}