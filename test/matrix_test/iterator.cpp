#include <catch2/catch.hpp>
#include <matrix.h>

using namespace homology;

TEST_CASE("Iterator foreach test","[matrix]")
{
    Matrix<int> m {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };
    for(const auto i : m) {
        REQUIRE(i == 1);
    }
}

TEST_CASE("Plain loop test","[matrix]")
{
    Matrix<int> m {
        {1,2},
        {3,4}
    };
    auto it = begin(m);
    REQUIRE(*it == 1);
    ++it;
    REQUIRE(*it == 2);
    ++it;
    REQUIRE(*it == 3);
    ++it;
    REQUIRE(*it == 4);
    ++it;
    REQUIRE(it == end(m));
}

TEST_CASE("Backwards test","[matrix]")
{
    Matrix<int> m {
        {1,2},
        {3,4}
    };
    auto it = end(m);
    --it;
    REQUIRE(*it == 4);
    --it;
    REQUIRE(*it == 3);
    --it;
    REQUIRE(*it == 2);
    --it;
    REQUIRE(*it == 1);
    REQUIRE(it == begin(m));
}
