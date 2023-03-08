/*
*/
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

//
#include "Material.h"
#include "Rtweekend.h"

//
struct HitRecord;

//
class Lambertian : public Material
{
public:
  Color m_albedo{};

public:
  Lambertian(const Color& a);

  virtual ScatterResult scatter(
    const Ray& rIn, const HitRecord& rec
  ) const override;

};

#endif
