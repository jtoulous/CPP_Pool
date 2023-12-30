#pragma once 

#include "libX.hpp"
#include <stack>
#include <cctype>
#include <cstdlib>

#define stack std::stack

class RPN
{
    public:
            static void         inputCheck(String &input);
            static void         printRes(String &input);

    private:
            RPN();
            RPN(const RPN &ref);
            ~RPN();

            RPN &operator=(const RPN &ref);
            
            static bool isAllowed(char ch);
            static void applyOperator(stack<double> &stck, char ope);
};