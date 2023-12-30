#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class   Zombie
{
    public:
            Zombie();
            Zombie(std::string in_name);
            ~Zombie();
            void        announce();
            void        set_name(std::string in_name);

    private:
            std::string name;
};

Zombie  *zombieHorde(int  N, std::string in_name);

# endif