# Yet Another Book Based Raytracing, C++ version

## Intro
This is my version for the raytracer code from the book [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley.

As I am a novice in C++, most of the code foolows the book representation except some different parts and overall approach. More specifically:
1. Mersenne Twister.
2. Separation of interface and implementation.
3. More modern C++.

## Differences compared to the book version
### Mersenne Twister
For some reason, author doesn't seed Mersenne Twister. Maybe because it's not the kind of an application for that?
In any case, I tried to apply what I learned from [_learncpp_](https://www.learncpp.com/), so my implementation uses another approach. (Hope that I was able to put proper links everywhere for the parts that I borrowed.)

### Separation of interface and implementation
Probably, again wasn't quite necessary for the application. But I decided to stick to the approach.

### More modern C++
I tried to use current best practices, at least, those that I saw on [_learncpp_](https://www.learncpp.com/) and got used to.
Unified initialisation where possible (and not forgotten), constexpr and inline constants in headers, etc.

## How to launch
Use script in the top of the repository:

```sh
chmod +x ./get_image.sh
./get_image.sh
```

No specific parameters to pass for the moment.
