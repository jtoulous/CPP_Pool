#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
    std::cout << "a Cat has been built" 
              << std::endl;
}

Cat::Cat(const Cat &to_copy)
: Animal(to_copy)
{
    std::cout << "a Cat has been built" 
              << std::endl;
}

Cat::~Cat()
{
      std::cout << "a Cat has been destroyed" 
                << std::endl;
}

Cat &Cat::operator=(const Cat &ref)
{
    if (this != &ref)
        type = ref.type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}
