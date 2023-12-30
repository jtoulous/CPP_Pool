#include "Pair.hpp"

Pair::Pair()
{}

Pair::Pair(int nb1, int nb2)
{
    if (nb1 < nb2)
    {
        small = nb1;
        big = nb2;
    }
    else
    {    
        small = nb2;
        big = nb1;
    }
}

Pair::Pair(const Pair &ref)
{
    *this = ref;
}

Pair::~Pair()
{}

Pair    &Pair::operator=(const Pair &ref)
{
    this->big = ref.big;
    this->small = ref.small;
    return (*this);
}