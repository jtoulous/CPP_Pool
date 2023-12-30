#include "Bureaucrat.hpp"
#include <exception>

int main()
{
  try
  {
    Bureaucrat  low("low", 150);
    Bureaucrat  high("high", 1);

    try 
    {
      std::cout << "\n\n=======    GRADE TOO LOW    =======\n" << std::endl;
      std::cout << low << std::endl;
      low.promote();
      std::cout << low << std::endl;
      low.demote();
      std::cout << low << std::endl;
      low.demote();
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl; 
    }

    try
    {
      std::cout << "\n\n=======    GRADE TOO HIGH    =======\n" << std::endl;
      std::cout << high << std::endl;
      high.demote();
      std::cout << high << std::endl;
      high.promote();
      std::cout << high << std::endl;
      high.promote();
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
    

    std::cout << "\n\n=======    INSTANCIATION    =======\n" << std::endl;
    Bureaucrat   error("error", 151);
  }

  catch (std::exception &e)
  {
    std::cout << e.what() << "\n" << std::endl;
  }

  return (0);
}