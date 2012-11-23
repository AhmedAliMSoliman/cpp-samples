#ifndef EDIT_H
#define EDIT_H

#include <algorithm>
#include <vector>

/*******************************************
 * Computes the Edit distance between two sequences
 * @section DESCRIPTION
 * Computes the edit distance between two sequences.
 * A sequence must implements the size() and at() functions and its 
 * elements must implement the equal to operator.
 * @param s1 initial sequence 
 * @param s2 target sequence 
 * @return edit distance, as an integer
 ********************************************/
template <class T>
int edit(const T& s1, const T& s2) {
  std::vector<std::vector<int> > path(s1.size() + 1,
                                      std::vector<int>(s2.size() + 1));
  for (int i = 0 ; i < s1.size() + 1 ; ++i)
    path.at(i).at(0) = i;
  for (int j = 0 ; j < s2.size() + 1 ; ++j)
    path.at(0).at(j) = j;
  for (int i = 1 ; i < s1.size() + 1 ; ++i)
    for (int j = 1 ; j < s2.size() + 1 ; ++j)
      path.at(i).at(j) = std::min(1 + path.at(i - 1).at(j),
                                  std::min(1 + path.at(i).at(j - 1),
                                           path.at(i - 1).at(j - 1) +
                                           (s1.at(i-1) != s2.at(j-1))));
  return path.at(s1.size()).at(s2.size());
}

#endif /* EDIT_H */
