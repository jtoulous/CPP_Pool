#include "ClapTrap.hpp"

int main()
{
    ClapTrap    jc("Jacky Chan");
    ClapTrap    bo("Barak Obama");
    ClapTrap    as("Anakin Skywalker");
    ClapTrap    mk("Mia kalif");

    jc.attack(bo.getName());
    bo.takeDamage(0);
    as.takeDamage(9);
    as.takeDamage(2);
    as.attack(mk.getName());
    as.beRepaired(5);
    mk.takeDamage(5);
    mk.beRepaired(4);
}