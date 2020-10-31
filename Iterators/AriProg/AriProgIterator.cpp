#include "AriProgIterator.hpp"

template <class Type>
AriProgIterator<Type>::AriProgIterator(Type first, Type step, int size) : current(first),
    step(step),
    index(1),
    size(size)
    {}

template <class Type>
void AriProgIterator<Type>::next() {
    if (over()) {
        return;
    }
    this->current += this->step;
    this->index += 1;
}

template <class Type>
Type AriProgIterator<Type>::get() {
    return this->current;
}

template <class Type>
bool AriProgIterator<Type>::over() {
    return index >= size;
}

template class AriProgIterator<int>;
template class AriProgIterator<float>;
template class AriProgIterator<double>;
