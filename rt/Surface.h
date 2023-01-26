#pragma once

#include "Colour.h"
#include "Line.h"

class Surface
{
public:
	bool intersects(Line l, Vector *location);
	Line reflection(Line l);
};

