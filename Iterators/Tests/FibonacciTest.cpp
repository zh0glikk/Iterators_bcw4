#include "catch.hpp"
#include "../Fibonacci/FibonacciIterator.hpp"

TEST_CASE("FibonacciIterator test", "[Fibonacci]") {
    FibonacciIterator<int>* it = new FibonacciIterator<int>(5);
    
    SECTION("constructor"){
        REQUIRE(it->get() == 0);
    }
    
    SECTION("1"){
        it->next();
        REQUIRE(it->get() == 1);
    }
    
    SECTION("2"){
        it->next();
        it->next();
        REQUIRE(it->get() == 1);
    }
    
    SECTION("3"){
        it->next();
        it->next();
        it->next();
        REQUIRE(it->get() == 2);
    }
    SECTION("4"){
        it->next();
        it->next();
        it->next();
        it->next();
        REQUIRE(it->get() == 3);
    }
    SECTION("5"){
        it->next();
        it->next();
        it->next();
        it->next();
        it->next();
        REQUIRE(it->get() == 5);
    }
}
