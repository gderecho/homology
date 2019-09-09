#include <catch2/catch.hpp>
#include <z.h>
#include <matrix.h>

using namespace homology;

TEST_CASE("Equality test 1","[matrix]")
{
    Matrix<Z<101>> m1{
        {10,2},
        {9,2}
    };

    Matrix<Z<101>> m2{
        {10,2},
        {9,2}
    };

    REQUIRE(m1 == m2);
}

TEST_CASE("Equality test 2","[matrix]")
{
    Matrix<Z<101>> m1{
        {10},
        {9}
    };

    Matrix<Z<101>> m2{
        {10,2},
        {9,2}
    };

    REQUIRE(!(m1 == m2));
}
