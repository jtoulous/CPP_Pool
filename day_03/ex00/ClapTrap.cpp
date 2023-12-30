#include "ClapTrap.hpp"

////////////////////////////////////////////////
///////////  CONSTRUCTORS && DESTROYERS   //////
////////////////////////////////////////////////

ClapTrap::ClapTrap()
: name("default"), hp(10), nrj(10), atck(0)
{}

ClapTrap::ClapTrap(std::string in_name)
: name(in_name), hp(10), nrj(10), atck(0)
{
  std::cout << "ClapTrap " << name << " has been built" 
            << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &to_copy)
:name(to_copy.name), hp(to_copy.hp), nrj(to_copy.nrj), atck(to_copy.atck)
{
  std::cout << "ClapTrap " << name << " has been built" 
            << std::endl;
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap " << name << " has been destroyed" 
            << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref)
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

void  ClapTrap::attack(const std::string &target)
{
  if (hp <= 0)
  {
    std::cout << "ClapTrap " << name << " is dead, he can't attack" 
              << std::endl;
    return ;
  }

  if (nrj == 0)
  {
    std::cout << "ClapTrap " << name << " out of energy" 
              << std::endl;
    return ;
  }

  nrj -= 1;
  std::cout << "ClapTrap " << name << " attacks " << target 
            << ", causing " << atck << " points of damage!" 
            << std::endl;
}

///////////////////////////////////////////////////
//////////     FCNT        ////////////////////////
///////////////////////////////////////////////////

void  ClapTrap::takeDamage(unsigned int amount)
{
  if (hp <= 0)
  {
    std::cout << "ClapTrap " << name << " is already dead" 
              << std::endl;
    return ;
  }

  std::cout << "ClapTrap " << name << " takes " << amount << " damage" 
            << std::endl;
  hp -= amount;
  if (hp <= 0)
    std::cout << "rip " << "ClapTrap " << name 
              << std::endl;
}

void  ClapTrap::beRepaired(unsigned int amount)
{
  if (hp <= 0)
  {
    std::cout << "ClapTrap " << name << " is dead, he can't be repaired" 
              << std::endl;
    return ;
  }

  if (nrj == 0)
  {
    std::cout << "ClapTrap " << name << " out of energy" 
              << std::endl;
    return ;
  }

  std::cout << "ClapTrap " << name << " got repaired and gains " 
            << amount << " hp" 
            << std::endl;
  hp += amount;
  nrj -= 1;
}

std::string  &ClapTrap::getName()
{
  return (name);
}