#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

//////////////////////////////////////
//             BUILDERS             //
//////////////////////////////////////

AForm::AForm()
: name("default"), signature(false), SignLvl(150), ExecLvl(150)
{}

AForm::AForm(std::string in_name, int in_SignLvl, int in_ExecLvl)
: name(in_name), signature(false), SignLvl(in_SignLvl), ExecLvl(in_ExecLvl)
{
  if (in_SignLvl < 1)
    throw AForm::GradeTooHighException("Signature lvl for the form is too high");
  if (in_SignLvl > 150)
    throw AForm::GradeTooLowException("Signature lvl for the form is too low");
  if (in_ExecLvl < 1)
    throw AForm::GradeTooHighException("Execution lvl for the form is too high");
  if (in_ExecLvl > 150)
    throw AForm::GradeTooHighException("Execution lvl for the form is too low");
}

AForm::AForm(const AForm &ref)
: name(ref.name), signature(ref.signature), SignLvl(ref.SignLvl), ExecLvl(ref.ExecLvl) 
{}

AForm::~AForm()
{}

AForm &AForm::operator=(const AForm &ref)
{
  (void)ref;
  return (*this);
}

/////////////////////////////////////
/////         GETTERS      //////////    
/////////////////////////////////////

const std::string &AForm::getName() const
{
  return (name);
}

bool        AForm::isSigned()
{
  return (signature);
}

const int &AForm::getSignLvl() const
{
  return (SignLvl);
}

const int &AForm::getExecLvl() const 
{
  return (ExecLvl);
}

///////////////////////////////////
//           FUNC               ///
///////////////////////////////////


void   AForm::beSigned(const Bureaucrat &brc)
{
  try
  {  
    if (brc.getGrade() > SignLvl)
      throw (AForm::GradeTooLowException(brc.getName() + " is not authorized to sign " + getName()));
  }
  catch (AForm::GradeTooLowException &e)
  {
    std::cout << e.what() << std::endl;
    return ;
  }
  if (isSigned())
    std::cout << brc.getName() << " couldn't sign " << getName() << ", someone else already signed it" << std::endl;
  else
  {
    signature = true;
    std::cout << brc.getName() << " signed the " << getName() << std::endl;
  }
}

void    AForm::execute(const Bureaucrat &executor) const
{
  if (signature == false)
    throw (AForm::signature_prob(getName() + " is not signed, can't be executed"));
  if (executor.getGrade() > ExecLvl)
    throw (AForm::GradeTooLowException(executor.getName() + "'s grade is too low for execution"));
  execution();
}

//////////////////////////////
//        EXCEPTION         //
//////////////////////////////

AForm::GradeTooHighException::GradeTooHighException(std::string in_msg)
: msg(in_msg)
{}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{}

const char *AForm::GradeTooHighException::what() const throw()
{
  return (msg.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(std::string in_msg)
: msg(in_msg)
{}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{}

const char *AForm::GradeTooLowException::what() const throw()
{
  return (msg.c_str());
}

AForm::signature_prob::signature_prob(std::string in_msg)
: msg(in_msg)
{}

AForm::signature_prob::~signature_prob() throw()
{}

const char *AForm::signature_prob::what() const throw()
{
  return (msg.c_str());
}

std::ostream  &operator<<(std::ostream &os, AForm &to_insert)
{
        os << to_insert.getName() << "(grade to sign: " << to_insert.getSignLvl() 
           << ", grade to execute: " << to_insert.getExecLvl() << ")";
        return (os); 
}