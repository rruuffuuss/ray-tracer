#pragma once

#include "Vector.h"

static class VMath
{
public:
	static Vector add(Vector vec1, Vector vec2);
	static Vector subtract(Vector vec1, Vector vec2);
	static Vector get_unit_vector(Vector vec);
	static float get_magnitude(Vector vec);
	static Vector multiply(float scalar, Vector vec);
	static Vector multiply(Vector vec1, Vector vec2);
	static float dot_product(Vector vec1, Vector vec2);
	static float get_cos_angle(Vector line1, Vector line2);
};

