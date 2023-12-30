#include "Span.hpp"
#include <ctime>

static int random_int()
{
    static int  seeded = 0;

    if (seeded == 0)
        srand(time(NULL));
    seeded = 1;
    return (rand());
}

int main(void)
{
    {
        try
        {
            Span    container(10000);
            Span    container2(10);
            Span    container3(20);

            for (int z = 0; z < 10000; z++)
                container.addNumber(random_int());

            std::cout << "\nthe size of the vector is " << container.getSize() << std::endl;

            std::cout << "the longest span is " << container.longestSpan()
                      << std::endl;

            std::cout << "the shortest span is " << container.shortestSpan() 
                      << "\n\n=====================\n       addSpan" << std::endl;

            
            for (int z = 0; z < 10; z++)
            {    
                container2.addNumber(random_int());
                container3.addNumber(random_int());
            }
            container3.addSpan(container2.getBegin(), container2.getEnd());
            
            std::cout << "\nthe size of the vector is " << container3.getSize() << " after fonction addSpan" << std::endl;

        }
        catch (Xception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n====================================\n" << std::endl;

    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return 0;
}
