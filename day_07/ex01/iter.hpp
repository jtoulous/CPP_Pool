#pragma once

#include "String_2_guerre.hpp"

template <typename T, typename S, typename F>
void    iter(T  tab, S  size, F func)
{
    for (S z = 0; z < size; z++)
    {
        func(tab[z]);
    }
}

template <typename T>
void    addOne(T &var)
{
    var = var + 1;
}