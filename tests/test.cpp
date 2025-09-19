#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "prime.hpp"
// Testing few prime identification

int prime_numbers[100] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};
TEST_CASE("Testing a few prime numbers", "[PrimeNumbers]") {
    for(int num:prime_numbers){
        REQUIRE(isPrimeHalf(num,nullptr));
        REQUIRE(isPrimeSqrt(num,nullptr));
    }
}
//Testing composite numbers
int composite_numbers[74] = {4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30, 32, 33, 34, 35, 36, 38, 39, 40, 42, 44, 45, 46, 48, 49, 50, 51, 52, 54, 55, 56, 57, 58, 60, 62, 63, 64, 65, 66, 68, 69, 70, 72, 74, 75, 76, 77, 78, 80, 81, 82, 84, 85, 86, 87, 88, 90, 91, 92, 93, 94, 95, 96, 98, 99, 100};
TEST_CASE("Testing a few composite numbers", "[CompositeNumbers]") {
    for(int num:composite_numbers){
        REQUIRE(!isPrimeHalf(num,nullptr));
        REQUIRE(!isPrimeSqrt(num,nullptr));
    }
}
// test for few range of prime numbers if both methods are consistent
TEST_CASE("Testing a range of prime numbers", "[PrimeRange]") {
    for(int i = 0; i <= 1000; i++){
        bool opHalf = isPrimeHalf(i,nullptr);
        bool opSqrt =  isPrimeSqrt(i,nullptr);
        REQUIRE(opHalf == opSqrt);
    }
}
// Testing mod operation counts
TEST_CASE("Testing mod operation counts", "[ModOpCount]") {
    bool isPrimeHalf(int n, std::shared_ptr<long long> modOps);
    bool isPrimeSqrt(int n, std::shared_ptr<long long> modOps);
    long long opHalf = countModOps(isPrimeHalf,2,10000);
    long long opSqrt = countModOps(isPrimeSqrt,2,10000);
    REQUIRE(opSqrt <=opHalf);
}
// test edge cases
TEST_CASE("Test edge cases", "[EdgeCase]") {
    REQUIRE(isPrimeHalf(0, nullptr) == false);
    REQUIRE(isPrimeHalf(1, nullptr) == false);
    REQUIRE(isPrimeHalf(2, nullptr) == true);
    REQUIRE(isPrimeSqrt(0, nullptr) == false);
    REQUIRE(isPrimeSqrt(1, nullptr) == false);
    REQUIRE(isPrimeSqrt(2, nullptr) == true);
}