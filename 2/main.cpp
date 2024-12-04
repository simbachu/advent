#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>

bool safe_delta(const int& lhs, const int& rhs){
    int delta { std::max(lhs, rhs) - std::min(lhs, rhs) };
    return (delta > 0 && delta <= 3);
}

bool is_safe(const std::vector<int>& nums){
    if (std::is_sorted(nums.begin(), nums.end()) || std::is_sorted(nums.begin(), nums.end(), std::greater<int>())){
        auto it = nums.begin();
        while (it != nums.end()-1){
            if (safe_delta(*it, *(it+1))){
                ++it;
            } else {
                return false;
            }
        }
        return true;
    } else { return false; }
}

bool is_safe_with_dampener(const std::vector<int>& nums){
    bool found_perm {false};
    std::vector<std::vector<int>> permutations;
    for ( auto i {0}; i < nums.size(); i++ ){
        std::vector<int> perm {nums};
        perm.erase(perm.begin()+i);
        permutations.push_back(perm);
    }
    for ( const auto & perm : permutations ){
        if ( is_safe(perm) ){
            for ( const auto& i : perm ){
                std::cout << i << " ";
            }
            std::cout << '\n';
            found_perm = true;
        }
    }
    return found_perm;
}

int main(){
    std::ifstream input;
    input.open("input.txt");

    int safe {};
    int safe_with_dampener {};
    std::string line{};
    while (std::getline(input, line)){
        std::vector<int> nums;
        std::cout << line << '\n';
        while ( line.size() ){
            size_t str_offset {};
            nums.push_back(std::stoi(line, &str_offset));
            line = line.substr(str_offset);
        }

        if (is_safe(nums)){
            std::cout << "Safe" << '\n';
            safe++;
            } else if ( is_safe_with_dampener(nums) ){
                std::cout << "Safe (dampened)" << '\n';
                safe_with_dampener++;
            } else {
                std::cout << "Unsafe" << '\n';
            }
        }
    std::cout << safe << '\n' << safe + safe_with_dampener;
}