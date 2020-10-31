#include "catch.hpp"
#include "../AriProg/AriProgIterator.hpp"

TEST_CASE("AriProgIterator check", "[AriProgIterator]") {
    AriProgIterator<int>* it = new AriProgIterator<int>(0, 2, 5);
    
    SECTION("Constructor test") {
        REQUIRE(it->get() == 0);
    }
    SECTION("next test") {
        it->next();
        REQUIRE(it->get() == 2);
    }
    
    SECTION("over test") {
        for ( int i = 0; i < 5; i++) {
            it->next();
        }
        REQUIRE(it->get() == 8);
        
        it->next();
        
        REQUIRE(it->get() == 8);
    }
}
