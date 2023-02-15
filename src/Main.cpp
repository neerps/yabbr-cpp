/*
*/
#include "Camera.h"
#include "Color.h"
#include "HittableList.h"
#include "RandomDoubleGen.h"
#include "Rtweekend.h"
#include "Sphere.h"

#include <iostream>

//
int main()
{
  //
  RandomDoubleGen rng{};

  // Image
  const auto aspectRatio{16.0 / 9.0};
  const int imageWidth{400};
  const int imageHeight{static_cast<int>(imageWidth / aspectRatio)};
  const int samplesPerPixel{100};
  const int maxDepth{50};

  // World
  HittableList world;
  world.add(std::make_shared<Sphere>(Point3{0, 0, -1}, 0.5));
  world.add(std::make_shared<Sphere>(Point3{0, -100.5, -1}, 100));

  // Camera
  Camera cam{};

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
        auto u{(i + rng.getRandom(0, 1)) / (imageWidth - 1)};
        auto v{(j + rng.getRandom(0, 1)) / (imageHeight - 1)};
        Ray r{cam.getRay(u, v)};
        pixelColor += rayColor(r, world, rng, maxDepth);
      }
      writeColor(std::cout, pixelColor, samplesPerPixel);
    }
  }
  std::cerr << "\nDone.\n";

  return 0;
}
