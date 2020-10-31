#ifndef FileIterator_hpp
#define FileIterator_hpp

#include <iostream>
#include <fstream>

class FileIterator {
private:
    std::ifstream in;
    char current;
    int size;
    int index;
public:
    FileIterator(std::string name);
    
    void next();
    char get();
};

#endif /* FileIterator_hpp */
