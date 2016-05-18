#include "iostream"
#include "catch_with_main.hpp"
#include "vector.hpp"

TEST_CASE("constructor, two parameters"){
        vector v(3,4);
        REQUIRE(v==vector(3,4));
}
TEST_CASE("+ operator"){
        vector v(3,4);
        vector p = v + vector(5,4);
        REQUIRE(p==vector(8,8));
}
TEST_CASE("- operator"){
        vector v(7,5);
        vector p = v - vector(5,4);
        REQUIRE(p==vector(2,1));
}
TEST_CASE("* operator, multiply by integer"){
        vector v(3,4);
        vector p = v * 2;
        REQUIRE(p==vector(6,8));
}
TEST_CASE("+= operator"){
        vector v(3,4);
        v += vector(1,2);
        REQUIRE(v == vector(4,6));
}
TEST_CASE("operator -, no parameters"){
        vector v(3,-4);
        vector p = -v;
        REQUIRE(p == vector(-3,4));
}
TEST_CASE("operator +, no parameters"){
        vector v(3,4);
        vector p = v * +2;
        REQUIRE(p == vector(6,8));
}
TEST_CASE("-= operator "){
        vector v(3,4);
        v-= vector(1,2);
        REQUIRE(v == vector(2,2));
}
TEST_CASE("*= operator , multiply with integer"){
        vector v(3,4);
        v*= 3;
        REQUIRE(v == vector(9,12));
}
TEST_CASE("/ operator, devided by integer"){
        vector v(3,6);
        vector p = v / 3;
        REQUIRE(p == vector(1,2));
}
TEST_CASE("/= operator, devided by integer"){
        vector v(3,6);
        v /= 3;
        REQUIRE(v == vector(1,2));
}
TEST_CASE("* operator, multiply by vector"){
        vector v(3,6);
        vector p = 2 * v;
        REQUIRE(p == vector(6,12));
}

