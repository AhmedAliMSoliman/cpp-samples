#ifndef _HEAP_H
#define _HEAP_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <class T>
class Heap {
 public:
  Heap<T>&  Insert(const T&);
  T Delete();
  std::string Print();
  explicit Heap(bool max = true) : m_max(max) { }
  Heap(const std::vector<T>&, bool);
  friend std::ostream& operator<<(std::ostream& stream, const Heap& h) {
    std::copy(h.m_data.begin(),
              h.m_data.end(),
              std::ostream_iterator<T>(stream, " "));
    return stream;
  }
 private:
  bool m_max;
  std::vector<T> m_data;
  void Heapify(int);
  inline bool compare(const T& left, const T& right) {
    return m_max ? left > right : left < right;
  }
};

template <class T>
void Heap<T>::Heapify(int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;
  if ( (left < m_data.size()) &&
       compare(m_data.at(left), m_data.at(largest))) {
    largest = left;
  }
  if ( (right < m_data.size()) &&
       compare(m_data.at(right), m_data.at(largest))) {
    largest = right;
  }
  if (i != largest) {
    int tmp = m_data.at(largest);
    m_data.at(largest) = m_data.at(i);
    m_data.at(i) = tmp;
    Heapify(largest);
  }
}

template <class T>
Heap<T>::Heap(const std::vector<T>& v, bool max = true)
              : m_data(v), m_max(max) {
  for (int i = v.size() / 2 ; i >= 0 ; --i) Heapify(i);
}

template <class T>
Heap<T>& Heap<T>::Insert(const T& element) {
  m_data.push_back(element);
  int child = m_data.size() - 1;
  int parent = (child - 1) / 2;
  while ( (parent >= 0) &&
          compare(m_data.at(child), m_data.at(parent))) {
    int tmp = m_data.at(parent);
    m_data.at(parent) = m_data.at(child);
    m_data.at(child) = tmp;
    child = parent;
    parent = (parent - 1) / 2;
  }
  return *this;
}

template <class T>
std::string Heap<T>::Print() {
  std::ostringstream s;
  std::copy(m_data.begin(),
            m_data.end(),
            std::ostream_iterator<T>(s, " "));
  return s.str();
}

template <class T>
T Heap<T>::Delete() {
  if (m_data.size() == 0) throw 0;
  T out = m_data.at(0);
  if (m_data.size() > 1) {
    m_data.at(0) = m_data.back();
    m_data.pop_back();
    Heapify(0);
  }
  return out;
}

#endif /* _HEAP_H */
