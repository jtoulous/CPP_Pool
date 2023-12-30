#include "replace.hpp"
#include <string>

variables::variables(char *arg_1, char *arg_2, char *arg_3)
:file_name(arg_1), s1(arg_2), s2(arg_3)
{}

void    variables::errorz()
{
    std::string outfile_name;

    if (file_name.empty())
        exit_error("first argument is empty");
    if (s1.empty())
        exit_error("second argument is empty");
    if (s2.empty())
        exit_error("third argument is empty");

    if (s1.compare(s2) == 0)
        exit_error("its the same occurence");

    infile.open(file_name.c_str());
    if (!infile.is_open())
        exit_error("problem opening the infile");
    
    outfile_name = file_name + ".replace";
    outfile.open(outfile_name.c_str());
    if (!outfile.is_open())
    {    
        infile.close();
        exit_error("problem opening outfile");
    }
}

void    variables::convert()
{
    char    ch;
    std::string to_comp;
    long unsigned int     z = 0;

    while (infile.get(ch))
    {
        if (ch == s1[z])
        {
            to_comp.push_back(ch);
            while (z < s1.size() - 1)
            {
                infile.get(ch);
                to_comp.push_back(ch);
                z++;
            }
            if (s1.compare(to_comp) == 0)              
                result = result + s2;
            else 
                result = result + to_comp;
            to_comp.clear();
            z = 0;
        }
        else
            result.push_back(ch);
    }
    outfile << result;
    infile.close();
    outfile.close();
}