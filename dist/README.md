Distribution of samples of an input stream
------------------------------------------

This is the solution to a programming exercise I have been given. The goal was to fill in a container of fixed size with samples with the same distribution as a given input stream of samples. The idea of the solution is that each time a sample is received, it must be decided whether or not to add it in the container. When the first samples are received, all samples must be included in the container, but as more samples are received, it get less likely that we must include each sample.

In other words, if the container is of length L, and we received N samples, the probability to add the next sample is:

    P(add_sample?) = min (1, L / N)

The given solution implements it, using a template for the sample type and `istream` syntax to add samples.

The file `dist.h` includes the implementation of the `Dist` class and the file `dist.cpp` shows a test. The test uses a long input stream of 0s and 1s, with a given percentage of 1s. At the end, we make sure we have the correct percentage of 1s.

To compile and run it:

    $ g++ -o dist dist.cpp
    $ ./dist

