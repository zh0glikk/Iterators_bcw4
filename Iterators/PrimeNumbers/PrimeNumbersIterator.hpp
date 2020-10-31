#ifndef PrimeNumbersIterator_hpp
#define PrimeNumbersIterator_hpp

#include <vector>

class PrimeNumbersIterator {
private:
    int current;
    int index;
    int size;
    std::vector<int> primeNumbers;
    
    bool isPrime(int number);
public:
    PrimeNumbersIterator(int size);
    
    void next();
    void prev();
    
    int get();
    
    bool over();
    bool under();
};

#endif /* PrimeNumbersIterator_hpp */
