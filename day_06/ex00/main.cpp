#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        String to_conv(argv[1]);
        ScalarConverter::convert(to_conv);
    }
    else
        std::cout << "one argument required" << std::endl;
    return (0);
}