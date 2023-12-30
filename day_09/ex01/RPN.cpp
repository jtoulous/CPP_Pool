#include "RPN.hpp"

void    RPN::inputCheck(String &input)
{
    int digitCount = 0;
    int operatorCount = 0;

    for (int z = 0; input[z]; z++)
    {
        if (!isdigit(input[z]) && !isAllowed(input[z]))
            throw (Xception("Error: '", input[z], "' not authorized"));
        
        if (isdigit(input[z]) && isdigit(input[z + 1]))
            throw (Xception("Error: only nums inferior to 10 accepted"));
        
        if (isdigit(input[z]))
            digitCount++;

        if (isAllowed(input[z]) && input[z] != ' ')
        {
            if (digitCount < 2)
                throw (Xception("Error: operation needs to start with at least 2 digits"));
            else 
                operatorCount++;
        }
    }
    if (digitCount != operatorCount + 1)
        throw (Xception("Error: incorrect amount of operators"));
}

void    RPN::printRes(String &input)
{
    stack<double>  stck;
    String         tmp;

    input -= " ";
    for (int z = 0; input[z]; z++)
    {
        if (isdigit(input[z]))
        {
            tmp.push_back(input[z]);
            stck.push(strtod(tmp.c_str(), NULL));
            tmp.clear();
        }
        if (!isdigit(input[z]))
            applyOperator(stck, input[z]);
    }
    std::cout << stck.top() << std::endl;
}

void    RPN::applyOperator(stack<double> &stck, char ope)
{
    double res;

    res = stck.top();
    stck.pop();
    
    if (ope == '+')
        res = stck.top() + res;
    else if (ope == '-')
        res = stck.top() - res;
    else if (ope == '*')
        res = stck.top() * res;
    else if (ope == '/')
    {    
        if (res == 0)
            throw (Xception("Error: no div by 0"));
        res = stck.top() / res;
    }
    stck.pop();
    stck.push(res);
}

bool    RPN::isAllowed(char ch)
{
    if (ch != ' ' && ch != '-' && ch != '+'
        && ch != '*' && ch != '/')
        return (false);
    return (true);
}




//////////////////////////////////////////
//           Private                    //
//////////////////////////////////////////                           

RPN::RPN()
{}

RPN::RPN(const RPN &ref)
{
    (void)ref;
}

RPN::~RPN()
{}

RPN &RPN::operator=(const RPN &ref)
{
    (void)ref;
    return (*this);
}