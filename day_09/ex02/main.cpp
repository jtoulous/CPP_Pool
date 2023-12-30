#include "PmergeMe.hpp"
#include "Pair.hpp"
#include <vector>
#include <deque>
#include <ctime>

#define vector std::vector
#define deque std::deque

static double execTime(std::clock_t start, std::clock_t end)
{
    return (static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000));
}

template <typename container>
static void printList(container &to_print)
{
    for (typename container::iterator ite = to_print.begin(); ite != to_print.end(); ite++)
        std::cout << *ite << " ";
    std::cout << std::endl;
}    

int main(int argc, char **argv)
{
    try
    {
        {
            vector<int>  list;
            std::clock_t        start;
            std::clock_t        end;

            PmergeMe<vector<int>, vector<Pair> >::errorz(argc, argv, list);

            std::cout << "\nBefore: ";
            printList< vector<int> >(list);
            std::cout << std::endl;

            start = std::clock();
            PmergeMe<vector<int>, vector<Pair> >::sort(list);
            end = std::clock();

            std::cout << "After: ";
            printList< vector<int> >(list);
            std::cout << std::endl;

            std::cout << "execution time with vector for " << list.size() << " elements: " 
                      << execTime(start, end) << "us" << std::endl;
        }
       
        {
            deque<int>  list;
            std::clock_t        start;
            std::clock_t        end;
            
            PmergeMe<deque<int>, deque<Pair> >::errorz(argc, argv, list);
            
            start = std::clock();
            PmergeMe<deque<int>, deque<Pair> >::sort(list);
            end = std::clock();

            std::cout << "execution time with deque " << list.size() << " elements: " 
                      << execTime(start, end) << "us" << std::endl;
        }
    }

    catch (Xception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}