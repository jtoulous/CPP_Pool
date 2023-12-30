#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap    jc("Jacky Chan");
    FragTrap    bo("Barak Obama");
    FragTrap    as("Anakin Skywalker");
    FragTrap    mk("Mia kalif");

    jc.attack(bo.get_name());
    bo.takeDamage(30);
    as.takeDamage(100);
    as.attack(mk.get_name());
    as.beRepaired(5);
    mk.takeDamage(99);
    mk.beRepaired(4);
    mk.highFivesGuys();
}