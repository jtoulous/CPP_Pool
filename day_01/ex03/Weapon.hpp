#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    public:
            Weapon();
            Weapon(std::string in_type);
            const std::string  &getType();
            void               setType(std::string input);

    private:
            std::string type;
};

#endif