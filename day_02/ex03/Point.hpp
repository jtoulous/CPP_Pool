#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    public:
            Point();
            Point(const float nb1, const float nb2);
            Point(const Point &to_copy);
            ~Point();
            Point   &operator=(const Point &to_affect);
            Fixed   vectorial_product(const Point &vertice, const Point &point) const;
   
    private: 
            const       Fixed x;
            const       Fixed y;
};

#endif