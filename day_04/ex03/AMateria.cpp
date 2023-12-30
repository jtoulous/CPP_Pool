#include "AMateria.hpp"

////////////////////////////////////////////////////////////
///////////////     DADDY: AMateria      ///////////////////
////////////////////////////////////////////////////////////

AMateria::AMateria(const std::string &in_type)
:type(in_type)
{}

AMateria::AMateria(const AMateria &to_copy)
{
    this->type = to_copy.type;
}

AMateria::~AMateria()
{}

AMateria    &AMateria::operator=(const AMateria &to_affect)
{
    (void)to_affect;
    //if (this != &to_copy) 
    //    type = to_copy.type;
    return (*this);
}

const std::string   &AMateria::getType() const
{
    return (type);
}

////////////////////////////////////////////////
///////////     ICE        /////////////////////
////////////////////////////////////////////////

Ice::Ice()
:AMateria("ice")
{}

AMateria  *Ice::clone() const
{
    AMateria  *clone;

    clone = new Ice();
    return (clone);
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}

void    AMateria::use(ICharacter &target)
{
    (void)target;
}

/////////////////////////////////////////////////
///////////      CURE         ///////////////////
/////////////////////////////////////////////////

Cure::Cure()
:AMateria("cure")
{}

AMateria  *Cure::clone() const
{
    AMateria  *clone;

    clone = new Cure();
    return (clone);
}

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wound *" 
              << std::endl;
}