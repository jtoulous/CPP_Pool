#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
            HumanA(std::string in_name, Weapon &in_weapon);
            void    attack();

    private:
            std::string name;
            Weapon      &weapon;
};

#endif