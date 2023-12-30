#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    public:
            Dog();
            Dog(const Dog &to_copy);
            ~Dog();

            Dog &operator=(const Dog &ref);

            void    makeSound() const;
            
    private:        
            Brain   *brain;
};

#endif