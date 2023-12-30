#include "iter.hpp"

#include <iostream>

int main(void)
{
    //int useless = 0;
    //addOne(useless);

    int     tab[] = {1, 1, 1, 1, 1};
    char    tab2[] = {'a', 'a', 'a', 'a', 'a'};
    double    tab3[] = {1.5, 1.5, 1.5, 1.5, 1.5};
    float    tab4[] = {1.5, 1.5, 1.5, 1.5, 1.5};

    iter(tab, 5, addOne<int>);
    for (int z = 0; z < 5; z++)
        std::cout << tab[z] << std::endl;
    
    std::cout << "\n===================\n" << std::endl;
    
    iter(tab2, 5, addOne<char>);
    for (int z = 0; z < 5; z++)
        std::cout << tab2[z] << std::endl;
    
    std::cout << "\n===================\n" << std::endl;
    
    iter(tab3, 5, addOne<double>);
    for (int z = 0; z < 5; z++)
        std::cout << tab3[z] << std::endl;
        
    std::cout << "\n===================\n" << std::endl;
    
    iter(tab4, 5, addOne<float>);
    for (int z = 0; z < 5; z++)
        std::cout << tab4[z] << std::endl;
    
    return (0);
}