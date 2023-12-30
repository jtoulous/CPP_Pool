#include <iostream>
#include "Array.hpp"
#include "String_2_guerre.hpp"

int main(void)
{
    Array<String>   test(6);
    Array<String>   test2;

    int z;
    
    try
    {
        for (z = 0; z <= 6; z++)
        {
            test[z] = "wesh";
            std::cout << test[z] << std::endl;
        }
    }
    catch (Xception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    {
        Array<String>   test3;
        
        test3 = test;
        test2 = test;
    }


    for (z = 0; z < 6; z++)
    {
        test2[z] = "wesh";
        std::cout << test2[z] << std::endl;
    }

    std::cout << test2.size() << std::endl;

    return (0);
}