#ifndef AriProgIterator_hpp
#define AriProgIterator_hpp

template <class Type>
class AriProgIterator {
private:
    Type current;
    Type step;
    int index;
    int size;
public:
    AriProgIterator(Type first, Type step, int size);
    ~AriProgIterator() = default;
    
    void next();
    Type get();
    
    bool over();
};

#endif /* AriProgIterator_hpp */
