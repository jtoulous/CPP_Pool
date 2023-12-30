#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

class Contact
{
    public:
                void    add();
                void    partial_print(int nb);
                void    full_print();

    private:
                std::string name;
                std::string last_name;
                std::string nickname;
                std::string phone;
                std::string darkest_secret;
};

class Phonebook
{
        public:
                Phonebook();
                void    add();
                void    search();

        private:
                Contact repertory[8];
                int     latest_entry;
};

#endif