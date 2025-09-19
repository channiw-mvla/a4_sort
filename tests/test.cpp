#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "array_bounds.hpp"
// Testing the array bounds

int single[1] = {4};
TEST_CASE("Testing a single array", "[SingleArray]") {
    REQUIRE(upper_bound_iterative(single, 1, 0) == std_upper_bound(single, 1, 0));//smaller
    REQUIRE(lower_bound_iterative(single, 1, 0) == std_lower_bound(single, 1, 0));//smaller
    REQUIRE(upper_bound_iterative(single, 1, 4) == std_upper_bound(single, 1, 4));//same
    REQUIRE(lower_bound_iterative(single, 1, 4) == std_lower_bound(single, 1, 4));//same
    REQUIRE(upper_bound_iterative(single, 1, 12) == std_upper_bound(single, 1, 12));//greater
    REQUIRE(lower_bound_iterative(single, 1, 12) == std_lower_bound(single, 1, 12));//greater
}
int a[11] = {2,6,8,12,17,23,30,37,38,45,62};
TEST_CASE("Testing a edge cases", "[EdgeCases]") {
    REQUIRE(upper_bound_iterative(single, 11, 23) == std_upper_bound(single, 11, 23));//middle
    REQUIRE(lower_bound_iterative(single, 11, 23) == std_lower_bound(single, 11, 23));//middle
    REQUIRE(upper_bound_iterative(single, 11, 24) == std_upper_bound(single, 11, 24));//middle greater
    REQUIRE(lower_bound_iterative(single, 11, 24) == std_lower_bound(single, 11, 24));//middle greater
    REQUIRE(upper_bound_iterative(single, 11, 22) == std_upper_bound(single, 11, 22));//middle less
    REQUIRE(lower_bound_iterative(single, 11, 22) == std_lower_bound(single, 11, 22));//middle less

    REQUIRE(upper_bound_iterative(single, 11, 2) == std_upper_bound(single, 11, 2));//start 
    REQUIRE(lower_bound_iterative(single, 11, 2) == std_lower_bound(single, 11, 2));//start 
    REQUIRE(upper_bound_iterative(single, 11, 1) == std_upper_bound(single, 11, 1));//start less
    REQUIRE(lower_bound_iterative(single, 11, 1) == std_lower_bound(single, 11, 1));//start less
    REQUIRE(upper_bound_iterative(single, 11, 3) == std_upper_bound(single, 11, 3));//start greater
    REQUIRE(lower_bound_iterative(single, 11, 3) == std_lower_bound(single, 11, 3));//start greater

    REQUIRE(upper_bound_iterative(single, 11, 62) == std_upper_bound(single, 11, 62));//end 
    REQUIRE(lower_bound_iterative(single, 11, 62) == std_lower_bound(single, 11, 62));//end 
    REQUIRE(upper_bound_iterative(single, 11, 61) == std_upper_bound(single, 11, 61));//end less
    REQUIRE(lower_bound_iterative(single, 11, 61) == std_lower_bound(single, 11, 61));//end less
    REQUIRE(upper_bound_iterative(single, 11, 63) == std_upper_bound(single, 11, 63));//end greater
    REQUIRE(lower_bound_iterative(single, 11, 63) == std_lower_bound(single, 11, 63));//end greater
}