#include <catch2/catch.hpp>
#include <z.h>

using namespace homology;


TEST_CASE("Unary - test 1", "[z]")
{
    Z<16> z{8};
    REQUIRE(z == -z);
}

TEST_CASE("Unary - test 2", "[z]")
{
    Z<101> z{101};
    REQUIRE(z == -z);
}

TEST_CASE("Unary - test 3", "[z]")
{
    Z<11> z {1};
    REQUIRE(10 == -z);
}

TEST_CASE("Unary - test 4", "[z]")
{
    Z<1001> z{50};
    REQUIRE(951 == -z);
}
