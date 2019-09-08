#include <catch2/catch.hpp>
#include <z.h>

using namespace homology;


TEST_CASE("- test 1", "[z]")
{
    Z<64> z{63};
    REQUIRE(z - 2 == 61);
}

TEST_CASE("- test 2", "[z]")
{
    Z<64> z{65};
    REQUIRE(z - 1 == 0);
}

TEST_CASE("- test 3", "[z]")
{
    Z<64> z{1};
    REQUIRE(z - 2 == -1);
}

