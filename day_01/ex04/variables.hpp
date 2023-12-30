#ifndef ARGZ_HPP
# define ARGZ_HPP

#include "replace.hpp"

class   variables
{
    public:
            variables(char *arg_1, char *arg_2, char *arg_3);
            void    errorz();
            void    convert();

    private:        
            std::string     file_name;
            std::string     s1;
            std::string     s2;
            std::string     result;
            std::ifstream   infile;
            std::ofstream   outfile;
};

void    exit_error(const char *err_msg);

#endif