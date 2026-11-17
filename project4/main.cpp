#include "p_4_header.hpp"

#include <iostream>
#include <fstream>
#include <cassert>

/// @brief This main is used for testing. Feel free to modify the contents.
/// @remark This file is replaced with a testing main when you submit your project.
int main() {
    std::size_t const WIDTH{ 20 }; // set the maximum number of letters in a word
     
    char **test_words{};            // empty word array
    std::size_t num_test_words{};   // number of words (will be modified when a file is read)

    // populate the word array, and update the number of words
    read_words_from_file("test_words.txt", test_words, num_test_words, WIDTH );

      //////////////////////
     // Function Testing //
    //////////////////////
    char test_string[21] {"cat"};

    // length
    std::cout << "The length of " << test_string << " is " << length(test_string) << std::endl;
    
    // comapare
    int test_compare { compare ( test_string, "dog") };
    if ( test_compare < 0 ) {
        std::cout << "The test_string comes before dog" << std::endl;
    } else if ( test_compare > 0 ) {
        std::cout << "The test_string comes after dog" << std::endl;
    } else {
        std::cout << "The test_string is dog" << std::endl;
    }

    // assign
    assign(test_string, "bird");
    std::cout << test_string << std::endl;
    
    // distance
    std::cout << "The distance between " << test_string 
              << " and hat is " << distance(test_string, "hat") << std::endl;

    // is sorted
    std::size_t num_sorted = is_sorted( test_words, num_test_words );
    if ( num_sorted == num_test_words ) {
        std::cout << "The test_words array is sorted." << std::endl;
    } else {
        std::cout << "Only the first " << num_sorted + 1 << " words are sorted." << std::endl;
    }

    /// Insert additional tests as needed

    // deallocate
    free_word_array(test_words);

    return 0;
}


/// @brief Reads words from a text file, allocates and populates a word array, and modifies the number of words
/// @remark You will need to understand how memory is allocated in order to delete memory in free_word_array
/// @param filename the name of the file to be opened
/// @param word_array given a word array pointer, allocates the word array
/// @param num_words updates (pass by reference) the number of words found in the file
/// @param width the maximum number of letters in a word
void read_words_from_file( 
    char const *filename, 
    char **&word_array,
    std::size_t &num_words, 
    std::size_t  width
) {

    // Attempt to open the file
    std::ifstream file{ filename };
    if (!file.is_open()) {
        std::cout << "[ERROR] " << filename << " not found or could not open file" << std::endl;
    }
    assert( file.is_open() );

    // Read the number of words from the first line of the file
    file >> num_words;

    // Ignore the newline '\n' character after the number
    file.ignore();

    /// Allocate memory and initialize the word array
    word_array = new char*[num_words]{};                // pointers to individual words
    word_array[0] = new char[num_words*(width + 1)]{};  // contiguous list of all words

    for ( std::size_t k{ 1 }; k < num_words; ++k ) {    // connect the individual word pointers
        word_array[k] = word_array[k-1] + width + 1;
    }


    // Read from the file into the word array
    for ( std::size_t k{ 0 }; k < num_words; ++k ) {
        file >> word_array[k];
    }

    file.close();
}
