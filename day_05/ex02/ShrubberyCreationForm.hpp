#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm: public AForm
{
  public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string in_target);
        ShrubberyCreationForm(const ShrubberyCreationForm &ref);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);

        const std::string &getTarget();

  private:
        const std::string target;
        void  execution() const;
};