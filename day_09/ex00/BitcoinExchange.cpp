#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(int argc, char **argv)
{
    String  buffer;
    String  key;
    double  value;

    if (argc != 2)
        throw(Xception("incorrect arguments"));
    
    input.open("data.csv");
    if (!input.is_open())
        throw(Xception("problem while opening the DataBase"));
    Toolbox::skipLine(input);
    
    while (buffer.getline(input))
    {
        if (buffer[0] != '\0')
        {    
            try
            {
                checkFormat(buffer, ',');
                key = buffer.substr(0, buffer.find(','));
                value = strtod(buffer.substr(buffer.find(',') + 1, buffer.size()).c_str(), NULL);
                dataBase[key] = value;
            }
            catch (Xception &e)
            {
                throw (Xception("problem in the Database: " + buffer));
            }
        }
    }
    input.close();
    
    input.open(argv[1]);
    if (!input.is_open())
        throw (Xception("problem opening input file"));
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
    (void)ref;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
    (void)ref;
    return (*this);
}

void    BitcoinExchange::valueFinder(String &buffer)
{
    try
    {
        preCheck(buffer);
        buffer -= " ";
        if (buffer.size() == 0)
            return ;
        checkFormat(buffer, '|');
        findVal(buffer);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl; 
    }
}

void    BitcoinExchange::findVal(String &buffer)
{
    String  key(buffer.substr(0, buffer.find('|')));
    double  val = strtod(buffer.substr(buffer.find('|') + 1, buffer.size()).c_str(), NULL);
    std::map<String, double>::iterator  ite;

    std::cout << std::setprecision(10);
    ite = dataBase.find(key);
    if (ite != dataBase.end())
        std::cout << key << " => " << val << " = " << val * ite->second << std::endl;
    else
        find_closest_val(buffer);
}

void    BitcoinExchange::find_closest_val(String &buffer)
{
    std::map<String, double>::iterator  ite = dataBase.begin();
    double                              val = strtod(buffer.substr(buffer.find('|') + 1, buffer.size()).c_str(), NULL);
    int                                 year = atoi(buffer.substr(0, 4).c_str());
    int                                 month = atoi(buffer.substr(5, 7).c_str());
    int                                 day = atoi(buffer.substr(8, 10).c_str());
    int                                 tmp;

    while (1)
    {
        tmp = atoi(ite->first.substr(0, 4).c_str());
        if (tmp == year)
        {
            while (1)
            {
                tmp = atoi(ite->first.substr(5, 7).c_str());
                if (tmp == month)
                {
                    while (1)
                    {
                        tmp = atoi(ite->first.substr(8, 10).c_str());
                        if (tmp == day)
                        {
                            std::cout << buffer.substr(0, buffer.find('|')) << " => " << val << " = " << val * ite->second << std::endl;
                            return ;
                        }
                        else if(tmp > day)
                        {
                            ite--;
                            std::cout << buffer.substr(0, buffer.find('|')) << " => " << val << " = " << val * ite->second << std::endl;
                            return ;
                        }
                        ite++;
                    }
                }
                ite++;
            }
        }
        ite++;
    }
}

void    BitcoinExchange::preCheck(String buffer)
{
    int i = 0;
    int spaceNb = 0;
    int last = buffer.size() - 1;

    while (buffer[last] == ' ')
        last--;

    while (buffer[i] == ' ')
        i++;

    while (i < last)
    {
        for (; buffer[i] != ' ' && i < last; i++)
            ;
        if (buffer[i] == ' ' && spaceNb == 0)
        {    
            if (buffer[i + 1] != '|' || buffer[i - 1] == ' ')
                throw (Xception("Error: bad input '", (char *)buffer.c_str(), "'"));
            spaceNb++;
        }
        else if (buffer[i] == ' ' && spaceNb == 1)
        {
            if (buffer[i - 1] != '|' || buffer[i + 1] == ' ')
                throw (Xception("Error: bad input '", (char *)buffer.c_str(), "'"));
            spaceNb++;
        }
        else if (buffer[i] == ' ')
            spaceNb++;
        i++;
    }
    if (spaceNb > 2)
        throw (Xception("Error: bad input '", (char *)buffer.c_str(), "'"));
}

void    BitcoinExchange::checkFormat(String &buffer, char sep)
{
    String  date;
    String  value;
    String  tmp;
    double  test;

    if (buffer.X_occur(sep) == 0)
        throw (Xception("Error: '" + buffer + "' two values needed, ex: 'date | value'"));

    if (buffer.X_occur(sep) > 1)
        throw (Xception("Error: '" + buffer + "' only two values needed, ex: 'date | value'"));

    if (buffer.X_occur('.') > 1)
        throw (Xception("Error: Format problem on '.'"));

    if (buffer.X_occur('-') < 2 || buffer.X_occur('-') > 3)
        throw (Xception("Error: Format problem on '-'"));

    for (int z = 0; buffer[z]; z++)
        if (!isdigit(buffer[z]) && buffer[z] != '-' && buffer[z] != sep && buffer[z] != '.')
        {    
            tmp = "Error: unauthorized character => ";
            tmp.push_back(buffer[z]);
            throw (Xception(tmp));
        }

    date = buffer.substr(0, buffer.find(sep));
    value = buffer.substr(buffer.find(sep) + 1, buffer.size());

    if (value.size() == 0)
        throw (Xception("Error: no value"));

    dateFormat(date);

    if (value.find('.') != NPOS && value[value.find('.') + 1] == '\0')
        throw (Xception("Error: incorrect value format => " + value));
    if (strtod(value.c_str(), NULL) == HUGE_VAL || strtod(value.c_str(), NULL) == -HUGE_VAL)
        throw (Xception("Error: value is too big"));
    test = strtod(value.c_str(), NULL);
    if (sep == '|' && test > 1000)
        throw (Xception("Error: value is too big"));
    else if (sep == ',' && test > 2147483647)
        throw (Xception("Error: value is too big"));
    if (test < 0)
    {
        tmp = "Error: '" + value + "' not a positive value";
        throw (Xception(tmp));
    }
}

void    BitcoinExchange::dateFormat(String &date)
{
    int  year;
    int  month;
    int  day;

    if (date.find('-') != 4
        || date.find('-', 5) != 7)
        throw (Xception("Error: Incorrect date format => " + date));

    year = atoi(date.substr(0, 4).c_str());
    month = atoi(date.substr(5, 7).c_str());
    day = atoi(date.substr(8, 10).c_str());

    if (month > 12)
        throw (Xception("Error: month can't be superior to 12"));
    if (month < 1)
        throw (Xception("Error: month can't be inferior to 1"));

    if (day > 31)
        throw (Xception("Error: day can't be superior to 31"));
    if (day < 1)
        throw (Xception("Error: days can't be inferior to 1"));

    if (year < 2009)
        throw (Xception("Error: BTC did not exist yet"));
    if (year == 2009)
        if (month == 1)
            if (day < 2)
                throw (Xception("Error: BTC did not exist yet"));

    if (year > 2022)
        throw (Xception("Error: last entry in Database: 2022-03-29"));
    if (year == 2022)
        if (month >= 03)
            if (day > 29)
                throw (Xception("Error: last entry in Database: 2022-03-29"));
}