#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>

template <class T>
std::vector<T> merge(std::vector<T>& left, std::vector<T>& right) {
  std::vector<T> output;
  output.reserve(left.size() + right.size());
  while (left.size() > 0 || right.size() > 0) {
    if (left.size() == 0) {
      output.insert(output.end(), right.begin(), right.end());
      right.resize(0);
    } else if (right.size() == 0) {
      output.insert(output.end(), left.begin(), left.end());
      left.resize(0);
    } else if (left.front() < right.front()) {
      output.push_back(left.front());
      left.erase(left.begin());
    } else {
      output.push_back(right.front());
      right.erase(right.begin());
    }
  }
  return output;
}

template <class T>
std::vector<T> sort(const std::vector<T>& input) {
  if (input.size() <= 1) return input;
  std::vector<T> left(input.size() / 2);
  std::copy_n(input.begin(), input.size() / 2, left.begin());
  std::vector<T> right(input.size() - (input.size() / 2));
  std::copy(input.begin() + (input.size() / 2), input.end(), right.begin());
  std::vector<T> left_sorted = sort(left);
  std::vector<T> right_sorted = sort(right);
  return merge(right_sorted, left_sorted);
}

#endif /* SORT_H */
