#pragma once

#include <stdint.h>
#include "String_2_guerre.hpp"


typedef struct s_data
{
    int     nb;
    String  str;
    char    ch;
}               Data;

class Serializer
{
    public:
            static uintptr_t serialize(Data *ptr);
            static Data *deserialize(uintptr_t raw);
    
    private:
            Serializer();
            Serializer(const Serializer   &ref);
            ~Serializer();
            Serializer  &operator=(Serializer &ref);
};