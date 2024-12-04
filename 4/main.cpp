#include <regex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include "WordFinder.h"




int main(){
    std::ifstream input;
    input.open("input.txt");
    
    std::vector<std::string> table{};
    std::string line {};

    std::vector<std::string> output_table {};
    output_table.reserve(140);
    std::string output_line {};
    output_line.reserve(140);

    int row_length {};
    int column_height {};
    int word_length = 4;

    while (std::getline(input, line)){
        row_length = std::max(row_length, static_cast<int>(line.size()));
        output_line = line;
        std::transform(output_line.begin(), output_line.end(), output_line.begin(), ::tolower);
        output_table.push_back(output_line);
        table.push_back(line);
    }
    input.close();
    column_height = table.size();

    std::cout << WordFinder::count_words(table, output_table, "XMAS");

    std::ofstream output;
    output.open("output.txt");
    for ( const auto& line : output_table){
        output << line << '\n';
    }
    output.close();
}