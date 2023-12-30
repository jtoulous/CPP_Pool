#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat()
: name("default"), grade(1)
{}

Bureaucrat::Bureaucrat(const std::string in_name, int in_grade)
: name(in_name)
{
  if (in_grade > 150)
    throw (Bureaucrat::GradeTooLowException());
  if (in_grade < 1)
    throw (Bureaucrat::GradeTooHighException());
  grade = in_grade;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
: name(ref.name)
{
  if (&ref != this)
    *this = ref; 
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &ref)
{
  if (&ref != this)
    this->grade = ref.grade;
  return (*this);
}

const std::string &Bureaucrat::getName() const
{
  return (name);
}

int Bureaucrat::getGrade() const
{
  return (grade);
}

void  Bureaucrat::promote()
{
  if (grade == 1)
    throw (Bureaucrat::GradeTooHighException());
  grade--;
}

void  Bureaucrat::demote()
{
  if (grade == 150)
    throw (Bureaucrat::GradeTooLowException());
  grade++; 
}

////////////////////////////////
///////   EXCEPTION   //////////
////////////////////////////////

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade Too Low");
}

std::ostream  &operator<<(std::ostream &os, Bureaucrat &to_insert)
{
  os << to_insert.getName() << ", bureaucrat grade " << to_insert.getGrade();
  return (os);
}