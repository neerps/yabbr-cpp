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
bool HittableList::hit(const Ray& r, double tMin, double tMax, HitRecord& rec) const
{
  HitRecord tempRec;
  bool hitAnything{false};
  auto closestSoFar{tMax};

  for (const auto& object : m_objects)
  {
    if (object->hit(r, tMin, closestSoFar, tempRec))
    {
      hitAnything = true;
      closestSoFar = tempRec.t;
      rec = tempRec;
    }
  }
  return hitAnything;
}
