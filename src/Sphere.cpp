/*
*/
#include "Sphere.h"
#include "Vec3.h"

//
Sphere::Sphere() {};

//
Sphere::Sphere(Point3 cen, double r)
  : m_center{cen}, m_radius{r}
{};

//
bool Sphere::hit(const Ray& r, double tMin, double tMax, HitRecord& rec) const
{
  Vec3 oc{r.origin() - m_center};
  auto a{r.direction().lengthSquared()};
  auto halfB{dot(oc, r.direction())};
  auto c{oc.lengthSquared() - m_radius * m_radius};

  auto discriminant{halfB * halfB - a * c};
  if (discriminant < 0)
    return false;
  auto sqrtd{std::sqrt(discriminant)};

  // nearest root in acceptable range
  auto root{(-halfB - sqrtd) / a};
  if (root < tMin || tMax < root)
  {
    root = (-halfB + sqrtd) / a;
    if (root < tMin || tMax < root)
      return false;
  }

  rec.t = root;
  rec.p = r.at(rec.t);
  Vec3 outwardNormal{(rec.p - m_center) / m_radius};

  return true;
}
