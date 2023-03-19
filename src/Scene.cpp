/*
*/
#include "Dielectric.h"
#include "HittableList.h"
#include "Lambertian.h"
#include "Material.h"
#include "Metal.h"
#include "Sphere.h"
#include "Rtweekend.h"

//
HittableList randomScene()
{
  HittableList world{};

  auto groundMaterial{std::make_shared<Lambertian>(Color{0.5, 0.5, 0.5})};
  world.add(std::make_shared<Sphere>(Point3{0, -1000, 0}, 1000, groundMaterial));

  for (int a{-11}; a < 11; ++a)
  {
    for (int b{-11}; b < 11; ++b)
    {
      auto chooseMat{RandomGen::getRandomDouble(0, 1)};
      Point3 center{a + 0.9 * RandomGen::getRandomDouble(0, 1), 0.2, b + 0.9 * RandomGen::getRandomDouble(0, 1)};
    
      if ((center - Point3{4, 0.2, 0}).length() > 0.9)
      {
        std::shared_ptr<Material> sphereMaterial{};

        if (chooseMat < 0.8)
        {
          auto albedo{rndVec3() * rndVec3()};
          sphereMaterial = std::make_shared<Lambertian>(albedo);
          world.add(std::make_shared<Sphere>(center, 0.2, sphereMaterial));
        }
        else if (chooseMat < 0.95)
        {
          auto albedo{rndVec3(0.5, 1)};
          auto fuzz{RandomGen::getRandomDouble(0, 0.5)};
          sphereMaterial = std::make_shared<Metal>(albedo, fuzz);
          world.add(std::make_shared<Sphere>(center, 0.2, sphereMaterial));
        }
      }
    }
  }

  auto material1{std::make_shared<Dielectric>(1.5)};
  world.add(std::make_shared<Sphere>(Point3{0, 1 ,0}, 1.0, material1));

  auto material2{std::make_shared<Lambertian>(Color{0.4, 0.2, 0.1})};
  world.add(std::make_shared<Sphere>(Point3{-4, 1, 0}, 1.0, material2));

  auto material3{std::make_shared<Metal>(Color{0.7, 0.6, 0.5}, 0.0)};
  world.add(std::make_shared<Sphere>(Point3{4, 1, 0}, 1.0, material3));

  return world;
}
