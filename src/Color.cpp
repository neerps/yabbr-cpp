/*
*/

#include "Color.h"
#include "Ray.h"
#include "Vec3.h"

#include <iostream>

//
bool hitSphere(const Point3& center, double radius, const Ray& r)
{
  Vec3 oc{r.origin() - center};
  auto a{dot(r.direction(), r.direction())};
  auto b{2.0 * dot(oc, r.direction())};
  auto c{dot(oc, oc) - radius * radius};
  auto discriminant{b * b - 4 * a * c};

  return (discriminant > 0);
}

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
  if (hitSphere(Point3{0, 0, -1}, 0.5, r))
    return Color{1, 0, 0};
  Vec3 unitDirection{unitVector(r.direction())};
  auto t{0.5 * (unitDirection.y() + 1.0)};
  return (1.0 - t) * Color{1.0, 1.0, 1.0} + t * Color{0.5, 0.7, 1.0};
}
