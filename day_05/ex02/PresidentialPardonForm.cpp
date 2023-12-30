#include "PresidentialPardonForm.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential Pardon", 25, 5), target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string in_target)
: AForm("Presidential Pardon", 25, 5), target(in_target)  
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
: AForm(ref), target(ref.target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
    (void)ref;
    return (*this);
}

void  PresidentialPardonForm::execution() const
{
  std::cout << target << " was pardonned by Zaphod Beeblebrox"
            << std::endl;
}

const std::string &PresidentialPardonForm::getTarget()
{
  return (target);
}