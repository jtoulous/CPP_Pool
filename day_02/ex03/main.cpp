#include "Fixed.hpp"
#include "Point.hpp"

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

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    Fixed res1;
    Fixed res2;
    Fixed res3;

    res1 = a.vectorial_product(b, point);
    res2 = b.vectorial_product(c, point);
    res3 = c.vectorial_product(a, point);

    if (res1 == 0 || res2 == 0 || res3 == 0)
        return (false);
    if (res1 > 0)
    {
        if (res2 <= 0 || res3 <= 0)
            return (false);
    }
    if (res1 < 0)
    {
        if (res2 >= 0 || res3 >= 0)
            return (false);
    }
    return (true);
}

int main( void ) 
{

    const Point a(3, 3);
    const Point b(5, 5);
    const Point c(6, 2);
    const Point p1(4, 4);
    const Point p2(4.51, 4.36);
    const Point p3(4.37, 2.82);
    const Point p4(5 ,3);
    const Point p5(5.63293, 3.99164);

    if (bsp(a, b, c, p1))
        std::cout << "p1 is in" << std::endl;
    else
        std::cout << "p1 is out" << std::endl;
        
    if (bsp(a, b, c, p2))
        std::cout << "p2 is in" << std::endl;
    else
        std::cout << "p2 is out" << std::endl;

    if (bsp(a, b, c, p3))
        std::cout << "p3 is in" << std::endl;
    else
        std::cout << "p3 is out" << std::endl;

    if (bsp(a, b, c, p4))
        std::cout << "p4 is in" << std::endl;
    else
        std::cout << "p4 is out" << std::endl;

    if (bsp(a, b, c, p5))
        std::cout << "p5 is in" << std::endl;
    else
        std::cout << "p5 is out" << std::endl;

    return (0);
}