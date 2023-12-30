#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int> vec;
    std::vector<int>::iterator   ite;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    
    for (int i = 0; i < 5; i++)
    {
        try
        {
            ite = easyfind(vec, i);
            std::cout << i << " was found"
                      << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << i << " was not found" << std::endl;
        }
    }
    return (0);
}