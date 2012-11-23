#ifndef DIST_H
#define DIST_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <vector>

template <class T> class Dist;

template <class T>
std::ostream& operator<<(std::ostream &, const Dist<T>&);

template <class T>
std::istream& operator>>(std::istream &, Dist<T>&);

template <class T>
class Dist {
 public:
  explicit Dist(int dist_length = 1) : input_length(0), dist(dist_length) {
    std::srand(std::time(0));
  }
  int count(int n) { return std::count(dist.begin(), dist.end(),  n); }
  friend std::ostream& operator<< <> (std::ostream &, const Dist<T>&);
  friend std::istream& operator>> <> (std::istream &, Dist<T>&);
 private:
  int64_t input_length;
  std::vector<T> dist;
};

template <class T>
std::ostream& operator<<(std::ostream & stream, const Dist<T>& d) {
  std::copy(d.dist.begin(), d.dist.end(),
            std::ostream_iterator<T>(stream, " "));
  return stream;
}

template <class T>
std::istream& operator>>(std::istream & stream, Dist<T>& d) {
  int random_variable = std::rand();
  ++d.input_length;
  T elt;
  stream >> elt;
  if ( random_variable < d.dist.size() * RAND_MAX / d.input_length ) {
    d.dist.at(d.input_length % d.dist.size()) = elt;
  }
  return stream;
}

#endif /* DIST_H */
