#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
            FragTrap();
            FragTrap(std::string in_name);
            FragTrap(const FragTrap &to_copy);
            ~FragTrap();
            FragTrap &operator=(const FragTrap &ref);

            void    attack(std::string &target);
            void    highFivesGuys(void);
};

#endif