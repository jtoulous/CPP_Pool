#ifndef AFORM_HPP
# define AFORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
  public:
          AForm();
          AForm(std::string in_name, int in_SignLvl, int in_ExecLvl);
          AForm(const AForm &ref);
          virtual ~AForm();

          AForm &operator=(const AForm &ref);
          
          bool                        isSigned();
          const std::string           &getName() const;
          const int                   &getSignLvl() const;
          const int                   &getExecLvl() const;
          virtual const std::string   &getTarget() = 0;

          void              beSigned(const Bureaucrat &brc);          
          void              execute(const Bureaucrat &executor) const;
        
          class GradeTooHighException;
          class GradeTooLowException;
          class signature_prob;
          
  protected:
          const std::string name;
          bool              signature;
          const int               SignLvl;
          const int               ExecLvl;
          virtual void      execution() const = 0;

};

std::ostream    &operator<<(std::ostream &os, AForm &to_insert);

class AForm::GradeTooHighException: public std::exception
{
  public: 
          GradeTooHighException(std::string in_msg);
          ~GradeTooHighException() throw();
          const char * what() const throw();
  private:
          std::string msg;
};

class AForm::GradeTooLowException: public std::exception
{
  public: 
          GradeTooLowException(std::string in_msg);
          ~GradeTooLowException() throw();
          const char * what() const throw();
  private:
          std::string msg;
};

class AForm::signature_prob: public std::exception
{
  public: 
          signature_prob(std::string in_msg);
          ~signature_prob() throw();
          const char * what() const throw();
  private:
          std::string msg;
};

#endif