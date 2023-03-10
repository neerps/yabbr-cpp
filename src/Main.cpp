/*
*/
#include "Camera.h"
#include "Color.h"
#include "Dielectric.h"
#include "HittableList.h"
#include "Lambertian.h"
#include "Material.h"
#include "Metal.h"
#include "RandomGen.h"
#include "Rtweekend.h"
#include "Sphere.h"

#include <iostream>

//
int main()
{
  // Image
  constexpr auto aspectRatio{16.0 / 9.0};
  constexpr int imageWidth{400};
  constexpr int imageHeight{static_cast<int>(imageWidth / aspectRatio)};
  constexpr int samplesPerPixel{100};
  constexpr int maxDepth{50};

  // World
  HittableList world{};

  auto materialGround{std::make_shared<Lambertian>(Color{0.8, 0.8, 0.0})};
  auto materialCenter{std::make_shared<Lambertian>(Color{0.1, 0.2, 0.5})};
  auto materialLeft{std::make_shared<Dielectric>(1.5)};
  auto materialRight{std::make_shared<Metal>(Color{0.8, 0.6, 0.2}, 0.0)};

  world.add(std::make_shared<Sphere>(Point3{0.0, -100.5, -1.0}, 100.0, materialGround));
  world.add(std::make_shared<Sphere>(Point3{0.0, 0.0, -1.0}, 0.5, materialCenter));
  world.add(std::make_shared<Sphere>(Point3{-1.0, 0.0, -1.0}, 0.5, materialLeft));
  world.add(std::make_shared<Sphere>(Point3{-1.0, 0.0, -1.0}, -0.45, materialLeft));
  world.add(std::make_shared<Sphere>(Point3{1.0, 0.0, -1.0}, 0.5, materialRight));

  // Camera
  Point3 lookFrom{3, 3, 2};
  Point3 lookAt{0, 0, -1};
  Vec3 vUp{0, 1, 0};
  auto distToFocus{(lookFrom - lookAt).length()};
  auto aperture{2.0};
  Camera cam{lookFrom, lookAt, vUp, 20, aspectRatio, aperture, distToFocus};

  // Render
  std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

  for (int j{imageHeight - 1}; j >= 0; --j)
  {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i{0}; i < imageWidth; ++i)
    {
      Color pixelColor{0, 0, 0};
      for (int s{0}; s < samplesPerPixel; ++s)
      {
        auto u{(i + RandomGen::getRandomDouble(0, 1)) / (imageWidth - 1)};
        auto v{(j + RandomGen::getRandomDouble(0, 1)) / (imageHeight - 1)};
        Ray r{cam.getRay(u, v)};
        pixelColor += rayColor(r, world, maxDepth);
      }
      writeColor(std::cout, pixelColor, samplesPerPixel);
    }
  }
  std::cerr << "\nDone.\n";

  return 0;
}
