#pragma once
#include "Surface.h"
#include "Plane.h"

class Poly :
    public Surface
{
public:

    Poly(Vector p1, Vector p2, Vector, Vector p3);
    ~Poly();

    bool intersects(Line l, Vector* location, float* length);
    Line reflection(Line l);

private:
    Plane base, side1, side2, side3;
    //represents if poly area is "above" or "below" the plane
    int side1_rpos, side2_rpos, side3_rpos;
};

