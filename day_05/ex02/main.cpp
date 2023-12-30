#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <exception>

int main()
{
  try 
  {
    PresidentialPardonForm  f1("bob");
    ShrubberyCreationForm   f2("bob");
    RobotomyRequestForm     f3("bob");

    std::cout << "\n==========    Low Rank     ===========\n" << std::endl;

    {
      Bureaucrat  lowRank("Joe", 150);
      Bureaucrat  copy(lowRank);

      std::cout << "after construction:\n" << lowRank << std::endl;
      std::cout << copy << "\n" << std::endl;
      
      lowRank.promote();

      std::cout << "after promotion:\n" << lowRank << std::endl;
      std::cout << copy << "\n" << std::endl;

      copy = lowRank;
      
      std::cout << "after operator=:\n" << lowRank << std::endl;
      std::cout << copy << "\n" << std::endl;
      
      lowRank.signForm(f1);
      lowRank.signForm(f2);
      lowRank.signForm(f3);
      lowRank.executeForm(f1);
      lowRank.executeForm(f2);
      lowRank.executeForm(f3);
    }

    std::cout << "\n\n==========    High Rank     ===========\n" << std::endl;

    {
      Bureaucrat  highRank("Bill", 1);

      std::cout << highRank << std::endl;
      highRank.signForm(f1);
      highRank.signForm(f2);
      highRank.signForm(f3);
      highRank.executeForm(f1);
      highRank.executeForm(f2);
      highRank.executeForm(f3);
    }
  }
  catch (std::exception &e) 
  {
    std::cout << e.what() << std::endl;
  }
  
  return (0);
}