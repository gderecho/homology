#include <catch2/catch.hpp>
#include <z.h>

using namespace homology;

TEST_CASE("Declaration test","[z]")
{
    Z<4> z;
    (void)z;
}

TEST_CASE("Initialization test", "[z]")
{
    Z<6> z1001 {1001};
    Z<6> z4 {4};
    Z<6> z3 {3};
    Z<6> z1 {1};
    Z<6> z0 {0};
    Z<6> zm1 {-1};
    Z<6> zm101 {-101};

    (void)z1001;
    (void)z4;
    (void)z3;
    (void)z1;
    (void)z0;
    (void)zm1;
    (void)zm101;
}
