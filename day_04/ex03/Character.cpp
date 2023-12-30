#include "Character.hpp"

/////////     BUILDERS, DESTRUCTORS, OPERATORS //////////////

Character::Character(std::string &in_name)
: name(in_name), nb_dropped(0)
{
    inventory[0] = NULL;
    inventory[1] = NULL;
    inventory[2] = NULL;
    inventory[3] = NULL;
    dropped = NULL;
}

Character::Character(const char *in_name)
: name(in_name), nb_dropped(0)
{
    inventory[0] = NULL;
    inventory[1] = NULL;
    inventory[2] = NULL;
    inventory[3] = NULL;
    dropped = NULL;
}
 
Character::Character(const Character &to_copy)
{
    nb_dropped = 0;
    dropped = NULL;
    inventory[0] = NULL;
    inventory[1] = NULL;
    inventory[2] = NULL;
    inventory[3] = NULL;
    *this = to_copy;
}

Character::~Character()
{
    int z = -1;

    while (++z < 4)
    {
        if (inventory[z] != NULL)
            delete inventory[z];
    }
    z = -1;
    while (++z < nb_dropped)
        delete dropped[z];
    delete[] dropped;
}

Character   &Character::operator=(const Character &to_affect)
{
    if (this != &to_affect)
    {
        if (inventory[0] != NULL)
            delete inventory[0];
        if (inventory[1] != NULL)
            delete inventory[1];
        if (inventory[2] != NULL)
            delete inventory[2];
        if (inventory[3] != NULL)
            delete inventory[3];
        name = to_affect.name;
        if (inventory[0] != NULL)
            *inventory[0] = *to_affect.inventory[0]->clone();
        if (inventory[1] != NULL)
            *inventory[1] = *to_affect.inventory[1]->clone();
        if (inventory[2] != NULL)
            *inventory[2] = *to_affect.inventory[2]->clone();
        if (inventory[3] != NULL)
            *inventory[3] = *to_affect.inventory[3]->clone();
    }
    return (*this);
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

const std::string &Character::getName() const
{
    return (name);
}

void    Character::equip(AMateria *m)
{
    int z = 0;

    while (z < 4)
    {
        if (inventory[z] == NULL)
        {
            inventory[z] = m;
            /*std::cout << name << " has equipped the " << m->getType() << " Metaria" 
                      << std::endl;*/
            return ;
        }
        z++;
    }
    //std::cout << "no more space in inventory"
    //          << std::endl;
}

void    Character::unequip(int idx)
{
    AMateria    **new_dropped;
    int         z = 0;

    if (idx > 3)
        return ;
    if (inventory[idx] == NULL)
        std::cout << "already empty"
                  << std::endl;
    else
    {
        nb_dropped++;
        new_dropped = new AMateria*[nb_dropped];
        while (z < nb_dropped - 1)
        {
            new_dropped[z] = dropped[z];
            z++;
        }
        new_dropped[z /*+ 1*/] = inventory[idx];
        if (dropped != NULL)
            delete[] dropped;
        dropped = new_dropped;

        std::cout << inventory[idx]->getType() << " metaria unequiped"
                  << std::endl;
        
        inventory[idx] = NULL;
    }
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3)
        return;

    if (inventory[idx] != NULL)
        inventory[idx]->use(target);
    else
        std::cout << "nothing equipped there" << std::endl;
}