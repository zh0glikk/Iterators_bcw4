#include "catch.hpp"
#include "../Factorial/FactorialIterator.hpp"

TEST_CASE("FactorialIterator test", "[Factorial]") {
    FactorialIterator<int>* it = new FactorialIterator<int>(5);
    
    SECTION("Constuctor") {
        REQUIRE(it->get() == 1);
    }
    
    SECTION("1") {
        it->next();
        REQUIRE(it->get() == 1);
    }
    
    SECTION("2") {
        it->next();
        it->next();
        REQUIRE(it->get() == 2);
    }
    
    SECTION("3") {
        it->next();
        it->next();
        it->next();
        REQUIRE(it->get() == 6);
    }
}
