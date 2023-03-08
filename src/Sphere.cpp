/*
*/
#include "Hittable.h"
#include "Material.h"
#include "Sphere.h"
#include "Vec3.h"

//
Sphere::Sphere() {};

//
Sphere::Sphere(Point3 cen, double r, std::shared_ptr<Material> m)
  : m_center{cen}, m_radius{r}, m_matPtr{m}
{};

//
HitResult Sphere::hit(const Ray& r, double tMin, double tMax) const
{
  HitResult resRec{};
  Vec3 oc{r.origin() - m_center};
  auto a{r.direction().lengthSquared()};
  auto halfB{dot(oc, r.direction())};
  auto c{oc.lengthSquared() - m_radius * m_radius};

  auto discriminant{halfB * halfB - a * c};
  if (discriminant < 0)
  {
    resRec.isHit = false;
    return resRec;
  }
  auto sqrtd{std::sqrt(discriminant)};

  // nearest root in acceptable range
  auto root{(-halfB - sqrtd) / a};
  if (root < tMin || tMax < root)
  {
    root = (-halfB + sqrtd) / a;
    if (root < tMin || tMax < root)
    {
      resRec.isHit = false;
      return resRec;
    }
  }

  resRec.isHit = true;
  resRec.rec.t = root;
  resRec.rec.p = r.at(resRec.rec.t);
  Vec3 outwardNormal{(resRec.rec.p - m_center) / m_radius};
  resRec.rec.setFaceNormal(r, outwardNormal);
  resRec.rec.matPtr = m_matPtr;

  return resRec;
}
