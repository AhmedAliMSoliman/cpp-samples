#include "sort.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template<class T>
std::string print(const std::vector<T>& v) {
  std::stringstream s;
  std::copy(v.begin(), v.end(), std::ostream_iterator<T>(s, " "));
  return s.str();
}

int main() {
  std::vector<int> v{12, -1, -3, 5, 18, 5, 2};
  std::cout << "Input vector " << print(v) << "\n";
  std::vector<int> out = sort(v);
  std::cout << "Output vector " << print(out) << "\n";
  return 0;
}
