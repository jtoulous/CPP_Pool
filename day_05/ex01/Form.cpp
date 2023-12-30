#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

Form::Form()
: name("default"), signature(false), SignLvl(150), ExecLvl(150)
{}

Form::Form(std::string in_name, int in_SignLvl, int in_ExecLvl)
: name(in_name), signature(false), SignLvl(in_SignLvl), ExecLvl(in_ExecLvl)
{
  if (in_SignLvl < 1)
    throw GradeTooHighException("Signature lvl for the form is too high");
  if (in_SignLvl > 150)
    throw GradeTooLowException("Signature lvl for the form is too low");
  if (in_ExecLvl < 1)
    throw GradeTooHighException("Execution lvl for the form is too high");
  if (in_ExecLvl > 150)
    throw GradeTooHighException("Execution lvl for the form is too low");
}

Form::Form(const Form &ref)
: name(ref.name), signature(ref.signature), SignLvl(ref.SignLvl), ExecLvl(ref.ExecLvl) 
{}

Form::~Form()
{}

Form  &Form::operator=(const Form &to_affect)
{
  (void)to_affect;
  return (*this);
}

const std::string &Form::getName() const
{
  return (name);
}

bool        Form::isSigned()
{
  return (signature);
}

const int &Form::getSignLvl() const
{
  return (SignLvl);
}

const int &Form::getExecLvl() const 
{
  return (ExecLvl);
}

void   Form::beSigned(const Bureaucrat &brc)
{
  try
  {  
    if (brc.getGrade() > SignLvl)
      throw (Form::GradeTooLowException(""));
  }
  catch (Form::GradeTooLowException &e)
  {
    std::cout << brc.getName() << " is not authorized to sign " << getName() << std::endl;
    return ;
  }
  if (isSigned())
    std::cout << brc.getName() << " couldn't sign " << getName() << ", someone else already signed it" << std::endl;
  else
  {
    signature = true;
    std::cout << brc.getName() << " signed " << getName() << std::endl;
  }
}

//////////////////////////////
//        EXCEPTION         //
//////////////////////////////

Form::GradeTooHighException::GradeTooHighException(std::string in_msg)
: msg(in_msg)
{}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

const char *Form::GradeTooHighException::what() const throw()
{
  return (msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(std::string in_msg)
: msg(in_msg)
{}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

const char *Form::GradeTooLowException::what() const throw()
{
  return (msg.c_str());
}

std::ostream  &operator<<(std::ostream &os, Form &to_insert)
{
        os << to_insert.getName() << "(grade to sign: " << to_insert.getSignLvl() 
           << ", grade to execute: " << to_insert.getExecLvl() << ")";
        return (os); 
}