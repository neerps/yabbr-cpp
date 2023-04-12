/*
  Mersenne-twsiter based random generator
  and corresponding methods to get random values

  Current version is based on code from
  https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
*/
#ifndef RANDOM_DOUBLE_GEN_H
#define RANDOM_DOUBLE_GEN_H

#include <chrono>
#include <random>

//
namespace RandomGen
{
  inline std::mt19937_64 init()
  {
    std::random_device rd;

    std::seed_seq ss{
      static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()),
      rd(), rd(), rd(), rd(), rd(), rd(), rd()
    };

    return std::mt19937_64{ss};
  }

  inline thread_local std::mt19937_64 mt{init()};

  inline double getRandomDouble(double lower, double upper)
  {
    std::uniform_real_distribution<double> dicey(lower, upper);
    return dicey(mt);
  }
}

#endif
