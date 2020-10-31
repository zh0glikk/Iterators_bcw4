#include "catch.hpp"
#include "../GeoProg/GeoProgIterator.hpp"

TEST_CASE("GeoProgIterator test", "[GeoProgIterator]") {
    GeoProgIterator<double>* it = new GeoProgIterator<double>(1, 0.5, 5);
    
    SECTION("constuctor check") {
        REQUIRE(it->get() == 1);
    }
    SECTION("next() check") {
        it->next();
        REQUIRE(it->get() == 0.5);
    }
    SECTION("over() check") {
        for ( int i = 0; i < 5; i++ ) {
            it->next();
        }
        REQUIRE(it->get() == 0.03125);
        
        it->next();
        REQUIRE(it->get() == 0.03125);
        
    }
}
