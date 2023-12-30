#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
    public:
            HumanB(std::string input_name);
            HumanB(std::string input_name, Weapon input_weapon);
            void        setWeapon(Weapon &input_weapon);
            void        attack();

    private:
            std::string name;
            Weapon  *weapon;
};

#endif