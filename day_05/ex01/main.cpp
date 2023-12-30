#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <exception>

int main()
{
  try 
  {
    Bureaucrat  bill("Bill", 145);
    Form  f1("the death sentence", 144, 144);
    
    std::cout << f1 << std::endl;
    std::cout << bill << std::endl;
    bill.signForm(f1);
    bill.promote();
    std::cout << bill << std::endl;
    bill.signForm(f1);
    f1.beSigned(bill);
  }
  catch (std::exception &e) 
  {
    std::cout << e.what() << std::endl;
  }
}