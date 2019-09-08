#include <catch2/catch.hpp>
#include <matrix.h>

using namespace homology;

TEST_CASE("Initialization test 1","[matrix]")
{
    Matrix<int> m{
        {1,2},
        {1,2}
    };
}
