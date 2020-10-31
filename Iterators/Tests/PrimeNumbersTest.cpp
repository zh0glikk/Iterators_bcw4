#include "catch.hpp"
#include "../PrimeNumbers/PrimeNumbersIterator.hpp"

TEST_CASE("PrimeNumbersIterator test", "[PrimeNumbers]") {
    PrimeNumbersIterator* it = new PrimeNumbersIterator(10);

    SECTION("constructor"){
        REQUIRE(it->get() == 2);
    }
    
    SECTION("next()") {
        it->next();
        REQUIRE(it->get() == 3);
        
        it->next();
        REQUIRE(it->get() == 5);
        
        it->next();
        REQUIRE(it->get() == 7);
        
        it->next();
        REQUIRE(it->get() == 11);
    }
    
    SECTION("prev()") {
        it->next();
        REQUIRE(it->get() == 3);
        
        it->next();
        REQUIRE(it->get() == 5);
        
        it->next();
        REQUIRE(it->get() == 7);
        
        it->next();
        REQUIRE(it->get() == 11);
        
        it->prev();
        REQUIRE(it->get() == 7);

        it->prev();
        REQUIRE(it->get() == 5);

        it->prev();
        REQUIRE(it->get() == 3);
        
        it->prev();
        REQUIRE(it->get() == 2);
    }
    
    SECTION("over()") {
        for ( int i = 0; i < 10; i++ ) {
            it->next();
        }
        
        REQUIRE(it->get() == 31);
        
        it->next();
        
        REQUIRE(it->get() == 31);
    }
    
    SECTION("under()") {
        it->prev();
        
        REQUIRE(it->get() == 2);
    }
}
