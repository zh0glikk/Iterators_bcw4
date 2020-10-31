#ifndef FibonacciIterator_hpp
#define FibonacciIterator_hpp

template <class Type>
class FibonacciIterator {
private:
    Type current;
    Type prev;
    int index;
    int size;
public:
    FibonacciIterator(int size);
    
    void next();
    Type get();
    
    bool over();
};

#endif /* FibonacciIterator_hpp */
