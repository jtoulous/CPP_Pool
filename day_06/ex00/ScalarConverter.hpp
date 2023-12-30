#pragma once

#include <limits>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "String_2_guerre.hpp"

#define DBL_MAX std::numeric_limits<double>::max()
#define DBL_MIN std::numeric_limits<double>::min()
#define FLOAT_MAX std::numeric_limits<float>::max()
#define FLOAT_MIN std::numeric_limits<float>::min()
#define INT_MAX std::numeric_limits<int>::max()
#define INT_MIN std::numeric_limits<int>::min()

class ScalarConverter
{
    public: 
            static void convert(String &to_conv);

    private:
            ScalarConverter();
            ScalarConverter(const ScalarConverter &ref);
            ~ScalarConverter();

            ScalarConverter &operator=(ScalarConverter &ref);

            static void    is_char(char ch);
            static void    is_int(String &to_conv);
            static void    is_float(String &to_conv);
            static void    is_double(String &to_conv);
            static int     special_cases(String &to_conv);
            static int     impossible_check(String &to_conv);
            static bool    int_overflowTest(std::string &str);
            static bool    is_double_integer(double test);
            static bool    is_float_integer(float test);
};