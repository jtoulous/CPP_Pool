#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

//////////////////////////////////////////////
///////////     BUILDERS   ///////////////////
//////////////////////////////////////////////

ScavTrap::ScavTrap()
: ClapTrap("default", 100, 50, 20)
{}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name, 100, 50, 20)
{ 
    std::cout << "ScavTrap " << name << " is built" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &to_copy)
: ClapTrap(to_copy)
{
    std::cout << "ScavTrap " << name << " is built" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " has been destroyed" << std::endl;
}

ScavTrap    &ScavTrap::operator=(const ScavTrap &ref)
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

//////////////////////////////////////////
/////////    FONC     ////////////////////
//////////////////////////////////////////


void    ScavTrap::attack(const std::string &target)
{
    if (hp <= 0)
    {
        std::cout << "ScavTrap " << name << " is dead, he can't attack" 
                  << std::endl;
        return ;
    }

    if (nrj == 0)
    {
        std::cout << "ScavTrap " << name << " is out of energy" 
                  << std::endl;
                  return ;
    }

    nrj -= 1;
    std::cout << "ScavTrap " << name << " attacks " << target 
              << ", causing " << atck << " points of damage!" 
              << std::endl;
}

void    ScavTrap::guardGate()
{
    if (hp <= 0)
    {
        std::cout << "ScavTrap " << name << " is dead, he can't keep the gate" 
                  << std::endl;
        return ;
    }

    if (nrj == 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy" 
                  << std::endl;
                  return ;
    }

    nrj -= 1;    
    std::cout << "ScavTrap " << name << " has entered gate-keeper mode" 
              << std::endl;
}