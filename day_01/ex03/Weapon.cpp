#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string in_type)
:type(in_type)
{}

const std::string &Weapon::getType()
{
    return (this->type);
}

void    Weapon::setType(std::string input)
{
    this->type = input;
}