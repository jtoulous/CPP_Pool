#include "Zombie.hpp"

int main(void)
{
    Zombie  first("first");
    Zombie  second("second");
    Zombie  *ptr;

    first.announce();
    second.announce();
    randomChump("random");
    ptr = newZombie("alloked");
    ptr->announce();
    delete (ptr);
}