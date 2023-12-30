#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
    std::cout << "a Dog has been built" << std::endl;
}

Dog::Dog(const Dog &to_copy)
: Animal(to_copy)
{
    std::cout << "a Dog has been built" << std::endl;
}

Dog::~Dog()
{
    std::cout << "a Dog has been destroyed" << std::endl; 
}

Dog &Dog::operator=(const Dog &ref)
{
    if (this != &ref)
        type = ref.type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Dog sound" << std::endl;
}