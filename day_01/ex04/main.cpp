#include "replace.hpp"

void    exit_error(const char *err_msg)
{
    std::cout << err_msg << std::endl;
    exit (69);
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return (0);
    
    variables varz(argv[1], argv[2], argv[3]);

    varz.errorz();
    varz.convert();
    return (0);
}