#pragma once 

#include <map>
#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "libX.hpp"

#define NPOS std::string::npos

class BitcoinExchange
{
    public:
            BitcoinExchange(int argc, char **argv);
            ~BitcoinExchange();

            void valueFinder(String &buffer);
            std::ifstream               input;
    
    private:
            BitcoinExchange();
            BitcoinExchange(const BitcoinExchange &ref);
            BitcoinExchange &operator=(const BitcoinExchange &ref);
            
            void preCheck(String buffer);
            void checkFormat(String &buffer, char sep);
            void dateFormat(String &date);
            void findVal(String &buffer);
            void find_closest_val(String &buffer);

            std::map<String, double>    dataBase;
};