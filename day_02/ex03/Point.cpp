#include "Point.hpp"

Point::Point()
    : x(0), y(0)
{}

Point::Point(const float nb1, const float nb2)
    : x(nb1), y(nb2)
{}

Point::Point(const Point &to_copy)
    : x(to_copy.x), y(to_copy.y)
{}

Point::~Point()
{
    //std::cout << "destructor" << std::endl;
}

Point &Point::operator=(const Point &to_affect)
{
    if (this != &to_affect)
    {
        (Fixed) x = to_affect.x;
        (Fixed) y = to_affect.y;
    }
    return (*this);
}

Fixed Point::vectorial_product(const Point &vertice, const Point &point) const
{
    Fixed res;

    res = (((Fixed)vertice.x - x) * ((Fixed)point.y - y)) - (((Fixed)vertice.y - y) * ((Fixed)point.x - x));
    return (res);
}