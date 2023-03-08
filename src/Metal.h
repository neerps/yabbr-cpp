/*
*/
#ifndef METAL_H
#define METAL_H

#include "Material.h"
#include "Rtweekend.h"

//
struct HitRecord;

//
class Metal : public Material
{
public:
  Color m_albedo{};

public:
  Metal(const Color& a);

  virtual ScatterResult scatter(
    const Ray& rIn, const HitRecord& rec
  ) const override;
};

#endif
