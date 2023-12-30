#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <exception>
#include <string>

class AForm;

class Bureaucrat
{
  public:
          Bureaucrat();
          Bureaucrat(const std::string in_name, int in_grade);
          Bureaucrat(const Bureaucrat &ref);
          ~Bureaucrat();
          
          Bureaucrat  &operator=(const Bureaucrat &ref);  

          const std::string &getName() const;
          int               getGrade() const;
          
          void              promote();
          void              demote();
          void              signForm(AForm &to_sign);
          void              executeForm(const AForm &form);

          class GradeTooHighException;
          class GradeTooLowException; 

  private:
          const std::string name;
          int               grade;

          bool              nullCheck(const AForm *form);
};

class Bureaucrat::GradeTooHighException: public std::exception
{
  public:
          const char * what() const throw();
};

class Bureaucrat::GradeTooLowException: public std::exception
{
  public:
          const char * what() const throw();
};

std::ostream  &operator<<(std::ostream &os, Bureaucrat &to_insert);

#endif