#include "heap.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

template <class T>
std::string Print(const std::vector<T>& v) {
  std::stringstream s;
  std::copy(v.begin(), v.end(), std::ostream_iterator<T>(s, " "));
  return s.str();
}

int main() {
  std::cout << "Test suite for heap implementation\n";
  std::vector<int> v_int ={ 7, 3, 12,-2, -5, 4, 12, 2, 0, -1};
  Heap<int> h;
  std::for_each(v_int.begin(), v_int.end(), [&h](const int& i) {h.Insert(i);});
  std::cout << "Inserted elements: " << Print(v_int) << "\n";
  std::cout << "Heap: "<< h.Print() << std::endl;
  std::cout << "First deleted elements: "<< h.Delete() << " " << h.Delete() << " " << h.Delete() << std::endl;
  std::cout << "New heap: "<< h << std::endl;
  
  std::cout << "\n";
  std::vector<float> v_float = {-3.5, 1.2e3, -1.2, 3.7, 5.1, 2.0, -3.1e5};
  std::cout << "Floats to heapify: " << Print(v_float) << "\n";
  Heap<float> H(v_float);
  std::cout << "Heapified floats: " << H << std::endl;
  Heap<float> HM(v_float, false);
  std::cout << "Min-heapified floats: " << HM << std::endl;
  return 0;
}
