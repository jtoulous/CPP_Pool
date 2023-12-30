#include "Zombie.hpp"

int main(void)
{
    Zombie  first("first");
    Zombie  second("second");
    Zombie  *ptr;
    int z = -1;

    first.announce();
    second.announce();
    ptr = zombieHorde(5, "horde");
    while (++z < 5)
        ptr[z].announce();
    delete[] (ptr);
}