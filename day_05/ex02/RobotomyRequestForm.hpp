#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm: public AForm
{
  public:
          RobotomyRequestForm();
          RobotomyRequestForm(std::string in_target);
          RobotomyRequestForm(const RobotomyRequestForm &ref);
          ~RobotomyRequestForm();

          RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);

          const std::string &getTarget();

  private:
          const std::string target;
          void  execution() const;
};