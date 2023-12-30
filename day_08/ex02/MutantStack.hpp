#pragma once

#include <stack>
#include <deque>


template <typename T, typename container = std::deque<T> >
class MutantStack: public std::stack<T, container>
{
        public:
                MutantStack();
                MutantStack(const MutantStack<T, container> &ref);
                ~MutantStack();

                MutantStack<T, container>       &operator=(const MutantStack<T, container> &ref);

                
                typedef typename std::stack<T>::container_type::iterator iterator;
                
                iterator begin(void)
                {
                        return (this->c.begin());
                }

                iterator cbegin(void)
                {
                        return (this->c.cbegin());
                }

                iterator rbegin(void)
                {
                        return (this->c.rbegin());
                }
                
                iterator crbegin(void)
                {
                        return (this->c.crbegin());
                }
                
                iterator end(void)
                {
                        return (this->c.end());
                }
                
                iterator cend(void)
                {
                        return (this->c.cend());
                }
                
                iterator rend(void)
                {
                        return (this->c.rend());
                }

                iterator crend(void)
                {
                        return (this->c.crend());
                }
};

#include "MutantStack.tpp"