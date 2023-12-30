#include "String_2_guerre.hpp"

///////////////////////////////////////////////////////////
//                      BUILDERS                        //
/////////////////////////////////////////////////////////

String::String()
: std::string()
{}

String::String(const std::string &ref)
: std::string(ref)
{}

String::String(const char *ref)
: std::string(ref)
{}

String::String(const String &ref)
:std::string(ref.c_str())
{}



/////////////////////////////////////////////////////////////
///                     OPERATORZ                          //
/////////////////////////////////////////////////////////////

String    String::operator-(const String &sub)
{
    String  str(*this);
    int     found = 0;

    while (found != -1)
    {
        found = str.find(sub);
        if (found != -1)
            str.erase(found, sub.size());
    }
    return (str);
}

String    String::operator-(const std::string &sub)
{
    String  str(*this);
    int     found = 0;

    while (found != -1)
    {
        found = str.find(sub);
        if (found != -1)
            str.erase(found, sub.size());
    }
    return (str);
}

String    String::operator-(const char *sub)
{
    String  str(*this);
    int     found = 0;
    int     lenght = 0;

    while (sub[lenght])
        lenght++;
    while (found != -1)
    {
        found = str.find(sub);
        if (found != -1)
            str.erase(found, lenght);
    }
    return (str);
}

String  &String::operator-=(const String &sub)
{
    int     found;

    for (found = this->find(sub); found != -1; found = this->find(sub))
        this->erase(found, sub.size());
    return (*this);
}

String  &String::operator-=(const std::string &sub)
{
    int     found;

    for (found = this->find(sub); found != -1; found = this->find(sub))
        this->erase(found, sub.size());
    return (*this);
}

String  &String::operator-=(const char *sub)
{
    int     found;
    int     size = 0;

    while (sub[size])
        size++;
    for (found = this->find(sub); found != -1; found = this->find(sub))
        this->erase(found, size);
    return (*this);
}


///////////////////////////////////////////////////////////////
//                       FONCTIONS                          //
//////////////////////////////////////////////////////////////


void    String::pop_back()
{
    if (!this->empty())    
        erase(this->size() - 1, 1);
}

char    &String::back()
{
    return (at(size() - 1));
}

