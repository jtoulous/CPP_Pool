#include "Serializer.hpp"

#include <iostream>

int main(void)
{
    Data test;
    Data *ptr2;
    uintptr_t   ptr;

    test.str = "wesh";
    test.ch = 'c';
    test.nb = 5;

    std::cout << test.str << " " << test.nb << " " << test.ch << std::endl;

    ptr = Serializer::serialize(&test);
    ptr2 = Serializer::deserialize(ptr);
    std::cout << ptr2->str << " " << ptr2->nb << " " << ptr2->ch << std::endl;
}   