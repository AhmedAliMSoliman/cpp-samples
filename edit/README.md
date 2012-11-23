Edit distance
-------------

This C++ sample illustrates how to compute the edit (or Levenshtein) distance between two sequences. The Wikipedia entry about the edit distance can be found here: [http://en.wikipedia.org/wiki/Levenshtein_distance].

The file `edit.h` contains the definition of the edit function, and `edit.cpp` runs tests with a few types of sequences (sequences of characters, words, numbers). It requires the C++11 initializers for convenience. It can be compiled and run with:

    $ g++ -std=c++0x -o edit edit.cpp
    $ ./edit

The definition of the `edit` function uses templates as input so that it can be used on any container (as long as it implements `at()` and `size()`) of any type (as long as it implements the equal to operator).