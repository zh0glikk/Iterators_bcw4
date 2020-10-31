#include "FileIterator.hpp"

FileIterator::FileIterator(std::string name) {
    this->in.open(name);
    this->index = 1;
    this->current = ' ';
}

void FileIterator::next() {
    in >> this->current;
}

char FileIterator::get() {
    return this->current;
}

