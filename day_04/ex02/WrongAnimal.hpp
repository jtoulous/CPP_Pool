#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "iostream"
# include "Animal.hpp"

class WrongAnimal
{
    public:
            WrongAnimal();
            WrongAnimal(const WrongAnimal &ref);
            ~WrongAnimal();
            
            WrongAnimal &operator=(WrongAnimal &ref);

            void        makeSound() const;
            const std::string getType() const;
    
    protected:
            std::string type;
};

class WrongCat : public WrongAnimal
{
    public:
            WrongCat();
            WrongCat(const WrongCat &ref);
            ~WrongCat();

            WrongCat    &operator=(const WrongCat &ref);
            
            void    makeSound() const;
};

#endif