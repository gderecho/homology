#include <catch2/catch.hpp>
#include <z.h>

using namespace homology;


TEST_CASE("* test 1", "[z]")
{
    Z<64> left{1};
    Z<64> right{1};
    REQUIRE(left * right == 1);
}

TEST_CASE("* test 2", "[z]")
{
    Z<64> left{-1};
    Z<64> right{1};
    REQUIRE(left * right == -1);
}

TEST_CASE("* test 3", "[z]")
{
    Z<1> z{1};
    REQUIRE(z * z == z);
}

TEST_CASE("* test 4", "[z]")
{
    Z<16> left{5};
    Z<16> right{7};
    REQUIRE(left * right == 3);
}
