#include <vector>
#include <string>
#include <iostream>

class WordFinder{
    public:
    static int count_words( const std::vector<std::string>& input, std::vector<std::string>& output, const std::string& word );
};


int WordFinder::count_words( const std::vector<std::string>& input, std::vector<std::string>& output, const std::string& word ){
    int row_length {static_cast<int>(input.front().size())};
    int column_height {static_cast<int>(input.size())};
    int word_length = {static_cast<int>(word.size())};
    int max_index = word_length -1;

    int count {};

    for ( int row = 0; row < row_length; row++ ){
        for ( int col = 0; col < column_height; col++ ){
            //E
            if ( (col + word_length) < row_length ){
                
                int found {};
                for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                    if (input[row][col+letter_offset] == word[letter_offset]){
                        ++found;
                    }
                }
                if (found == word_length){
                    ++count;
                    for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                        output[row][col+letter_offset] = word[letter_offset];
                    }
                }
            }
            //SE
            if ( ((col + word_length) < row_length) && ((row + word_length) < column_height) ){
                int found {};
                for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                    if (input[row+letter_offset][col+letter_offset] == word[letter_offset]){
                        ++found;
                    }
                }
                if (found == word_length){
                    ++count;
                    for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                        output[row+letter_offset][col+letter_offset] = word[letter_offset];
                    }
                }
            }
            //S 
            if ( (row + word_length) < column_height ){
                int found {};
                for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                    if (input[row+letter_offset][col] == word[letter_offset]){
                        ++found;
                    }
                }
                if (found == word_length){
                    ++count;
                    for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                        output[row+letter_offset][col] = word[letter_offset];
                    }
                }
            }
            //SW
            if ( ((col - max_index) >= 0) && ((row + word_length) < column_height) ){
                int found {};
                for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                    if (input[row+letter_offset][col-letter_offset] == word[letter_offset]){
                        ++found;
                    }
                }
                if (found == word_length){
                    ++count;
                    for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                        output[row+letter_offset][col-letter_offset] = word[letter_offset];
                    }
                }
            }
            //W
            if ( (col - max_index) >= 0 ){
                int found {};
                for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                    if (input[row][col-letter_offset] == word[letter_offset]){
                        ++found;
                    }
                }
                if (found == word_length){
                    ++count;
                    for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                        output[row][col-letter_offset] = word[letter_offset];
                    }
                }
            }
            //NW
            if ( ((col - max_index) >= 0) && ((row - max_index) >= 0) ){
                int found {};
                for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                    if (input[row-letter_offset][col-letter_offset] == word[letter_offset]){
                        ++found;
                    }
                }
                if (found == word_length){
                    ++count;
                    for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                        output[row-letter_offset][col-letter_offset] = word[letter_offset];
                    }
                }
            }
            //N
            if ( (row - max_index) >= 0 ){
                int found {};
                for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                    if (input[row-letter_offset][col] == word[letter_offset]){
                        ++found;
                    }
                }
                if (found == word_length){
                    ++count;
                    for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                        output[row-letter_offset][col] = word[letter_offset];
                    }
                }
            }
            //NE
            if ( ((col + word_length) < row_length) && ((row - max_index) >= 0) ){
                int found {};
                for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                    if (input[row-letter_offset][col+letter_offset] == word[letter_offset]){
                        ++found;
                    }
                }
                if (found == word_length){
                    ++count;
                    for ( int letter_offset = 0; letter_offset < word_length; ++letter_offset ){
                        output[row-letter_offset][col+letter_offset] = word[letter_offset];
                    }
                }
            }
            
        }
    }

    return count;
}