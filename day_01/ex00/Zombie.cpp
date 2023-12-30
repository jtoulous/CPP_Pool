#include "Zombie.hpp"

Zombie::Zombie(std::string in_name)
: name(in_name)
{}

Zombie::~Zombie()
{
    std::cout << name << " destroyed" << std::endl;
}

void    Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}