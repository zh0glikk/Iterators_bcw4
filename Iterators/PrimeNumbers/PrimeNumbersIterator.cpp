#include "PrimeNumbersIterator.hpp"

PrimeNumbersIterator::PrimeNumbersIterator(int size) {
    this->current = 2;
    this->index = 0;
    this->size = size;
    this->primeNumbers.push_back(2);
}

bool PrimeNumbersIterator::isPrime(int number) {
    for ( int i = 0; i < this->primeNumbers.size(); i++ ) {
        if ( number %  this->primeNumbers[i] == 0) {
            return false;
        }
    }
    return true;
}




void PrimeNumbersIterator::next() {
    if ( over() ) {
        return;
    }
    
    for ( int tmp = this->current; ; tmp++ ) {
        if ( isPrime(tmp) ) {
            this->current = tmp;
            this->primeNumbers.push_back(tmp);
            this->index += 1;
            break;
        }
    }
}

void PrimeNumbersIterator::prev() {
    if ( under() ) {
        return;
    }
    
    this->primeNumbers.pop_back();
    this->current = primeNumbers[primeNumbers.size()-1];
    this->index -= 1;
}

int PrimeNumbersIterator::get() {
    return this->current;
}

bool PrimeNumbersIterator::over() {
    return this->index >= this->size;
}

bool PrimeNumbersIterator::under() {
    return this->index <= 0;
}
