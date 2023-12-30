#include "Harl.hpp"

static int  evaluate_madness(std::string tolerance)
{
    int z = 0;
    std::string lvls[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (z < 4)
    {
        if (tolerance.compare(lvls[z]) == 0)
            return (z + 1);
        z++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    Harl    harl;
    int     mad_lvl;    

    if (argc > 2)
        return (0);

    if (argc == 1)
        mad_lvl = 1;
    else    
        mad_lvl = evaluate_madness(argv[1]);
    
    switch(mad_lvl)
    {
        case 0:
                std::cout << "[ Probably complaining about insignificant problems ]"
                          << std::endl;
                break;
        case 1:
                harl.complain("DEBUG");
                __attribute__((fallthrough));
                
        case 2:
                harl.complain("INFO");
                __attribute__((fallthrough));

        case 3:
                harl.complain("WARNING");
                __attribute__((fallthrough));

        case 4:
                harl.complain("ERROR");
    }
    return (0);
}