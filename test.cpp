#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "5\n"
                "1 50 3 4 3\n"
                "16\n"
                "1 2 3 4 5 1 3 3 4 5 5 5 5 5 4 5"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() ==
            "YES\n"
            "NO\n"
            "NO\n"
            "NO\n"
            "YES\n"
    );
}
/*
TEST_CASE("test 2", ""){
    std::stringstream input(
            ""
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    ""
    );
}
*/
