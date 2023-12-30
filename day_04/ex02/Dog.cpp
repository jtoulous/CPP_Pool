#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
    brain = new Brain;
    std::cout << "a Dog has been built" << std::endl;
}

Dog::Dog(const Dog &to_copy)
: Animal(to_copy)
{
    brain = new Brain(*to_copy.brain);
    std::cout << "a Dog has been built" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "a Dog has been destroyed" << std::endl; 
}

Dog &Dog::operator=(const Dog &ref)
{
    if (this != &ref)
        type = ref.type;
    if (brain != NULL)
        delete brain;
    brain = new Brain(*ref.brain);
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Dog sound" << std::endl;
}