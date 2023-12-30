#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::Zombie(std::string in_name): name(in_name)
{}

Zombie::~Zombie()
{   
    std::cout << name << " has been destroyed" << std::endl;
}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string in_name)
{
    name = in_name;
}