#include "Zombie.hpp"
#include <stdio.h>

Zombie  *zombieHorde(int  N, std::string in_name)
{
  Zombie  *horde;
  int     z;

  z = -1;
  if (N <= 0)
    return (NULL);
  horde = new Zombie[N];
  while (++z < N)
    horde[z].set_name(in_name);
  return (horde);
}