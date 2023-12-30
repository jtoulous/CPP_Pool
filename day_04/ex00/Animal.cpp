#include "Animal.hpp"

Animal::Animal()
: type("unknown species") 
{
    std::cout << "an Animal has been built " 
              << std::endl;
}

Animal::Animal(std::string in_type)
: type(in_type)
{
    std::cout << "an Animal has been built " 
              << std::endl;
}

Animal::Animal(const Animal &to_copy)
: type(to_copy.type)
{
    std::cout << "an Animal has been built " 
              << std::endl;
}

Animal::~Animal()
{
    std::cout << "an Animal has been destroyed"
              << std::endl;
}

Animal  &Animal::operator=(const Animal &ref)
{
    if (this != &ref)
        type = ref.type;
    return (*this);
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void    Animal::makeSound() const
{
    std::cout << "Animal sound" 
              << std::endl;
}

const std::string   &Animal::getType() const
{
    return (type);
}