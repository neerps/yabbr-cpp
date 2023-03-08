/*
*/
#include "HittableList.h"

//
HittableList::HittableList() {};

//
HittableList::HittableList(std::shared_ptr<Hittable> object)
{
  add(object);
}

//
void HittableList::clear()
{
  m_objects.clear();
}

//
void HittableList::add(std::shared_ptr<Hittable> object)
{
  m_objects.push_back(object);
}

//
HitResult HittableList::hit(const Ray& r, double tMin, double tMax) const
{
  HitResult tempRes{};
  HitRecord resRec{};
  bool hitAnything{false};
  auto closestSoFar{tMax};

  for (const auto& object : m_objects)
  {
    tempRes = object->hit(r, tMin, closestSoFar);
    if (tempRes.isHit)
    {
      hitAnything = true;
      closestSoFar = tempRes.rec.t;
      resRec = tempRes.rec;
    }
  }
  return {hitAnything, resRec};
}
