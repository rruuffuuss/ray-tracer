#pragma once
#include "Line.h"
class Plane
{
public:

    Plane(Vector normal, float distance);
    ~Plane();

    static Plane getPlaneFromPoints(Vector p1, Vector p2, Vector p3);

    bool intersects(Line line, Vector* location, float* length);
    Line reflection(Line l, Vector intersection);

    Vector get_normal();
    float get_distance();

private:
    Vector normal;
    float distance; 
};

