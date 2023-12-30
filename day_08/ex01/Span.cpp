#include "Span.hpp" 


/////////////////////BUILDERS//////////////////////////////////////

Span::Span()
: maxSize(0)
{}

Span::Span(unsigned int in_maxSize)
:maxSize(in_maxSize)
{
    if (in_maxSize > std::numeric_limits<std::vector<int>::size_type>::max())
        throw Xception("too big to be contained in a vector");
}

Span::Span(const Span &ref)
{
    if (this != &ref)
        *this = ref;
}

Span::~Span()
{}

Span &Span::operator=(const Span &ref)
{
    std::vector<int>::const_iterator it;

    if (this != &ref)
    {
        maxSize = ref.maxSize;
        this->vec.clear();

        for(it = ref.vec.begin(); it != ref.vec.end(); it++)
            vec.push_back(*it);
    }
    return (*this);
}

////////////////////////GETTERS/////////////////////////////////


unsigned int    Span::getSize()
{
    return (vec.size());
}

std::vector<int>::iterator  Span::getBegin()
{
    return (vec.begin());
}

std::vector<int>::iterator  Span::getEnd()
{
    return (vec.end());
}

///////////////////////FUNCTIONS/////////////////////////////////////


void    Span::addNumber(int to_add)
{
    if (vec.size() >= maxSize)
        throw Xception("vector's maximum size reached");
    vec.push_back(to_add);
}

int     Span::shortestSpan()
{  
    Span        tmp(*this);
    int         smallest = 2147483647;

    if (vec.size() < 2)
        throw Xception("at least two numbers needed to use fonction shortestSpan");

    for (iterator ite = this->getBegin(); ite != this->getEnd(); ite++)
    {
        for(iterator ite2 = ite + 1; ite2 != this->getEnd(); ite2++)
        {
            if (abs(*ite - *ite2) < smallest)
                smallest = abs(*ite - *ite2);
        }
    }
    return (smallest);
}

int     Span::longestSpan()
{
    int max;
    int min;

    if (vec.size() < 2)
        throw Xception("at least two numbers needed to use fonction shortestSpan");
    
    max = *(max_element(vec.begin(), vec.end()));
    min = *(min_element(vec.begin(), vec.end()));
    return (max - min);
}

void    Span::addSpan(iterator it_begin, iterator it_end)
{
    iterator    tmp;
    int         count = 0; 
    
    for (tmp = it_begin; tmp != it_end; tmp++)
        count++;
    if (count + vec.size() > maxSize)
        throw Xception("Error: range is too big, will surpass max size of the Span");
    vec.insert(vec.end(), it_begin, it_end);
}