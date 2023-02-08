/*
*/

#include "Color.h"
#include "Ray.h"
#include "Vec3.h"

#include <iostream>

//
double hitSphere(const Point3& center, double radius, const Ray& r)
{
  Vec3 oc{r.origin() - center};
  auto a{dot(r.direction(), r.direction())};
  auto b{2.0 * dot(oc, r.direction())};
  auto c{dot(oc, oc) - radius * radius};
  auto discriminant{b * b - 4 * a * c};
  if (discriminant < 0)
  {
    return -1.0;
  }
  else
  {
    return (-b - std::sqrt(discriminant)) / (2.0 * a);
  }
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
  auto t{hitSphere(Point3{0, 0, -1}, 0.5, r)};
  if (t > 0.0)
  {
    Vec3 N{unitVector(r.at(t) - Vec3{0, 0, -1})};
    return 0.5 * Color{N.x() + 1, N.y() + 1, N.z() + 1};
  }
  Vec3 unitDirection{unitVector(r.direction())};
  t = 0.5 * (unitDirection.y() + 1.0);
  return (1.0 - t) * Color { 1.0, 1.0, 1.0 } + t * Color{0.5, 0.7, 1.0};
}
