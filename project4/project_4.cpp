#include <iostream>
#include <cassert>
#include <algorithm>
#include "p_4_header.hpp"


std::size_t length( char const *a){
    std::size_t count{0};
    while (*a != '\0'){
        count++;
        a++;
    }
    return count;
}
int compare( char const *str1, char const *str2){
    bool have_result{false};
    int num = 0;
    while(str1[num] == str2[num]){
        num++;
    }
    if(str1[num]<str2[num]){
        return -1;
    }else if(str1[num] == str2[num]){
        return 0;
    }else{
        return 1;
    }
}

void assign( char *str1, char const *str2){
    assert(sizeof(str1)<= 20 && sizeof(str2) <= 20);
    int i = 0;
    while (str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    if (str1[i] != '\0'){
        while (str1[i] != '\0'){ // make sure if str1 longer that str2, we can make all char to '\0'
            str1[i] =0;
            i++;
        }
    }
}

unsigned int distance(char const *str1, char const *str2){// we turn str1 into str2
    if (str1[0] == '\0' ){
        return length(str2);
    }else if(str2[0] == '\0'){
        return length(str1);
    }

    if (str1[0] == str2[0]) {
        return distance(str1 + 1, str2 + 1);
    }else{
        unsigned int after_delete = distance(str1 + 1, str2);
        unsigned int after_insert = distance(str1, str2+1);
        unsigned int after_replace = distance(str1+1, str2+1);
        return 1u + std::min(after_delete, std::min(after_insert, after_replace));
    }
}

std::size_t is_sorted( char *array[], std::size_t capacity){
    std::size_t i = 0;
    while(i < capacity){
        if(compare(array[i],array[i+1]) == -1 || compare(array[i],array[i+1]) == 0){
            i++;
        }else{
            return i+1;
        }
    }
    return capacity;
}

void insert( char *array[], std::size_t capacity ){
    bool find_location{false};
    std::size_t i = 0;
    
    while(! find_location){
        if (i == capacity-1)
        if (compare(array[i],array[capacity-1]) == 1 || compare(array[i],array[capacity-1]) == 0){
            find_location = true;
        }else{
            i++;
        }
        
    }
    char *temp = new char[length(array[capacity-1]) + 1];
    assign(temp, array[capacity-1]);
    for (std::size_t j = capacity-1; j > i; --j) {
        assign(array[j], array[j - 1]);
    }
    assign(array[i], temp);
    delete[] temp;
    temp = nullptr;
}

void insertion_sort( char *array[], std::size_t capacity ){
    for (std::size_t i = 1; i<= capacity; i++){
        insert(array,i);
    }
}

std::size_t remove_duplicates(char *array[], std::size_t capacity){
    if (capacity == 0) {
        return 0;    
    }
    std::size_t unique_count{1};

    for (std::size_t read{1}; read < capacity; ++read) {
        if (compare(array[read], array[unique_count - 1]) == 0) {
            continue;  // Skip the duplicate.
        }

        if (read != unique_count) {
            assign(array[unique_count], array[read]);
        }
        ++unique_count;
    }

    return unique_count;
}

std::size_t find( char *array[], std::size_t capacity, char const *str ){
    std::size_t before{};
    std::size_t after{};
    for (std::size_t i = 0; i< capacity; i++){
        if (compare(array[i], str) == 0){
            return i;
        }
        if (compare(array[i], str) == -1 && compare(array[i+1], str) == 1 ){
            before = i;
            after  = i+1;
        }
    }
    if ((distance(array[before], str) <= distance(array[after], str))){
        return before;
    }else{
        return after;
    }
}

void free_word_array( char** word_array ){
    delete[] word_array[0];
    delete[] word_array;
    word_array = nullptr;
    
}


