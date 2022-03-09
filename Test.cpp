#include "doctest.h"
#include "mat.hpp"
#include <string>
#include <algorithm>
using namespace ariel;
using namespace std;

string ns(string input){
    erase(input, ' ');
    erase(input, '\n');
    erase(input, '\t');
    erase(input, '\r');
    return input;
}

TEST_CASE("Good Input"){
    CHECK(ns(mat(1, 1, '*', '&')) == ns("*"));
    CHECK(ns(mat(5, 5, '#', '@')) == ns("#####"
                                        "#@@@#"
                                        "#@#@#"
                                        "#@@@#"
                                        "#####"));
    CHECK(ns(mat(7, 3, '?', '!')) == ns("???????"
                                        "?!!!!!?"
                                        "???????"));
    CHECK(ns(mat(1, 9, '^', '%')) == ns("^"
                                        "^"
                                        "^"
                                        "^"
                                        "^"
                                        "^"
                                        "^"
                                        "^"
                                        "^"));
    CHECK(ns(mat(9, 7, '1', '0')) == ns("111111111"
                                        "100000001"
                                        "101111101"
                                        "101000101"
                                        "101111101"
                                        "100000001"
                                        "111111111"));
    CHECK(ns(mat(3, 3, '*', '*')) == ns("***"
                                        "***"
                                        "***"));
    CHECK(ns(mat(19, 1, '(', ')')) == ns("((((((((((((((((((((((((((((("));
    CHECK(ns(mat(13, 13, 'x', 'o')) == ns("xxxxxxxxxxxxx"
                                          "xooooooooooox"
                                          "xoxxxxxxxxxox"
                                          "xoxoooooooxox"
                                          "xoxoxxxxxoxox"
                                          "xoxoxoooxoxox"
                                          "xoxoxoxoxoxox"
                                          "xoxoxoooxoxox"
                                          "xoxoxxxxxoxox"
                                          "xoxoooooooxox"
                                          "xoxxxxxxxxxox"
                                          "xooooooooooox"
                                          "xxxxxxxxxxxxx"));
    CHECK(ns(mat(3, 7, 'z', 's')) == ns("zzz"
                                        "zsz"
                                        "zsz"
                                        "zsz"
                                        "zsz"
                                        "zsz"
                                        "zzz"));
    CHECK(ns(mat(17, 9, '|', '-')) == ns("|||||||||||||||||"
                                         "|---------------|"
                                         "|-|||||||||||||-|"
                                         "|-|-----------|-|"
                                         "|-|-|||||||||-|-|"
                                         "|-|-----------|-|"
                                         "|-|||||||||||||-|"
                                         "|---------------|"
                                         "|||||||||||||||||"));
    CHECK(ns(mat(25, 5, 'A', 'V')) == ns("AAAAAAAAAAAAAAAAAAAAAAAAA"
                                         "AVVVVVVVVVVVVVVVVVVVVVVVA"
                                         "AVAAAAAAAAAAAAAAAAAAAAAVA"
                                         "AVVVVVVVVVVVVVVVVVVVVVVVA"
                                         "AAAAAAAAAAAAAAAAAAAAAAAAA"));
    CHECK(ns(mat(5, 25, 'V', 'A')) == ns("VVVVV"
                                         "VAAAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAVAV"
                                         "VAAAV"
                                         "VVVVV"));
    CHECK(ns(mat(5, 5, '/', '\\')) == ns("/////"
                                         "/\\\\\\/"
                                         "/\\/\\/"
                                         "/\\\\\\/"
                                         "/////"));
    CHECK(ns(mat(1001, 1001, '0', '0').length() == 1001 * 1001));
}

TEST_CASE("Bad Inputs"){
    CHECK_THROWS(mat(0, 3, '1', '1'));
    CHECK_THROWS(mat(7, 0, '2', '2'));
    CHECK_THROWS(mat(10, 7, '3', '3'));
    CHECK_THROWS(mat(7, 10, '4', '4'));
    CHECK_THROWS(mat(-1, -1, '5', '5'));
    CHECK_THROWS(mat(9, -9, '6', '6'));
    CHECK_THROWS(mat(-5, 5, '7', '7'));
}