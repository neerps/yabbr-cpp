/*
*/
#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

//
#include "Hittable.h"

#include <memory>
#include <vector>

//
class HittableList : public Hittable
{
public:
  std::vector<std::shared_ptr<Hittable>> m_objects{};

public:
  HittableList();
  HittableList(std::shared_ptr<Hittable> object);

  void clear();
  void add(std::shared_ptr<Hittable> object);

  virtual bool hit(const Ray& r, double tMin, double tMax, HitRecord& rec) const override;
};

#endif
