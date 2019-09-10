#include <catch2/catch.hpp>
#include <matrix.h>

using namespace homology;

TEST_CASE("Inequality test 1","[matrix]")
{
    for(int i = 0; i < 50; ++i) {
        for(int j = 0; j < 50; ++j) {
            Matrix<int> m1{{j,i},{j,j}};
            Matrix<int> m2{{j,j},{j,j}};
            if(i == j) {
                REQUIRE(!(m1 != m2));
                continue;
            } 
            REQUIRE(m1 != m2);
        }
    }

}
