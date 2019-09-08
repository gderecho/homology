#include <catch2/catch.hpp>
#include <z.h>

using namespace homology;


TEST_CASE("Unary + test 1", "[z]")
{
    Z<64> z{101};
    REQUIRE(z == +z);
    REQUIRE(+z == 101);
}

TEST_CASE("Unary + test 2", "[z]")
{
    Z<64> z{101};
    REQUIRE(z == +z);
    REQUIRE(+z == 101);
}

