
#include <chrono>
#include <random>
#include "maze/utils.h"

namespace utils {

int random_integer(int lower, int upper) {
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(lower, upper);
  return distribution(generator);
}

}
