#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "iostream"

class AMateria;

class ICharacter
{
    public:
            virtual ~ICharacter() {}
            virtual std::string const & getName() const = 0;
            virtual void equip(AMateria *m) = 0;
            virtual void unequip(int idx) = 0;
            virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
    public:
            Character(std::string &in_name);
            Character(const char *in_name);
            Character(const Character &to_copy);
            ~Character();
            
            Character &operator=(const Character &to_affect);
            
            const std::string &getName() const;
            void equip(AMateria *m);
            void unequip(int idx);
            void use(int idx, ICharacter &target);

    protected:
            AMateria    *inventory[4];
            std::string name;
            AMateria    **dropped;
            int         nb_dropped;
};

#endif