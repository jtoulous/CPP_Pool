#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy request", 72, 45), target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string in_target)
: AForm("Robotomy request", 72, 45), target(in_target) 
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
: AForm(ref), target(ref.target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
    (void)ref;
    return (*this);
}

const std::string &RobotomyRequestForm::getTarget()
{
  return (target); 
}

void  RobotomyRequestForm::execution() const
{
  int        result;
  static int seed = 0;

  if (seed == 0)
  {
    std::srand(std::time(0));
    seed = 1;
  }
  result = rand();
  std::cout << "BrrrrrrrrrrrrrrrrrrrrrrrZZZZZZZZZZZZZZZZZZZZZZZZZZZZZzzzzzzzzzzzzzzzzzzzzzzzzzzz!"
            << std::endl;
  
  if (result % 2 == 0)
    std::cout << target << " was successfully robotomised!" 
              << std::endl;
  else
    std::cout << "the robotomisation on " << target << " was unsuccessfull"
              << std::endl;
}