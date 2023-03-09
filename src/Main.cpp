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
  const auto R{cos(pi / 4)};
  HittableList world{};

  auto materialLeft{std::make_shared<Lambertian>(Color{0, 0, 1})};
  auto materialRight{std::make_shared<Lambertian>(Color{1, 0, 0})};

  world.add(std::make_shared<Sphere>(Point3{-R, 0, -1}, R, materialLeft));
  world.add(std::make_shared<Sphere>(Point3{R, 0, -1}, R, materialRight));

  // Camera
  Camera cam{90.0, aspectRatio};

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
