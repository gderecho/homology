#include <catch2/catch.hpp>
#include <matrix.h>
#include <z.h>

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

TEST_CASE("Uneaven backwards test", "[matrix]")
{
    Matrix<Z<101>> m {
        {1,10},
        {2,20},
        {3,30},
        {4,40}
    };

    auto it = end(m);
    std::vector<size_t> ivals {10,1};
    std::vector<size_t> jvals {4,3,2,1};
    for(size_t j : jvals) {
        for(size_t i : ivals) {
            --it;
            REQUIRE(*it == i*j);
        }
    }


}

TEST_CASE("Transform test", "[matrix]")
{
    Matrix<Z<11>> m1 {
        {1,1,1},
        {2,2,2},
        {3,3,3},
        {4,4,4}
    };

    Matrix<Z<11>> m2 {
        {1,2,3},
        {1,2,3},
        {2,3,4},
        {3,1,10}
    };

    std::vector<Z<11>> result; // Note 1d array

    std::transform(
            begin(m1),
            end(m1),
            begin(m2),
            std::back_inserter(result),
            [&result](Z<11> a, Z<11> b){return (a+b);}
            );

    Matrix<Z<11>> sum {m1+m2};
    auto it1 {begin(sum)};
    auto it2 {begin(result)};
    for(; it1 != end(sum) && it2 != end(result); ++it1, ++it2) {
        REQUIRE(*it1 == *it2);
    }

}
