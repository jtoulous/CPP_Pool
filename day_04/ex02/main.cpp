#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    int             z = 0;
    Animal          **cats_n_dogs;
    const Animal    *dog = new Dog();
    const Animal    *cat = new Cat();
    //Animal          test("cow");

    
    /////////   REQUIRED     ///////////////
    cats_n_dogs = new Animal*[10];
    while (z < 5)
    {    
        cats_n_dogs[z] = new Dog();
        z++;
    }
    while (z < 10)
    {    
        cats_n_dogs[z] = new Cat();
        z++;
    }
    z = -1;
    while (++z < 10)
        cats_n_dogs[z]->makeSound();
    z = -1;
    while (++z < 10)
        delete cats_n_dogs[z];
    delete[] cats_n_dogs;
    //////////////////////////////////////////////
    

    dog->makeSound();
    cat->makeSound();
    std::cout << "dog is a " << dog->getType() << std::endl;
    std::cout << "cat is a " << cat->getType() << std::endl;
    delete (dog);
    delete (cat);

    return (0);
}