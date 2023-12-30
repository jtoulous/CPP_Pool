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
            bool         operator<(const Fixed &to_comp) const;
            bool         operator>(const Fixed &to_comp) const;
            bool         operator>=(const Fixed &to_comp) const;
            bool         operator<=(const Fixed &to_comp) const;
            bool         operator==(const Fixed &to_comp) const;
            bool         operator!=(const Fixed &to_comp) const;
            Fixed        operator+(const Fixed &to_add);
            Fixed        operator-(const Fixed &to_sub);
            Fixed        operator*(const Fixed &to_mult);
            Fixed        operator/(const Fixed &to_div);
            Fixed        operator++(int to_incre);
            Fixed        &operator++();
            Fixed        operator--(int to_decre);
            Fixed        &operator--();
            int          getRawBits(void) const;
            void         setRawBits(int const raw);
            float        toFloat() const;
            int          toInt() const;
            static Fixed &min(Fixed &a, Fixed &b);
            static const Fixed &min(const Fixed &a, const Fixed &b);
            static Fixed &max(Fixed &a, Fixed &b);
            static const Fixed &max(const Fixed &a, const Fixed &b);

    private:
            static int  bits;
            int         fixed_nb;

};

float power(float nb, int powa);
std::ostream&   operator<<(std::ostream& os, const Fixed &to_insert);

#endif