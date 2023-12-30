#include "Fixed.hpp"

float power(float nb, int powa)
{
    int z = 0;
    float res = nb;

    while (z < powa - 1)
    {
        res = res * nb;
        z++;
    }
    return (res);
}

int main( void ) 
{

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}