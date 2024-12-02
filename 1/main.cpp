#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

int main(){

    std::ifstream input;
    input.open("input.txt");

    std::vector<int> left{};
    std::vector<int> right{};

    std::string line;
    std::string l {}; 
    std::string r {};
    while (std::getline(input, line)){
        l = line.substr(0, 5);
        r = line.substr(8, 5);
        left.push_back(std::stoi(l));
        right.push_back(std::stoi(r));
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    auto l_it = left.begin();
    auto r_it = right.begin();

    int diff {};
    int sim {};
    while (l_it != left.end()){
        int occ {};
        for ( auto r_sec = right.begin(); r_sec != right.end(); ++r_sec ){
            occ += *l_it * ( *l_it == *r_sec );
        }
        sim += occ;

        diff += std::abs(*l_it - *r_it);
        ++l_it;
        ++r_it;
    }

    std::cout << '\n' << diff;
    std::cout << '\n' << sim;
}