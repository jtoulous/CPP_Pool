#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

AForm  *create_PresidentialPardon(std::string &target);
AForm  *create_RobotomyRequest(std::string &target);
AForm  *create_ShrubberyCreation(std::string &target);

class Intern
{
  public:
          Intern();
          Intern(Intern &ref);
          ~Intern();

          Intern  &operator=(const Intern &ref);

          AForm  *makeForm(std::string name, std::string target);
          AForm  *(*createFormz[3])(std::string &);

        // Form  *create_PresidentialPardon(std::string &target);
        // Form  *create_RobotomyRequest(std::string &target);
        // Form  *create_ShrubberyCreation(std::string &target);
};