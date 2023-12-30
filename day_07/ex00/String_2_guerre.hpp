#pragma once

#include <string>

#define NPOS std::string::npos

class   String: public std::string
{
    public:
            String();
            String(const std::string &ref);
            String(const char *ref);
            String(const String &ref);

            String  operator-(const String &sub);
            String  operator-(const std::string &sub);
            String  operator-(const char *sub);
            String  &operator-=(const String &sub);
            String  &operator-=(const std::string &sub);
            String  &operator-=(const char *sub);

            void            pop_back();
            char            &back();
};