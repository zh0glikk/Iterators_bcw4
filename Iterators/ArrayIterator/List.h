#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>

class OutOfMemoryException {};
class ZeroLenException {};
class WrongIndexExeption {};

template <class Type>
class List {
    private:
        Type* array;
        int capacity;
        double multiplier;
        int current;
    public:
    class Iterator {
        private:
            int index;
            List<Type>* list;
        public:
            Iterator(int index, List<Type>* list);
            void next();
            
            Type get();
        
            bool over();
            bool isEquals(Iterator* other);
    };
    
    public:
        List(int capacity=100, double multiplier=1.05);
        ~List();

        int size() const;
        int max_size() const;

        void erase(int index);
        void insert(Type value, int index);
        int find(Type value) const;
        void push_back(Type value);
        Type pop_back();
        void sort();

        Type operator[](int index) const;
        bool operator==(const List& other) const;
        bool operator!=(const List& other) const;
    
        Iterator* begin();
        Iterator* end();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const List<Type>& list);

template <class Type>
List<Type>::List(int capacity, double multiplier) : capacity(capacity), current(0), multiplier(multiplier) {
    array = (Type*)malloc(capacity*sizeof(Type));

    if ( array == NULL ) {
        throw OutOfMemoryException();
    }
}

template <class Type>
List<Type>::~List() {
    free(array);
}

template <class Type>
int List<Type>::size() const {
    return this->current;
}

template <class Type>
int List<Type>::max_size() const {
    return this->capacity;
}

template <class Type>
void List<Type>::erase(int index) {
    if ( index < 0 || index > current ) {
        throw WrongIndexExeption();
    }

    if ( index != (current - 1) ) {
        for ( int i = index; i < current; i++ ) {
          array[i] = array[i+1];
        }
        current -= 1;
    } else {
        pop_back();
    }
}

template <class Type>
void List<Type>::insert(Type value, int index) {
    if ( index < 0 || index > current ) {
        throw WrongIndexExeption();
    }

    if ( index != (current) ) {
        int newCurrent = current + 1;

        if ( newCurrent > capacity ) {
            int newCapacity = capacity * multiplier;
            Type* newArray = (Type*)realloc(array, newCapacity*sizeof(Type));

            if ( newArray == NULL ) {
                throw OutOfMemoryException();
            }

            capacity = newCapacity;
            array = newArray;
        }

        for ( int i = current; i > index; i-- ) {
            array[i] = array[i-1];
        }
        array[index] = value;
    } else {
        push_back(value);
    }
}

template <class Type>
int List<Type>::find(Type value) const {
    for ( int i = 0; i < current; i++ ) {
        if ( array[i] == current ) {
            return i;
        }
    }
    return -1;
}

template <class Type>
void List<Type>::push_back(Type value) {
    int newCurrent = current + 1;

    if ( newCurrent > capacity ) {
        int newCapacity = capacity * multiplier;
        Type* newArray = (Type*)realloc(array, newCapacity*sizeof(Type));

        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }

        capacity = newCapacity;
        array = newArray;
    }
    array[current] = value;
    current = newCurrent;
}

template <class Type>
Type List<Type>::pop_back() {
    if ( current == 0 ) {
        throw ZeroLenException();
    }
    current -= 1;
    return array[current];
}

template <class Type>
void List<Type>::sort() {
    for ( int i = 1; i < current; i++ ) {
        int tmp = array[i];
        int j = i - 1;

        for ( ; j >= 0 && array[j] > tmp; j-- ) {
            array[j+1] = array[j];
        }
        array[j+1] = tmp;
    }
}

template <class Type>
Type List<Type>::operator[](int index) const {
    if ( index < 0 || index >= this->size() ) {
        throw WrongIndexExeption();
    }
    return this->array[index];
}

template <class Type>
bool List<Type>::operator==(const List& other) const {
    if ( this->current != other.size() ) {
        return false;
    } else {
        for ( int i = 0; i < this->current; i++ ) {
            if ( this->array[i] != other[i] ) {
                return false;
            }
        }
        return true;
    }
}

template <class Type>
bool List<Type>::operator!=(const List& other) const {
    if ( this->current == other.size() ) {
        return false;
    } else {
        for ( int i = 0; i < this->current; i++ ) {
            if ( this->array[i] == other[i] ) {
                return false;
            }
        }
        return true;
    }
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const List<Type>& list) {
    int last = list.size() - 1;

    for ( int i = 0; i < last; i++ ) {
        out << list[i] << " ";
    }
    out << list[last];
    return out;
}

template <class Type>
List<Type>::Iterator::Iterator(int index, List<Type>* list) {
    this->index = index;
    this->list = list;
}

template <class Type>
Type List<Type>::Iterator::get() {
    return this->list->operator[](index);
}

template <class Type>
void List<Type>::Iterator::next() {
    if ( over() ) {
        return;
    }
    this->index += 1;
}

template <class Type>
bool List<Type>::Iterator::over() {
    return this->index >= this->list->size() - 1;
}

template <class Type>
typename List<Type>::Iterator* List<Type>::begin() {
    return new Iterator(0, this);
}

template <class Type>
typename List<Type>::Iterator* List<Type>::end() {
    return new Iterator(this->current - 1, this);
}

template <class Type>
bool List<Type>::Iterator::isEquals(Iterator* other) {
    return this->index != other->index;
}


#endif //LIST_H
