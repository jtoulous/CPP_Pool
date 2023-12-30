#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t   serialized;

    serialized = reinterpret_cast<uintptr_t>(ptr);
    return (serialized);
}

Data    *Serializer::deserialize(uintptr_t raw)
{
    Data *deserialized;

    deserialized = reinterpret_cast<Data *>(raw);
    return (deserialized);
}

Serializer::Serializer()
{}

Serializer::~Serializer()
{}

Serializer::Serializer(const Serializer &ref)
{
    (void)ref;
}

Serializer &Serializer::operator=(Serializer &ref)
{
    return (ref);
}

