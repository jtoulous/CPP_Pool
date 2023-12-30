#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    public:
            Cat();
            Cat(const Cat &to_copy);
            ~Cat();

            Cat &operator=(const Cat &ref);

            void    makeSound() const;

    private:
            Brain   *brain;
};

#endif