#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap    jc("Jacky Chan");
    ScavTrap    bo("Barak Obama");
    ScavTrap    as("Anakin Skywalker");
    ScavTrap    mk("Mia kalif");

    jc.attack(bo.getName());
    bo.takeDamage(20);
    as.takeDamage(100);
    as.attack(mk.getName());
    as.beRepaired(5);
    as.guardGate();
    mk.takeDamage(5);
    mk.beRepaired(4);
    mk.guardGate();
}