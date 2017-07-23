#pragma once

#include <iostream>

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

}
