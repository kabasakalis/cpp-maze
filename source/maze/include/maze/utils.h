#pragma once

#include <iostream>
#include <random>
#include <vector>
namespace utils {

template <class T>
void logVar(const T& var, std::string message = "Logging") {
  std::cout << message << "\n";
  std::cout << var;
  std::cout << "\n";
  return;
}

template <typename Key, typename Value>
std::ostream& operator<<(std::ostream& os,
                         const std::pair<const Key, Value>& p) {
  os << p.first << " => " << p.second;
  return os;
}

// Log Containers
template <typename Container>
void log(const Container& c, std::string message, std::string sep = ", ") {
  std::cout << message << "\n";
  for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
    std::cout << *it;
    if (it != (--c.end())) {
      std::cout << sep;
    };
  };
  std::cout << "\n";
}

template <typename T>
T random_element(std::vector<T> v) {
	std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<unsigned long> dist(0, v.size() - 1);
	// T random_element = v[dist(engine)];
return  v.at(dist(engine));

}

int random_integer(int lower, int upper);
}
