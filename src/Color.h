#ifndef COLOR_H
#define COLOR_H

#include "HittableList.h"
#include "RandomGen.h"
#include "Rtweekend.h"

#include <iostream>

//
void writeColor(std::ostream& out, const Color& pixelColor, int samplesPerPixel);

//
Color rayColor(const Ray& r, const Hittable& world, int depth);

#endif
