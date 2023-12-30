#include "IMateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
    materia_info[0] = NULL;
    materia_info[1] = NULL;
    materia_info[2] = NULL;
    materia_info[3] = NULL;
}

MateriaSource::~MateriaSource()
{
    if (materia_info[0] != NULL)
        delete materia_info[0];
    if (materia_info[1] != NULL)
        delete materia_info[1];
    if (materia_info[2] != NULL)
        delete materia_info[2];
    if (materia_info[3] != NULL)
        delete materia_info[3];
}

void MateriaSource::learnMateria(AMateria *to_learn)
{
    int z = 0;

    while (z < 4)
    {
        if (materia_info[z] == NULL)
        {
            materia_info[z] = to_learn;
            return ;
        }
        z++;
    }
    delete to_learn;
    std::cout << "no more space in MateriaSource, create a new MateriaSource" 
              << std::endl;
}

AMateria    *MateriaSource::createMateria(std::string const &type)
{
    int z = 0;

    while (z < 4)
    {
        if (type.compare(materia_info[z]->getType()) == 0)
            return (materia_info[z]->clone());
        z++;
    }
    return (NULL);
}