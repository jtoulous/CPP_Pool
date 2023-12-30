#include <iostream> 

int main()
{
    std::string string;
    std::string *stringPTR;
    std::string &stringREF = string;

    string = "HI THIS IS BRAIN";
    stringPTR = &string;
    std::cout << "address of str: " << &string << "\n" << "address in stringPTR: " << stringPTR << "\n" 
              << "address in stringREF: " << &stringREF << std::endl;
    std::cout << "value of str: " << string << "\n" << "value pointed by stringPTR: " << *stringPTR << "\n" 
              << "value of stringREF: " << stringREF << std::endl;          
    return (0);
}