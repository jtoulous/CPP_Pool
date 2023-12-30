#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
    int         z = 1;
    std::string tmp;

    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
        return (0);
    }
    while (argv[z])
    {
        tmp = argv[z];
        std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
        std::cout << tmp;
        z++;
    }
    std::cout << std::endl;
    return (0);
}