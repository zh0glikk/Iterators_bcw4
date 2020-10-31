#include "FibonacciIterator.hpp"

template <class Type>
FibonacciIterator<Type>::FibonacciIterator(int size) {
    this->size = size;
    this->index = 0;
    this->current = 1;
    this->prev = 0;
}

template <class Type>
void FibonacciIterator<Type>::next() {
    if (over()) {
        return;
    }
    this->index += 1;
    if ( this->index == 1) {
        return;
    }
    
    Type tmp = this->current;
    this->current += this->prev;
    this->prev = tmp;
}

template <class Type>
Type FibonacciIterator<Type>::get() {
    if ( this->index == 0 ) {
        return 0;
    }
    return this->current;
}

template <class Type>
bool FibonacciIterator<Type>::over() {
    return this->index >= this->size;
}

template class FibonacciIterator<int>;
