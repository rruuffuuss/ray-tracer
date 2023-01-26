#pragma once
#include "Vector.h"

class Line
{
public:
	Vector start, direction;
	 
	Line(Vector start, Vector direction);
	~Line();

	static Line getLineFromPoints(Vector start, Vector end);

	void reflect(Vector normal);
};

