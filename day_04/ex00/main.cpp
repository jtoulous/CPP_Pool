#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    
    {
        std::cout << "///     FIRST MAIN      ///\n" << std::endl;

        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); 
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
    }

    {
        std::cout << "\n\n///     SECOND MAIN      ///\n" << std::endl;
        
        
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); 
        meta->makeSound();
        delete meta;
        delete i;
    }
    return (0);
}
