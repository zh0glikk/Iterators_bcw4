#include "GeoProgIterator.hpp"

template <class Type>
GeoProgIterator<Type>::GeoProgIterator(Type first, Type multiplier, int size) : current(first),
    multiplier(multiplier),
    index(0),
    size(size)
    {}

template <class Type>
void GeoProgIterator<Type>::next() {
    if (over()) {
        return;
    }
    this->current *= this->multiplier;
    this->index += 1;
}

template <class Type>
Type GeoProgIterator<Type>::get() {
    return this->current;
}

template <class Type>
bool GeoProgIterator<Type>::over() {
    return this->index >= this->size;
}

template class GeoProgIterator<int>;
template class GeoProgIterator<float>;
template class GeoProgIterator<double>;
