#include <catch2/catch.hpp>
#include <z.h>

using namespace homology;

TEST_CASE("Equality test 1","[z]")
{
    REQUIRE(105 == Z<101>(4));
}

TEST_CASE("Equality test 2","[z]")
{
    Z<64> first {67};
    Z<64> second {-61};
    REQUIRE(first == second);
}
