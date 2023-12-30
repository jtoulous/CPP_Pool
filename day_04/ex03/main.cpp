#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"

int main()
{
     std::cout << "\n============= FIRST MAIN ==============\n" << std::endl;
     {
        MateriaSource   source;
        Character       bob("bob");
        Character       victim("victim");
        Character       test = victim;


         source.learnMateria(new Ice);
         source.learnMateria(new Cure);
         source.learnMateria(new Cure);
         source.learnMateria(new Cure);
         source.learnMateria(new Cure);

         std::cout << bob.getName()
                   << std::endl;

         bob.equip(source.createMateria("ice"));
         bob.equip(source.createMateria("cure"));
         bob.use(0, victim);
         bob.use(1, victim);
         bob.use(2, victim);
         bob.unequip(2);
         bob.unequip(0);
         victim.equip(source.createMateria("ice"));
         victim.use(0, bob);
         victim.unequip(0);
     }
    
     std::cout << "\n\n============= SECOND MAIN ==============\n" << std::endl;
     {
         IMateriaSource* src = new MateriaSource();
         src->learnMateria(new Ice());
         src->learnMateria(new Cure());
    
         ICharacter* me = new Character("me");
    
         AMateria* tmp;
         tmp = src->createMateria("ice");
         me->equip(tmp);
         tmp = src->createMateria("cure");
         me->equip(tmp);

         ICharacter* bob = new Character("bob");
    
         me->use(0, *bob);
         me->use(1, *bob);

         delete bob;
         delete me;
         delete src;
     }
     std::cout << std::endl;
    return 0;
}