#include <regex>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    std::ifstream input;
    input.open("input.txt");
    
    std::string all{};
    std::string line{};
    while (std::getline(input, line)){
        all += line;
    }    
    
    input.close();

    std::vector<std::string> do_blocks;
    std::vector<std::pair<int, int>> mults;

    const std::regex do_block_rgx {"(?:do\\(\\))(.+?)(?:don't\\(\\))"};
    const std::regex mul_pair_rgx {"(?:mul\\()(\\d+)[,](\\d+)\\)"};
    for ( auto do_block_it = std::sregex_iterator(all.begin(), all.end(), do_block_rgx);
            do_block_it != std::sregex_iterator(); ++do_block_it){
        std::smatch do_block = *do_block_it;
        do_blocks.push_back(do_block[1].str());
    }
    for ( const auto & block : do_blocks ){
        for (
            auto mul_pair_it = std::sregex_iterator(block.begin(), block.end(), mul_pair_rgx);
            mul_pair_it != std::sregex_iterator(); ++mul_pair_it){
            std::smatch found_pair = *mul_pair_it;
            //std::cout << found_pair[1] << " * " << found_pair[2] << '\n';
            int first {};
            int second {};
            try {
                first = std::stoi(found_pair[1].str());
            } catch (const std::exception& e){
                std::cerr << found_pair[1] << " ";
                std::cerr << e.what();
            }
            try {
                second = std::stoi(found_pair[2].str());
            } catch (const std::exception& e){
                std::cerr << found_pair[2] << " ";
                std::cerr << e.what();
            }
            mults.push_back({first, second});
        }
    }
    int sum {};
    for (const auto & p : mults){
        sum += p.first * p.second;
    }
    std::cout << sum;
}