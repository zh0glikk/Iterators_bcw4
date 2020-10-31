#ifndef FactorialIterator_hpp
#define FactorialIterator_hpp

template <class Type>
class FactorialIterator {
private:
    Type current;
    int index;
    int size;
public:
    FactorialIterator(int size);
    
    void next();
    Type get();
    
    bool over();
};

#endif /* FactorialIterator_hpp */
