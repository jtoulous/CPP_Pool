#include "BitcoinExchange.hpp"
#include "libX.hpp"

int main(int argc, char **argv)
{
    try
    {
        BitcoinExchange utils(argc, argv);
        String          buffer;
        int             i;

        while (1)
        {
            if (!buffer.getline(utils.input))
                return (69);
            //buffer -= " ";
            //std::cout << buffer << std::endl;
            for (i = 0; buffer[i] == ' '; i++)
                ;
            if (isdigit(buffer[i]))
                break;
        }
        utils.valueFinder(buffer);
        buffer.clear();

        while (buffer.getline(utils.input))
        {
            //buffer -= " ";
            utils.valueFinder(buffer);
            buffer.clear();
        }
    }

    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}