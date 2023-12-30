#pragma once

#include "libX.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cmath>
#include "Pair.hpp"

#define INT_MAX std::numeric_limits<int>::max()

template <typename container, typename container2>
class PmergeMe
{
    public:
            static void errorz(int argc, char **argv, container &list);
            static void sort(container &list);

    private:
            static void    initPairs(container &list, container2 &pairs);
            static void    fillMax(container &list, container2 &pairs);
            static int     binarySearch(int big, int small, container &list);
            static void    insertOddval(container &list, int oddVal);
            static void    sortPairs(container2 &pairs); 
            static int     jacobsthal(String opt, int size, int *done);

            PmergeMe();
            PmergeMe(const PmergeMe &ref);
            ~PmergeMe();
            PmergeMe &operator=(PmergeMe &ref);
};

#include "PmergeMe.cpp"