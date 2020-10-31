#include "catch.hpp"
#include "../FileIterator/FileIterator.hpp"

const std::string fileName("/Users/mac/Desktop/Iterators/Iterators/Tests/task.in");

TEST_CASE("FileIterator check", "[FileIterator]") {
    FileIterator* it = new FileIterator(fileName);
    
    SECTION("Constructor test") {
        REQUIRE(it->get() == ' ');
    }
    
    SECTION("next()") {
        it->next();
        REQUIRE(it->get() == 'a');
        it->next();
        REQUIRE(it->get() == 'b');
        it->next();
        REQUIRE(it->get() == 'c');
        it->next();
        REQUIRE(it->get() == 'd');
        it->next();
        REQUIRE(it->get() == '1');
        it->next();
        REQUIRE(it->get() == '2');
        it->next();
        REQUIRE(it->get() == '3');
    }
}
