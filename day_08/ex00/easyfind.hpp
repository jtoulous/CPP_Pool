#pragma once

#include <exception>
#include <algorithm>

template <typename container>
typename container::iterator    easyfind(container cont, int nb)
{
    typename container::iterator ite;

    ite = std::find(cont.begin(), cont.end(), nb);
    if (ite == cont.end())
        throw (std::exception());
    return ite;
}