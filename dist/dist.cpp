#include <iostream>
#include <sstream>

#include "dist.h"

// Test suite for Dist class
// Gets the percentage of multiples of
// 3 (should be 33%)

int main() {
  int multiples = 3;
  int distribution_length = 100;
  int observation_length = 1e6;
  Dist<int> x(100);
  std::stringstream s;
  for (int i = 0 ; i < observation_length ; ++i) {
    s << (i%multiples == 0) << " ";
    s >> x;
    s.str("");
  }
  std::cout << "Percentage of multiples of "<<
               multiples <<": " <<
               100 *  x.count(1)  / distribution_length <<
               "%\n";
  return 0;
}
