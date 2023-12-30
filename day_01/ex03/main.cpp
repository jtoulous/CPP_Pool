#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        std::cout << club.getType() << std::endl;
        bob.attack();
        club.setType("other type of club");
        bob.attack();
    }
    std::cout << "\n";
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("other type of club");
        jim.attack();
    }
    return 0;
}