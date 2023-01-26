#include "VMath.h"
#include "math.h"

Vector VMath::add(Vector vec1, Vector vec2)
{
    return Vector((vec1.x + vec2.x), (vec1.y + vec2.y), (vec1.z + vec2.z));
}

Vector VMath::subtract(Vector vec1, Vector vec2)
{
    return Vector((vec1.x - vec2.x), (vec1.y - vec2.y), (vec1.z - vec2.z));
}

Vector VMath::get_unit_vector(Vector vec)
{
    float mag = get_magnitude(vec);
    return Vector( vec.x/mag, vec.y/mag, vec.z/mag );
}

float VMath::get_magnitude(Vector vec)
{
    return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}

Vector VMath::multiply(float scalar, Vector vec)
{
    return Vector(vec.x * scalar, vec.y * scalar, vec.z * scalar);
}

Vector VMath::multiply(Vector vec1, Vector vec2)
{
    //not implemented
    return Vector();
}

float VMath::dot_product(Vector vec1, Vector vec2)
{
    return float(vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

float VMath::get_cos_angle(Vector line1, Vector line2)
{
    return acos(abs(dot_product(line1,line2)/get_magnitude(line1)*get_magnitude(line2)));
}

