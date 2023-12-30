#include "ScalarConverter.hpp"

void ScalarConverter::convert(String &to_conv)
{
        if (ScalarConverter::special_cases(to_conv) == 1)
            return ;
        
        if (to_conv.size() != 1 && ScalarConverter::impossible_check(to_conv) == 1)
        {    
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return ;
        }

        else if (to_conv.size() == 1 && (to_conv[0] < '0' || to_conv[0] > '9'))
            ScalarConverter::is_char(to_conv[0]);
        else if (to_conv.find('.') == NPOS)
            ScalarConverter::is_int(to_conv);
        else if (to_conv.find('f') != NPOS)
            ScalarConverter::is_float(to_conv);
        else
            ScalarConverter::is_double(to_conv);
}

////////////////////////////////////////////////////////////////////////////

void    ScalarConverter::is_char(char ch)
{
    if (ch >= 32 && ch <= 126)
        std::cout << "char: '" << ch << "'" << std::endl;
    else if (ch < 32 || ch > 126)
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(ch) << std::endl;
    std::cout << "float: " << static_cast<float>(ch) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
}

/////////////////////////////////////////////////////////////////////////////

void    ScalarConverter::is_int(String &to_conv)
{
    int     in_int;

    try
    {
        if (ScalarConverter::int_overflowTest(to_conv))
            in_int = atoi(to_conv.c_str());
        else   
            throw std::exception();

        if (in_int >= 32 && in_int <= 126)
            std::cout << "char: '" << static_cast<char>(in_int) << "'" << std::endl;
        else if (in_int < 32 || (in_int > 126 && in_int <= 255))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        std::cout << "int: " << in_int << std::endl;
        std::cout << "float: " << static_cast<float>(in_int) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(in_int) << ".0" << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
         
            if (std::strtof(to_conv.c_str(), NULL) == HUGE_VALF || std::strtof(to_conv.c_str(), NULL) == -HUGE_VALF)
            {
                std::cout << "float: impossible" << std::endl;
                if (std::strtod(to_conv.c_str(), NULL) == HUGE_VAL || std::strtod(to_conv.c_str(), NULL) == -HUGE_VAL)
                    std::cout << "double: impossible" << std::endl;
                else
                    std::cout << "double: " << std::strtod(to_conv.c_str(), NULL) << ".0" << std::endl;
            }
            else
            {
                std::cout << "float: " << std::strtof(to_conv.c_str(), NULL) << ".0f" << std::endl;
                std::cout << "double: " << std::strtod(to_conv.c_str(), NULL) << ".0" << std::endl;
            }
    }
}

/////////////////////////////////////////////////////////////////////////

void    ScalarConverter::is_float(String &to_conv)
{
    float    test;
    //double   in_float;
    float   in_float;

    to_conv.pop_back();
    try
    {
        test = std::strtof(to_conv.c_str(), NULL);
        if (test == -HUGE_VALF || test == HUGE_VALF)
            throw std::exception();
        
        in_float = std::strtof(to_conv.c_str(), NULL);

        if (in_float >= 32 && in_float <= 126 && ScalarConverter::is_float_integer(in_float))
            std::cout << "char: '" << static_cast<char>(in_float) << "'" << std::endl;
        else if (in_float < 32 || (in_float > 126 && in_float <= 255))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;


        if (in_float > INT_MAX || in_float < INT_MIN)
            std::cout << "int: impossible" << std::endl;
        else            
            std::cout << "int: " << static_cast<int>(in_float) << std::endl;

        
        if (ScalarConverter::is_float_integer(in_float))
        {    
            std::cout << "float: " << /*static_cast<double>*/in_float << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(in_float) << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << /*static_cast<double>*/in_float << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(in_float) << std::endl;
        }
    }

    catch (std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        if (strtod(to_conv.c_str(), NULL) == HUGE_VAL || strtod(to_conv.c_str(), NULL) == -HUGE_VAL)
            std::cout << "double: impossible" << std::endl;
        else    
        {    
            if (ScalarConverter::is_double_integer(strtod(to_conv.c_str(), NULL)))
                std::cout << "double: " << strtod(to_conv.c_str(), NULL) << ".0" << std::endl;
            else
                std::cout << "double: " << strtod(to_conv.c_str(), NULL) << std::endl;
        
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

void    ScalarConverter::is_double(String &to_conv)
{
    double  in_double;

    try
    {
        in_double = std::strtod(to_conv.c_str(), NULL);

        if (in_double == HUGE_VAL || in_double == -HUGE_VAL)
            throw std::exception();

        if (in_double >= 32 && in_double <= 126 && ScalarConverter::is_double_integer(in_double))
            std::cout << "char: '" << static_cast<char>(in_double) << "'" << std::endl;
        else if (in_double < 32 || (in_double > 126 && in_double <= 255))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;


        if (in_double <= INT_MAX && in_double >= INT_MIN)
            std::cout << "int: " << static_cast<int>(in_double) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

            
        if (in_double <= FLOAT_MAX || in_double >= FLOAT_MIN)    
        {    
            if (ScalarConverter::is_double_integer(in_double))
                std::cout << "float: " << static_cast<float>(in_double) << ".0f" << std::endl;
            else
                std::cout << "float: " << static_cast<float>(in_double) << "f" << std::endl;
        }
        else 
            std::cout << "float: impossible" << std::endl;

        
        if (ScalarConverter::is_double_integer(in_double))
            std::cout << "double: " << in_double << ".0" << std::endl;
        else
            std::cout << "double: " << in_double << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

///////////////////////////////////////////////////////////////////////////////

int    ScalarConverter::special_cases(String &to_conv)
{
    if (to_conv.compare("nanf") == 0 || to_conv.compare("nan") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return (1);
    }
    if (to_conv.compare("+inf") == 0 || to_conv.compare("+inff") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return (1);
    }
    if (to_conv.compare("-inf") == 0 || to_conv.compare("-inff") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return (1);
    }
    return (0);
}

///////////////////////////////////////////////////////////////////////////////

int ScalarConverter::impossible_check(String &to_conv)
{
    String      test;
    int         dot_count = 0;

    to_conv = to_conv - " ";
    test = to_conv;
    if (test.empty())
        return (1);
    if (test.back() == 'f')
        test.pop_back();
    for (int z = 0; test[z]; z++)
    {
        if (z == 0 && (test[z] == '+' || test[z] == '-'))
        {
            if (test[z] == '+')
                test.erase(0, 1);
            else if (test[z] == '-')
                z++;
        }
        if ((test[z] < '0' || test[z] > '9') && test[z] != '.')
            return (1);
        if (test[z] == '.')
            dot_count++;
    }
    if (dot_count > 1)
        return (1);
    return (0);
}

//////////////////////////////////////////////////////////////////////////


bool    ScalarConverter::is_float_integer(float test)
{
    return (floor((double)test) == test);
}

/////////////////////////////////////////////////////////////////////////

bool    ScalarConverter::is_double_integer(double test)
{
    return (floor(test) == test);
}

/////////////////////////////////////////////////////////////////////////

bool    ScalarConverter::int_overflowTest(std::string &str)
{
    double test;

    if (str.size() > 12)
        return (false);
    test = strtod(str.c_str(), NULL);
    if (test > INT_MAX || test < INT_MIN)
        return (false);
    return (true); 
}


///////////////////////////////////////////////////////////////////////////////

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
    (void)ref;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &ref)
{
    return (ref);
}