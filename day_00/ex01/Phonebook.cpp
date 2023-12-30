#include "Phonebook.hpp"
#include "iomanip"

/////////////////////////////////
//        PHONEBOOK            //
/////////////////////////////////

Phonebook::Phonebook()
:latest_entry(0)
{}

void    Phonebook::add()
{
    repertory[latest_entry % 8].add();
    latest_entry++;
}

void    Phonebook::search()
{
    int         z = -1;
    std::string input;

    std::cout << "\n";
    while (++z < 8)
        repertory[z].partial_print(z);
    std::cout << "\nenter the number of the contact you wish to see\n" 
              << std::endl;
    std::getline(std::cin, input);
    
    z = 0;
    while (input[z] == '0')
        z++;
    if (input[z] < '1' || input[z] > '8' || input[z + 1] != '\0')
    {
        std::cout << "contact not found" << std::endl;
        return ;
    }
    repertory[input[z] - '0' - 1].full_print();
}

////////////////////////////////////
//        CONTACT                 //
////////////////////////////////////

void    Contact::full_print()
{
    if (name.empty())
    {
        std::cout << "contact not found\n" << std::endl;
        return ;
    }
    std::cout << name << "\n" << last_name << "\n" << nickname 
              << "\n" << phone << "\n" << darkest_secret 
              << std::endl;
}

void    Contact::partial_print(int nb)
{
    std::string tmp_name;
    std::string tmp_last;
    std::string tmp_nickname;

    if (name.empty())
        return ;

    if (name.length() > 10)
        tmp_name = name.substr(0, 9) + '.';
    else 
        tmp_name = name;

    if (last_name.length() > 10)
        tmp_last = last_name.substr(0, 9) + '.';
    else 
        tmp_last = last_name;
    
    if (nickname.length() > 10)
        tmp_nickname = nickname.substr(0, 9) + '.';
    else 
        tmp_nickname = nickname;
    
    std::cout << std::right << nb + 1 << " | " << std::setw(10) << tmp_name << " | " 
              << std::setw(10) << tmp_last << " | " << std::setw(10) << tmp_nickname
              << std::endl;
}

void    Contact::add()
{
    std::string input;

    std::cout << "\nName?" 
              << std::endl;
    while (input.empty())
        std::getline(std::cin, input);
    name = input;
    input.clear();

    std::cout << "Last name?" 
              << std::endl;
    while (input.empty())
        std::getline(std::cin, input);
    last_name = input;
    input.clear();

    std::cout << "Nickname?" 
              << std::endl;
    while (input.empty())
        std::getline(std::cin, input);
    nickname = input;
    input.clear();

    std::cout << "Telephone number?" 
              << std::endl;
    while (input.empty())
        std::getline(std::cin, input);
    phone = input;
    input.clear();

    std::cout << "Darkest secret?" 
              << std::endl;
    while (input.empty())
        std::getline(std::cin, input);
    darkest_secret = input;
}