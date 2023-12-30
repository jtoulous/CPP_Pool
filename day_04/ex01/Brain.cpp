#include "Brain.hpp"

Brain::Brain()
{
    ideas[0] = "wesh";
    std::cout << "a Brain has been built" 
              << std::endl;
}

Brain::~Brain()
{
    std::cout << "a Brain has been destroyed" 
              << std::endl;
}

Brain::Brain(Brain &to_copy)
{
    int     z = -1;

    while (++z < 100)
        ideas[z] = to_copy.ideas[z];
    std::cout << "a Brain has been built" 
              << std::endl;
}

Brain   &Brain::operator=( Brain &ref)
{
    if (this != &ref)
    {
        for (int z = 0; z < 100; z++)
            ideas[z] = ref.ideas[z];
    }
    return (*this);
}