#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
            Brain();
            Brain(Brain &to_copy);
            ~Brain();

            Brain       &operator=( Brain &ref);

    protected:
            std::string ideas[100];
};

#endif