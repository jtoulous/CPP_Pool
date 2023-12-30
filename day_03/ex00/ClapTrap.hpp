#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
  public:
          ClapTrap();
          ClapTrap(std::string in_name);
          ClapTrap (ClapTrap &ref);
          ~ClapTrap();
          ClapTrap &operator=(const ClapTrap &ref);

          void          attack(const std::string &target);
          void          takeDamage(unsigned int amount);
          void          beRepaired(unsigned int amount);
          std::string   &getName();

  private:
          std::string name;
          int         hp;
          int         nrj;
          int         atck;
};

#endif
