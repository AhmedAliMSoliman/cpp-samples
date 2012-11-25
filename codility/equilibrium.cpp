#include <stdint.h>

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int equi(const std::vector<int> &A) {
  if (A.size() == 0) return -1;
  int64_t right = 0;
  int64_t left = 0;
  for (int i = 1; i < A.size() ; ++i) right += A.at(i);
  if (right == 0) return 0;
  for (int i = 1 ; i < A.size() ; ++i) {
    right -= A.at(i);
    left += A.at(i-1);
    if (right == left) return i;
  }
  return -1;
}

int main() {
  std::vector<int> v = {-7, 1, 5, 2, -4, 3, 0};
  std::vector<int> solutions = {3, 6};

  if (std::find(solutions.begin(),
                solutions.end(),
                equi(v)) != solutions.end())
    std::cout << "Test from the task description passed\n";

  int element_min = -2147483648;
  int element_max = 2147483647;
  int length_max = 1e7;

  std::vector<int> v2 = {element_min, element_max, element_min + 1,
                         element_max - 1, 1 - 2 * element_min,
                         -1 - 2 * element_max, 60, 0};
  if (equi(v2) == 6) std::cout << "Test with large numbers passed\n";

  return 0;
}
