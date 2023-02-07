/*
*/

#include "Color.h"
#include "Ray.h"
#include "Vec3.h"

#include <iostream>

//
void writeColor(std::ostream& out, const Color& pixelColor)
{
  out << static_cast<int>(255.999 * pixelColor.x()) << ' '
    << static_cast<int>(255.999 * pixelColor.y()) << ' '
    << static_cast<int>(255.999 * pixelColor.z()) << '\n';
}

//
Color rayColor(const Ray& r)
{
  Vec3 unitDirection{unitVector(r.direction())};
  auto t{0.5 * (unitDirection.y() + 1.0)};
  return (1.0 - t) * Color{1.0, 1.0, 1.0} + t * Color{0.5, 0.7, 1.0};
}
