#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
  public:
          ClapTrap();
          ClapTrap(std::string in_name);
          ClapTrap(const ClapTrap &to_copy);
          ClapTrap(std::string in_name, int in_hp, int in_nrj, int atck);
          ~ClapTrap();
          ClapTrap &operator=(const ClapTrap &ref);
          
          virtual void          attack(const std::string &target);
          void                  takeDamage(unsigned int amount);
          void                  beRepaired(unsigned int amount);
          std::string           &get_name();

  protected:
          std::string name;
          int         hp;
          int         nrj;
          int         atck;
};

#endif