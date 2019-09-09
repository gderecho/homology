#include <catch2/catch.hpp>
#include <matrix.h>
#include <z.h>

using namespace homology;

TEST_CASE("+ Equality test","[matrix]")
{
    Matrix<int> m1{
        {1,2,9},
        {1,2,2}
    };
    Matrix<int> m2{
        {3,5,2},
        {2,5,6}
    };

    Matrix<int> sum {m1 + m2};
    Matrix<int> to_compare {
        {4,7,11},
        {3,7,8}
    };

    REQUIRE(to_compare == sum);
}

TEST_CASE("+ Equality test with Z","[matrix]")
{
    Matrix<Z<5>> m1{
        {9,1,4},
        {1,1,1},
        {5,2,3}
    };

    Matrix<Z<5>> m2{
        {8,5,2},
        {5,1,2},
        {1,0,-1}
    };

    Matrix<Z<5>> sum {m1 + m2};
    Matrix<Z<5>> to_compare {
        {2,1,1},
        {1,2,3},
        {1,2,2}
    };

    REQUIRE(to_compare == sum);
}
