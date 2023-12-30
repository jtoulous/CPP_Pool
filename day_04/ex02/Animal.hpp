#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal 
{
    public:
            Animal();
            Animal(std::string type);
            Animal(const Animal &to_copy);
            virtual ~Animal();
            
            Animal      &operator=(const Animal &ref);
            
            virtual void        makeSound() const = 0;
            const std::string   &getType() const;

    protected:
                std::string type;
};

#endif