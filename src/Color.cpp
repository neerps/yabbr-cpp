/*
*/

#include "Color.h"
#include "Hittable.h"
#include "HittableList.h"
#include "Lambertian.h"
#include "Material.h"
#include "Metal.h"
#include "RandomGen.h"
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
void writeColor(std::ostream& out, const Color& pixelColor, int samplesPerPixel)
{
  auto r{pixelColor.x()};
  auto g{pixelColor.y()};
  auto b{pixelColor.z()};

  auto scale{1.0 / samplesPerPixel};
  r = std::sqrt(scale * r);
  g = std::sqrt(scale * g);
  b = std::sqrt(scale * b);

  out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
    << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
    << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

//
Color backgroundRayColor(const Ray& r)
{
  Vec3 unitDirection{unitVector(r.direction())};
  auto t{0.5 * (unitDirection.y() + 1.0)};
  return (1.0 - t) * Color{1.0, 1.0, 1.0} + t * Color{0.5, 0.7, 1.0};
}

//
Color rayColor(const Ray& r, const Hittable& world, int depth)
{
  if (depth <= 0)
    return Color{0, 0, 0};

  HitResult resRec{world.hit(r, 0.001, infinity)};
  if (!resRec.isHit)
    return backgroundRayColor(r);
  else
  {
    ScatterResult scatterRes{resRec.rec.matPtr->scatter(r, resRec.rec)};
    if (!scatterRes.isScattered)
      return Color{0, 0, 0};
    else
    {
      return scatterRes.attentuation * rayColor(scatterRes.scattered, world, depth - 1);
    }
  }
}
