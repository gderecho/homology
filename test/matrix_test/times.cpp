#include <catch2/catch.hpp>
#include <vector>
#include <matrix.h>
#include <z.h>

using namespace homology;

std::vector<Matrix<int>> get_3b3_matrices();

std::vector<Matrix<int>> get_3b3_matrices()
{
    constexpr int MAX = 3;
    std::vector<Matrix<int>> result;
    for(int a = 0; a < MAX; ++a) {
    for(int b = 0; b < MAX; ++b) {
    for(int c = 0; c < MAX; ++c) {
    for(int d = 0; d < MAX; ++d) {
    for(int e = 0; e < MAX; ++e) {
    for(int f = 0; f < MAX; ++f) {
    for(int g = 0; g < MAX; ++g) {
    for(int h = 0; h < MAX; ++h) {
    for(int i = 0; i < MAX; ++i) {
        Matrix<int> m = {
            {a,b,c},
            {d,e,f},
            {g,h,i}
        };
        result.emplace_back(std::move(m));
    }}}}}}}}}
    return result;
}


TEST_CASE("* test 1","[matrix]")
{
    for(int i = 0; i < 50; ++i) {
        for(int j = 0; j < 50; ++j) {
            Matrix<int> a {{i}};
            Matrix<int> b {{j}};
            Matrix<int> tocompare {{i * j}};
            REQUIRE(a * b == tocompare);
        }
    }
}

TEST_CASE("* id test","[matrix]")
{
    Matrix<int> id {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    std::vector<Matrix<int>> list = get_3b3_matrices();
    for(auto m : list) {
        REQUIRE(m == m * id);
        REQUIRE(m == id * m);
    }
}

TEST_CASE("* zero test","[matrix]")
{
    Matrix<int> zero {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    std::vector<Matrix<int>> list = get_3b3_matrices();
    for(auto m : list) {
        REQUIRE(zero == m * zero);
        REQUIRE(zero == zero * m);
    }
}

TEST_CASE("4x1 1x5 test","[matrix]")
{
    Matrix<Z<101>> a {
        {1},
        {2},
        {3},
        {4}
    };
    Matrix<Z<101>> b {
        {5,4,3,2,1}
    };

    Matrix<Z<101>> test {
        {5,4,3,2,1},
        {10,8,6,4,2},
        {15,12,9,6,3},
        {20,16,12,8,4}
    };

    REQUIRE(a * b == test);
}

TEST_CASE("* diagonal test","[matrix]")
{
    Matrix<Z<101>> a {
        {1,0,0,0},
        {0,2,0,0},
        {0,0,3,0},
        {0,0,0,4}
    };

    Matrix<Z<101>> b {
        {2,0,0,0},
        {0,1,0,0},
        {0,0,2,0},
        {0,0,0,1}
    };

    Matrix<Z<101>> test {
        {2,0,0,0},
        {0,2,0,0},
        {0,0,6,0},
        {0,0,0,4}
    };

    REQUIRE(a * b == test);
}

TEST_CASE("* 1x3 3x2 test","[matrix]")
{
    Matrix<Z<101>> a {
        {1,7,4}
    };

    Matrix<Z<101>> b {
        {2,6},
        {3,9},
        {5,5}
    };

    Matrix<Z<101>> test {
        {43,89}
    };

    REQUIRE(a * b == test);
}
