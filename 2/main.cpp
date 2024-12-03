#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

int main(){
    std::ifstream input;
    input.open("input.txt");

    std::string line{};
    while (std::getline(input, line)){
        std::vector<int> nums;
        while ( std::find(line.begin(), line.end(), " ") != line.end() ){
            
        }
    }
}