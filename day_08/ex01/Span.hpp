#pragma once

#include <vector>
#include <exception>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include "String_2_guerre.hpp"

class Span
{
    public:
            typedef std::vector<int>::iterator iterator;

            Span();
            Span(unsigned int in_maxSize);
            Span(const Span &ref);
            ~Span();

            Span    &operator=(const Span &ref); 

            unsigned int                getSize();
            iterator  getBegin();
            iterator  getEnd();

            void    addNumber(int to_add);
            int    shortestSpan();
            int    longestSpan();
            
            void    addSpan(iterator it_begin, iterator it_end);

    private:
            std::vector<int>    vec;
            unsigned int maxSize;
};