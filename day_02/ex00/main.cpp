#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    
    c = b;
    std::cout << a.getRawBits() << "\n"
              << b.getRawBits() << "\n"
              << c.getRawBits() << std::endl;
    return (0);
}