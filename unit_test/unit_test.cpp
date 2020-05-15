#include "functions.h"
#include "struct.h"

#define CATCH_CONFIG_MAIN
#include"catch.hpp"

TEST_CASE("vidurkio_skaciavimas")
{
    vector<int> H{1, 2, 3, 4, 5};
    vector<int> G{4, 5, 6, 7};
    vector<int> M{10, 20, 30};
    REQUIRE(vidurkis(H) == 3);
    REQUIRE(vidurkis(G) == 5.5);
    REQUIRE(vidurkis(M) == 20);
}
TEST_CASE ("Medianos_skaiciavimas")
{
    vector<int> H{1, 2, 8, 4, 5};
    vector<int> G{10, 5, 6, 7};
    vector<int> M{10, 15, 30};
    REQUIRE(mediana(H) == 4);
    REQUIRE(mediana(G) == 6.5);
    REQUIRE(mediana(M) == 15);
}
