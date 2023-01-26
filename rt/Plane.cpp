#include "Plane.h"
#include "VMath.h"


Plane::Plane(Vector normal, float distance)
	:normal(normal), distance(distance)
{
}

Plane::~Plane()
{
}

Plane Plane::getPlaneFromPoints(Vector p1, Vector p2, Vector p3)
{
	Vector lambda = VMath::subtract(p1, p2);
	Vector mu = VMath::subtract(p1, p3);
	//normal.lambda = 0
	//normal.mu = 0
	Vector normal = Vector(
		(mu.y * lambda.z - lambda.y * mu.z) / (lambda.y * mu.x - mu.y * lambda.x),
		(lambda.z * mu.x - mu.z * lambda.x) / (mu.y * lambda.x - mu.x * lambda.y),
		1);
	float distance = normal.x * p1.x + normal.y * p1.y + normal.z * p1.z;
	
	return Plane(normal, distance);
}

bool Plane::intersects(Line line, Vector* location, float* length)
{
	if (VMath::dot_product(line.direction, normal) == 0) {
		return false;
	}

	*length = (distance - normal.x * line.start.x - normal.y * line.start.y - normal.z * line.start.z) / (normal.x * line.direction.x + normal.y * line.direction.y + normal.z * line.direction.z);
	*location = VMath::add(line.start, VMath::multiply(*length, line.direction));
	return true;
}


Line Plane::reflection(Line l, Vector intersection)
{

	Vector p = VMath::add(intersection, l.direction);
	Vector p_shadow;
	float d;
	intersects(Line(p, normal), &p_shadow, &d);
	Vector p_image = VMath::subtract(p_shadow, VMath::multiply(d, normal));

	return Line(intersection,VMath::subtract(p_image, intersection));
}

Vector Plane::get_normal()
{
	return normal;
}

float Plane::get_distance()
{
	return distance;
}

