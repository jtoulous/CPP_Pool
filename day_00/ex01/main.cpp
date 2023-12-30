#include "Phonebook.hpp"
#include <string>

int main()
{
    Phonebook   the_book;
    std::string input;

    while (std::cin.good())
    {
        std::cout << "\nTell me daddy" 
                  << std::endl;
        std::getline(std::cin, input);
        
        if (input.compare("ADD") == 0)
            the_book.add();
        
        else if (input.compare("SEARCH") == 0)
            the_book.search();
        
        else if (input.compare("EXIT") == 0)
            return (0);
        
        else
            std::cout << "ADD, SEARCH OR EXIT\n" << std::endl;
    }
    return (0);
}