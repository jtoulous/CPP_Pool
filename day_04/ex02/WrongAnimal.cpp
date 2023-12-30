#include "WrongAnimal.hpp"

///////////////////////////////////
/////// CLASS : WrongAnimal ///////
///////////////////////////////////


WrongAnimal::WrongAnimal()
: type("Wrong Animal")
{
    std::cout << "a WrongAnimal has been built" 
              << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
: type(ref.type)
{
    std::cout << "a WrongAnimal been built" 
              << std::endl;
}

WrongAnimal::~WrongAnimal()
{
   std::cout << "a WrongAnimal has been destroyed" 
             << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Wronganimal sound" << std::endl;
}

const std::string WrongAnimal::getType() const
{
    return (type);
}

//////////////////////////////////
////////   CLASS :  WrongCat  ////
/////////////////////////////////


WrongCat::WrongCat()
: WrongAnimal()
{
    type = "WrongCat";
    std::cout << "a WrongCat has been built" 
              << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}