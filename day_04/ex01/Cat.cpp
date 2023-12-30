#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
    brain = new Brain;
    std::cout << "a Cat has been built" 
              << std::endl;
}

Cat::Cat(const Cat &to_copy)
: Animal(to_copy)
{
    brain = new Brain(*to_copy.brain);
    std::cout << "a Cat has been built" << std::endl;
}

Cat::~Cat()
{
      delete brain;
      std::cout << "a Cat has been destroyed" 
                << std::endl;
}

Cat &Cat::operator=(const Cat &ref)
{
    if (this != &ref)
        type = ref.type;
    if (brain != NULL)
        delete brain;
    brain = new Brain(*ref.brain);
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}
