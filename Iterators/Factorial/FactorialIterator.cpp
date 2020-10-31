#include "FactorialIterator.hpp"

template <class Type>
FactorialIterator<Type>::FactorialIterator(int size) {
    this->size = size;
    this->index = 0;
    this->current = 1;
}

template <class Type>
void FactorialIterator<Type>::next() {
    if (over()) {
        return;
    }
    this->index += 1;
    this->current *= this->index;
}

template <class Type>
Type FactorialIterator<Type>::get() {
    return this->current;
}

template <class Type>
bool FactorialIterator<Type>::over() {
    return this->index >= this->size;
}

template class FactorialIterator<int>;
