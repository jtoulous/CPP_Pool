#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string in_name, Weapon &in_weapon):
name(in_name),
weapon(in_weapon)
{}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}