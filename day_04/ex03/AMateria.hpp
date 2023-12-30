#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "Character.hpp"
#include <iostream>

class ICharacter;

class AMateria
{
    public:
            AMateria();
            AMateria(const std::string &in_type);
            AMateria(const AMateria &to_copy);
            virtual ~AMateria();
            
            AMateria &operator=(const AMateria &to_affect);

            const std::string &getType() const;
            virtual AMateria  *clone() const = 0;
            virtual void      use(ICharacter &target);

    protected:
            std::string type;
};

class Ice: public AMateria
{
        public:
                Ice();
                AMateria *clone() const;
                void     use(ICharacter &target);
};

class Cure: public AMateria
{
        public:
                Cure();
                AMateria *clone() const;
                void     use(ICharacter &target);

};

#endif
