#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PGMImageProcessor.h"


TEST_CASE("PGMImageProcessor tests"){
    SECTION("Load image test"){
        PGMImageProcessor p("../images/chess.pgm");
        REQUIRE(p.getRows() == 252);
        REQUIRE(p.getCols() == 609);
        //int rows = sizeof(p.getImage())/sizeof(unsigned char*);
        //int cols = sizeof(p.getImage()[0])/sizeof(unsigned char);
        //REQUIRE(rows == 252);
        //REQUIRE(cols == 609);
    }
    SECTION("Copy Constructor"){
        PGMImageProcessor p("../images/chess.pgm");
        PGMImageProcessor n(p);
        REQUIRE(n.getRows() == p.getRows());
        REQUIRE(n.getCols() == p.getCols());
        REQUIRE(n.getImage() != p.getImage());
    }
    SECTION("Move Constructor"){
        PGMImageProcessor p("../images.chess.pgm");
        PGMImageProcessor l = std::move(p);
        REQUIRE(l.getRows() == 252);
        REQUIRE(l.getCols() == 609);
        REQUIRE(l.getImage() != nullptr);
        REQUIRE(p.getImage() == nullptr);
    }
    SECTION("Move Assignment"){
        PGMImageProcessor p("../images/chess.pgm");
        PGMImageProcessor l;
        l = std::move(p);
        REQUIRE(l.getCols() == 252);
        REQUIRE(l.getCols() == 609);
        REQUIRE(l.getImage() != nullptr);
        REQUIRE(p.getImage() == nullptr);
    }
    SECTION("writeImage"){
        PGMImageProcessor p("../images/chess.pgm");
        p.writeImage("output/test.pgm",p.getImage());
        PGMImageProcessor l("output/test.pgm");//loading the written image into a new isntance of PGMImageProcessor to compare with the original image
        REQUIRE(p.getCols() == l.getCols());
        REQUIRE(p.getRows() == l.getRows());

    }
    

}   