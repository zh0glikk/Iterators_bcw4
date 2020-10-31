#ifndef GeoProgIterator_hpp
#define GeoProgIterator_hpp

template <class Type>
class GeoProgIterator {
private:
    Type current;
    Type multiplier;
    int index;
    int size;
public:
    GeoProgIterator(Type first, Type multiplier, int size);
    ~GeoProgIterator() = default;
    
    void next();
    Type get();
    
    bool over();
    
};

#endif /* GeoProgIterator_hpp */
