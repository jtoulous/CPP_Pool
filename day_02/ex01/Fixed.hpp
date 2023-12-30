#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
    public:
            Fixed();
            Fixed(const Fixed &to_copy);
            Fixed(const int to_conv);
            Fixed(const float to_conv);
            ~Fixed();
            Fixed        &operator=(const Fixed &to_affect);
            int          getRawBits(void) const;
            void         setRawBits(int const raw);
            float        toFloat() const;
            int          toInt() const;

    private:
            static int  bits;
            int         fixed_nb;

};

float power(float nb, int powa);
std::ostream&   operator<<(std::ostream& os, const Fixed &to_insert);

#endif