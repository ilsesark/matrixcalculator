#include "catch.hpp"
#include "IntElement.h"

TEST_CASE("IntElement test", "[intelement]") {
    IntElement ie(12);
    CHECK(ie.getVal() == 12);

    IntElement ie2(-20);
    ie += ie2;
    CHECK(ie.getVal() == -8);

    IntElement summa = ie + ie2;
    CHECK(summa.getVal() == -28);

    ie.setVal(1);
    CHECK(ie.getVal() == 1);

    ie -= ie2;
    CHECK(ie.getVal() == 21);

    ie *= ie2;
    CHECK(ie.getVal() == -420);

    IntElement erotus = ie - ie2;
    CHECK(erotus.getVal() == -400);

    IntElement kerto = ie * ie2;
    CHECK(kerto.getVal() == 8400);

}