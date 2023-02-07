#ifndef COLOR_H
#define COLOR_H

#include "Ray.h"
#include "Vec3.h"

#include <iostream>

//
bool hitSphere(const Point3& center, double radius, const Ray& r);

//
void writeColor(std::ostream& out, const Color& pixelColor);

//
Color rayColor(const Ray& r);

#endif
