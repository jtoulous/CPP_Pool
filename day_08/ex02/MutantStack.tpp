#include "MutantStack.hpp"

template <typename T, typename container>
MutantStack<T, container>::MutantStack()
{}

template <typename T, typename container>
MutantStack<T, container>::MutantStack(const MutantStack<T, container> &ref)
{
    *this = ref;
}

template <typename T, typename container>
MutantStack<T, container>::~MutantStack()
{}

template <typename T, typename container>
MutantStack<T, container> &MutantStack<T, container>::operator=(const MutantStack<T, container> &ref)
{
    std::stack<T>::operator=(ref);
}