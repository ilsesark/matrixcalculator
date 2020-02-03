#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "SquareMatrix.h"

TEST_CASE("Matrix test") {
    CHECK_THROWS(SquareMatrix("[[1,2][3,4,5]]"));
    CHECK_NOTHROW(SquareMatrix("[[1,2,4][2,5,6][7,9,4]]"));

    SquareMatrix mt("[[2,3][-1,5]]");
    CHECK(mt.toString() == "[[2,3][-1,5]]");

    SquareMatrix mt2 = SquareMatrix(mt);
    CHECK(mt2.toString() == mt.toString());

    SquareMatrix mt3("[[1,2][3,4]]");
    CHECK(mt3.toString() == "[[1,2][3,4]]");

    mt += mt3;
    CHECK(mt.toString() == "[[3,5][2,9]]");

    mt -= mt3;
    CHECK(mt.toString() == "[[2,3][-1,5]]");

    mt.print(std::cout);

    SquareMatrix sq1("[[1,2][3,4]]");

    SquareMatrix sq2("[[1,2,3][3,4,5][4,6,5]]");

    CHECK(sq1.toString() == "[[1,2][3,4]]");

    CHECK(sq2.toString() == "[[1,2,3][3,4,5][4,6,5]]");

    SquareMatrix sq3 = sq1.transpose();

    CHECK(sq3.toString() == "[[1,3][2,4]]");

    sq3 *= sq1;

    //CHECK(sq3.toString() == "[[10,14][14,20]]");

    CHECK(sq3.toString() == "[[1,3][2,4]]");



    SquareMatrix tulos = mt + sq1;

    CHECK(tulos.toString() == "[[3,5][2,9]]");

    tulos = mt - sq1;

    //CHECK(tulos.toString() == "[[1,1][-4,1]]");

    CHECK(tulos.toString() == "[[1,1][-4,1]]");

    tulos = mt * sq1;

    CHECK(tulos.toString() == "[[2,3][-1,5]]");

    CHECK_FALSE(mt == sq1);

    mt = sq1;

    CHECK(mt.toString() == sq1.toString());

    SquareMatrix testi{6};

    SquareMatrix testi2{6};

    testi += testi2;

    std::cout << testi.toString() << std::endl;

    SquareMatrix testi3{6};

    testi -= testi3;

    std::cout << testi.toString() << std::endl;

    SquareMatrix testi4{6};

    testi *= testi4;

    std::cout << testi.toString() << std::endl;

    SquareMatrix testi5{6};

    testi *= testi5;

    std::cout << testi.toString() << std::endl;

}