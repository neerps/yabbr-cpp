/*
*/
#include "Camera.h"
#include "Color.h"
#include "HittableList.h"
#include "RandomGen.h"
#include "Rtweekend.h"

#include <iostream>

//
HittableList randomScene();

//
int main()
{
  // Image
  constexpr auto aspectRatio{3.0 / 2.0};
  constexpr int imageWidth{1200};
  constexpr int imageHeight{static_cast<int>(imageWidth / aspectRatio)};
  constexpr int samplesPerPixel{500};
  constexpr int maxDepth{50};

  // World
  HittableList world{randomScene()};

  // Camera
  Point3 lookFrom{13, 2, 3};
  Point3 lookAt{0, 0, 0};
  Vec3 vUp{0, 1, 0};
  auto distToFocus{10.0};
  auto aperture{0.1};
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
