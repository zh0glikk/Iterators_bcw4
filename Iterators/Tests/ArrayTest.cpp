#include "catch.hpp"
#include "List.h"

TEST_CASE("ArrayIterator check", "[ArrayIterator]") {
    List<int>* array = new List<int>();

    SECTION("Constructor test") {
        array->push_back(1);
        array->push_back(2);
        array->push_back(3);
        array->push_back(4);
        
        REQUIRE(array->size() == 4);
    }
    
    SECTION("Iterator test") {
        array->push_back(1);
        array->push_back(2);
        array->push_back(3);
        array->push_back(4);
        List<int>::Iterator* it = new List<int>::Iterator(0, array);
        
        REQUIRE(it->get() == 1);
        it->next();
        REQUIRE(it->get() == 2);
        it->next();
        REQUIRE(it->get() == 3);
        it->next();
        REQUIRE(it->get() == 4);
    }
    
    SECTION("over()") {
        array->push_back(1);
        array->push_back(2);
        List<int>::Iterator* it = new List<int>::Iterator(0, array);
        
        REQUIRE(it->get() == 1);
        it->next();
        REQUIRE(it->get() == 2);
        it->next();
        REQUIRE(it->get() == 2);
    }
    
    SECTION("loop") {
        array->push_back(1);
        array->push_back(2);
        array->push_back(3);
        array->push_back(4);
        List<int>::Iterator* it = array->begin();
        List<int>::Iterator* it2 = array->end();
        
        REQUIRE(it->get() == 1);
        REQUIRE(it2->get() == 4);
        
        for ( ; it->isEquals(it2); it->next() );
        
        REQUIRE(it2->get() == 4);
    }
}
