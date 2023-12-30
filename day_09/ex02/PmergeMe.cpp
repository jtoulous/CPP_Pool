#include "PmergeMe.hpp"

template <typename container, typename container2>
void    PmergeMe<container, container2>::errorz(int argc, char **argv, container &list)
{
    if (argc < 2)
        throw (Xception("Error: at least one argument required"));
    
    for (int z = 1; argv[z]; z++)
    {
        double  test;

        for (int y = 0; argv[z][y]; y++)
        {
            if (!isdigit(argv[z][y]))
                throw (Xception("Error: only digits required: '", argv[z], "'"));
        }
        
        if (strtod(argv[z], NULL) == HUGE_VAL)
            throw (Xception("Error: int overflow: ", argv[z]));
        
        test = strtod(argv[z], NULL);
        if (test > INT_MAX)
            throw (Xception("Error: int overflow: ", argv[z]));
        list.push_back(atoi(argv[z]));
    }
}

template <typename container, typename container2>
void    PmergeMe<container, container2>::sort(container &list)
{
    container2          pairs;
    int                 oddVal = -1;
    int                 done = 0;

    if (list.size() == 1)
        return ;

    if (list.size() % 2 != 0)
    {
        oddVal = list.back();
        list.pop_back();
    }

    initPairs(list, pairs);
    
    list.clear();
    list.push_back(pairs[0].small);
    for (typename container2::iterator ite = pairs.begin(); ite != pairs.end(); ite++)
        list.push_back(ite->big);

    while (done == 0 && pairs.size() != 1)
    {
        int begin = jacobsthal("begin", pairs.size(), &done);
        int end = jacobsthal("end", pairs.size(), &done);
        for (int i = begin; i > end; i--)
        {
            int pos;

            pos = binarySearch(pairs[i].big, pairs[i].small, list);
            list.insert(list.begin() + pos, pairs[i].small);
        }
    }
    jacobsthal("reset", 0, NULL);
    insertOddval(list, oddVal);
}

template <typename container, typename container2>
int PmergeMe<container, container2>::jacobsthal(String opt, int size, int *done)
{
    static int  loop = 1;
    static int  pos = 0;
    static int  n1 = 0;
    static int  n2 = 0;
    int         n = (2 * n2) + n1;
    int         tmp;

    if (opt == "reset")
    {
        pos = 0;
        n1 = 0;
        n2 = 0;
        loop = 1;
    }
    
    else if (opt == "begin")
    {
        if (loop == 1)
        {
            if (size <= 2)
                n1 = 1;
            else    
                n1 = 2;
            loop++;
            return (n1);
        }
        if (pos + n >= size)
        {
            *done = 1;
            return (size - 1);
        }
        n2 = n1;
        n1 = n;
        return (pos + n1);
    }

    else if (opt == "end")
    {
        tmp = pos;
        pos += n1;
        return (tmp);
    }

    return (0);
}

template <typename container, typename container2>
void    PmergeMe<container, container2>::initPairs(container &list, container2 &pairs)
{
    int Idx;
    int prevIdx = 0;
    int prevVal = 0;
    static int recursivity = 0;

    if (recursivity == 0)
    {
        recursivity = 1;
        initPairs(list, pairs);
        return ;
    }
    for (int z = 0; z < (int)list.size(); z += 2)
    {
        Pair    tmp(list[z], list[z + 1]);

        if (tmp.big > prevVal)
            Idx = prevIdx;
        else
            Idx = 0;
        
        while (Idx < (int)pairs.size() && pairs[Idx].big < tmp.big)
            Idx++;

        prevVal = tmp.big;
        prevIdx = Idx;
        if (pairs.size() == 0)
            pairs.push_back(tmp);
        else
            pairs.insert(pairs.begin() + Idx, tmp);
    }
}

template <typename container, typename container2>
int PmergeMe<container, container2>::binarySearch(int big, int small, container &list)
{
    int bigPos = 0;
    int limD;
    int limG;

    if (small <= list[0])
        return (0);
    
    if (small >= list.back())
        return (list.size());

    for (typename container::iterator ite = list.begin(); *ite != big && ite != list.end() - 1; ite++)
        bigPos++;

    if (small <= list[bigPos] && small >= list[bigPos])
        return (bigPos);

    limD = bigPos;
    limG = bigPos;
    while (1)
    {
        if (small <= list[limG] && small >= list[limG - 1])
            return (limG);
        if (small < list[limG])
        {
            limD = limG;
            limG = limG / 2;
        }
        else
            limG += (limD - limG) / 2;
    }
    return (0);
}

template <typename container, typename container2>
void    PmergeMe<container, container2>::insertOddval(container &list, int oddVal)
{
    int pos;

    if (oddVal == -1)
        return ;
    
    pos = binarySearch(oddVal + 1, oddVal, list);
    list.insert(list.begin() + pos, oddVal);
}