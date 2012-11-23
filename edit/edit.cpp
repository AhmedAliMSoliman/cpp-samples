#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "edit.h"

// Convenience for printing vectors
template <class T>
std::string Print(const std::vector<T> & v) {
  std::ostringstream s;
  std::copy(
            v.begin(),
            v.end(),
            std::ostream_iterator<T>(s, " "));
  return s.str();
}

int main() {
  std::cout << "Test suite for the edit distance\n";
  std::string string1 = "";
  std::string string2 = "";
  std::cout << "Distance between two empty strings: " <<
               edit(string1, string2) << "\n";

  string1 = "hello";
  string2 = "h";
  std::cout << "Distance between " <<
               string1 << " and " << string2 << ": " <<
               edit(string1, string2) << "\n";

  std::vector<std::string> strvec1 = {"hello", "how", "are", "you"};
  std::vector<std::string> strvec2 = {"hello", "who", "are", "you"};
  std::cout << "Distance between "<< Print(strvec1) << " and " <<
               Print(strvec2) << ": " << edit(strvec1, strvec2) << "\n";

  std::vector<int> intvec1 = {1, 2, 3, 4};
  std::vector<int> intvec2 = {1, 1, 4};
  std::cout << "Distance between "<< Print(intvec1) << " and " <<
               Print(intvec2) << ": " << edit(intvec1, intvec2) << "\n";
  std::cout << "Distance between "<< Print(intvec2) << " and " <<
               Print(intvec1) << ": " << edit(intvec2, intvec1) << "\n";

  return 0;
}
