#define CATCH_CONFIG_MAIN
#include "WordFinder.h"
#include "catch.hpp"

TEST_CASE("XMAS"){
    std::vector<std::string> table {
        {"MMMSXXMASM"},
        {"MSAMXMSMSA"},
        {"AMXSXMAAMM"},
        {"MSAMASMSMX"},
        {"XMASAMXAMM"},
        {"XXAMMXXAMA"},
        {"SMSMSASXSS"},
        {"SAXAMASAAA"},
        {"MAMMMXMMMM"},
        {"MXMXAXMASX"}
    };
    std::vector<std::string> result {
        {".........."},
        {".........."},
        {".........."},
        {".........."},
        {".........."},
        {".........."},
        {".........."},
        {".........."},
        {".........."},
        {".........."},
        {".........."}
    };

    CHECK(WordFinder::count_words(table, result, "XMAS") == 18);
    CHECK(result[0] == "....XXMAS." );
    CHECK(result[1] == ".SAMXMS..." );
    CHECK(result[2] == "...S..A..." );
    CHECK(result[3] == "..A.A.MS.X" );
    CHECK(result[4] == "XMASAMX.MM" );
    CHECK(result[5] == "X.....XA.A" );
    CHECK(result[6] == "S.S.S.S.SS" );
    CHECK(result[7] == ".A.A.A.A.A" );
    CHECK(result[8] == "..M.M.M.MM" );
    CHECK(result[9] == ".X.X.XMASX" );
}