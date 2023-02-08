/*
*/

#include "Color.h"
#include "HittableList.h"
#include "Rtweekend.h"
#include "Sphere.h"

#include <iostream>

//
double hitSphere(const Point3& center, double radius, const Ray& r)
{
  Vec3 oc{r.origin() - center};
  auto a{r.direction().lengthSquared()};
  auto halfB{dot(oc, r.direction())};
  auto c{oc.lengthSquared() - radius * radius};
  auto discriminant{halfB * halfB - a * c};

  if (discriminant < 0)
  {
    return -1.0;
  }
  else
  {
    return (-halfB - std::sqrt(discriminant)) / a;
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
Color rayColor(const Ray& r, const Hittable& world)
{
  HitRecord rec;
  if (world.hit(r, 0, infinity, rec))
  {
    return 0.5 * (rec.normal + Color{1, 1, 1});
  }
  Vec3 unitDirection{unitVector(r.direction())};
  auto t{0.5 * (unitDirection.y() + 1.0)};
  return (1.0 - t) * Color { 1.0, 1.0, 1.0 } + t * Color{0.5, 0.7, 1.0};
}
