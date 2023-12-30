#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap("default", 100, 100, 30)
{}

FragTrap::FragTrap(std::string in_name)
: ClapTrap(in_name, 100, 100, 30)
{   
    std::cout << "FragTrap " << name << " is built" << std::endl;
}

FragTrap::FragTrap(const FragTrap &to_copy)
: ClapTrap(to_copy)
{   
    std::cout << "FragTrap " << name << " is built" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Fragtrap " << name << " has been destroyed" << std::endl;
}

FragTrap    &FragTrap::operator=(const FragTrap &ref)
{
    if (this != &ref)
    {
        name = ref.name;
        hp = ref.hp;
        nrj = ref.nrj;
        atck = ref.atck;
    }
  return (*this);
}

////////////////////////////////////////
///////////    FONC   //////////////////
////////////////////////////////////////

void    FragTrap::attack(std::string &target)
{
    if (hp <= 0)
    {
        std::cout << "FragTrap " << name << " is dead, he can't attack" 
                  << std::endl;
        return ;
    }

    if (nrj == 0)
    {
        std::cout << "FragTrap " << name << " is out of energy" 
                  << std::endl;
                  return ;
    }

    nrj -= 1;
    std::cout << "FragTrap " << name << " attacks " << target 
              << ", causing " << atck << " points of damage!" 
              << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    if (hp <= 0)
    {
        std::cout << "FragTrap " << name << " is dead, he can't High-Five" 
                  << std::endl;
        return ;
    }

    if (nrj == 0)
    {
        std::cout << "FragTrap " << name << " is out of energy" 
                  << std::endl;
                  return ;
    }

    nrj -= 1;
    std::cout << "FragTrap " << name << " wants to High-Five" 
              << std::endl;
}