#include "Line.h"
#include "VMath.h"

Line::Line(Vector start, Vector direction)
	:start(start), direction(VMath::get_unit_vector(direction))
{
}

Line::~Line()
{
}

Line Line::getLineFromPoints(Vector start, Vector end)
{
	Vector direction = VMath::subtract(end, start);
	return Line(start, end);
}

void Line::reflect(Vector normal)
{
}
