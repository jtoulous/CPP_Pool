#include "Harl.hpp"

Harl::Harl()
{}

void Harl::complain(std::string level)
{
    static void (Harl::*fonctions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int z = 0;

    while (z < 4)
    {
        if (level == lvls[z])
            (this->*fonctions[z])();
        z++;
    }
}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
              << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money."
              << "You didn't put enough bacon in my burger ! "
              << "If you did, I wouldn't be asking for more !"
              << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I’ve been coming for years whereas you started working here since last month."
              << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable ! I want to speak to the manager now."
              << std::endl;
}