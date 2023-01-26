#include "Poly.h"
#include "VMath.h"

Poly::Poly(Vector p1, Vector p2, Vector, Vector p3)
	:base(Plane::getPlaneFromPoints(p1,p2,p3)), 
	side1(Plane::getPlaneFromPoints(p2, p3, Vector())), 
	side2(Plane::getPlaneFromPoints(p1, p3, Vector())), 
	side3(Plane::getPlaneFromPoints(p1, p2, Vector()))
{
	if (VMath::dot_product(side1.get_normal(), p1) > side1.get_distance()) side1_rpos = 1;
	else side1_rpos = -1;
	if (VMath::dot_product(side2.get_normal(), p2) > side2.get_distance()) side2_rpos = 1;
	else side2_rpos = -1;
	if (VMath::dot_product(side3.get_normal(), p3) > side3.get_distance()) side3_rpos = 1;
	else side3_rpos = -1;
}

Poly::~Poly()
{
}

bool Poly::intersects(Line l, Vector* location, float* length)
{

	if (base.intersects(l, location, length)) {
		if ((VMath::dot_product(*location, side1.get_normal()) - side1.get_distance()) * side1_rpos >= 0 &&
			(VMath::dot_product(*location, side2.get_normal()) - side2.get_distance()) * side2_rpos >= 0 &&
			(VMath::dot_product(*location, side3.get_normal()) - side3.get_distance()) * side3_rpos >= 0) {
			return true;
		}
	}
	return false;
}

Line Poly::reflection(Line l)
{
	return Line();
}
