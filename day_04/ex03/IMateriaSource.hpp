#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
  public:
          virtual ~IMateriaSource() {};
          virtual void learnMateria(AMateria *) = 0;
          virtual AMateria *createMateria(std::string const &type) = 0;
};

class MateriaSource: public IMateriaSource
{
  public:
        MateriaSource();
        MateriaSource(const MateriaSource &ref);
        ~MateriaSource();

        MateriaSource   &operator=(const MateriaSource &ref);

        void        learnMateria(AMateria *);
        AMateria    *createMateria(std::string const &type);

  private:
        AMateria *materia_info[4];
};

#endif