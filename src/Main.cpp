/*
*/
#include "Camera.h"
#include "Color.h"
#include "HittableList.h"
#include "RandomGen.h"
#include "Rtweekend.h"

#include <fstream>
#include <iostream>
#include <string>

//
HittableList randomScene();

//
int main(int argc, char* argv[])
{
  // Image
  constexpr auto aspectRatio{3.0 / 2.0};
  constexpr int imageWidth{1200};
  constexpr int imageHeight{static_cast<int>(imageWidth / aspectRatio)};
  constexpr int samplesPerPixel{32};
  constexpr int maxDepth{8};

  // World
  HittableList world{randomScene()};

  // Camera
  Point3 lookFrom{13, 2, 3};
  Point3 lookAt{0, 0, 0};
  Vec3 vUp{0, 1, 0};
  auto distToFocus{10.0};
  auto aperture{0.1};
  Camera cam{lookFrom, lookAt, vUp, 20, aspectRatio, aperture, distToFocus};

  // Output
  constexpr auto default_image_name{"default.ppm"};
  std::string image_name{};
  image_name = (argc == 1) ? default_image_name : std::string(argv[1]);
  std::ofstream imageFile{image_name};

  // Render
  imageFile << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

  for (int j{imageHeight - 1}; j >= 0; --j)
  {
    std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;
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
      writeColor(imageFile, pixelColor, samplesPerPixel);
    }
  }
  std::cout << "\nDone.\n";

  return 0;
}
