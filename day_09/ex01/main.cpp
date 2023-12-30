#include "RPN.hpp"
#include "libX.hpp"

int main(int argc, char **argv)
{
    String  input;

    try
    {
        if (argc != 2)
            throw (Xception("Error: one argument only"));
        
        input = argv[1];
        
        RPN::inputCheck(input);
        RPN::printRes(input);
    }

    catch (Xception &e)
    {
        std::cout << e.what() << std::endl;
    }
}