#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
  public:
          PresidentialPardonForm();
          PresidentialPardonForm(std::string in_target);
          PresidentialPardonForm(const PresidentialPardonForm &ref);
          ~PresidentialPardonForm();

          PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);

          const std::string &getTarget();

  private:
          const std::string  target;
          void   execution() const;

};