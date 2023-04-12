/*
*/
#include "Camera.h"
#include "Color.h"
#include "HittableList.h"
#include "RandomGen.h"
#include "Rtweekend.h"

#include <algorithm>
#include <array>
#include <fstream>
#include <execution>
#include <iostream>
#include <string>
#include <vector>

//
HittableList randomScene();

//
int main(int argc, char* argv[])
{
  // Image
  constexpr auto aspectRatio{3.0 / 2.0};
  constexpr int imageWidth{1200};
  constexpr int imageHeight{static_cast<int>(imageWidth / aspectRatio)};
  constexpr int samplesPerPixel{64};
  constexpr int maxDepth{16};

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
  std::vector<int> vericalIter(imageHeight);
  for (int i{imageHeight}; i >= 0; --i)
  {
    vericalIter[static_cast<size_t>(i)] = (imageHeight - i);
  }

  std::vector<int> horizontalIter(imageWidth);
  for (int i{0}; i < imageWidth; ++i)
  {
    horizontalIter[static_cast<size_t>(i)] = i;
  }

  imageFile << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

  std::for_each(std::execution::par, vericalIter.begin(), vericalIter.end(), 
                [&](auto j){
                  std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;
                  std::array<Color, imageWidth> currentLine{};
                  std::for_each(std::execution::par, horizontalIter.begin(), horizontalIter.end(),
                  [&](auto i){
                    Color pixelColor{0, 0, 0};
                    for (int s{0}; s < samplesPerPixel; ++s)
                    {
                      auto u{(i + RandomGen::getRandomDouble(0, 1)) / (imageWidth - 1)};
                      auto v{(j + RandomGen::getRandomDouble(0, 1)) / (imageHeight - 1)};
                      Ray r{cam.getRay(u, v)};
                      pixelColor += rayColor(r, world, maxDepth);
                    }
                    currentLine[static_cast<size_t>(i)] = pixelColor;
                  });
                  for (auto pixel : currentLine)
                  {
                    writeColor(imageFile, pixel, samplesPerPixel);
                  }
                });

  std::cout << "\nDone.\n";

  return 0;
}
