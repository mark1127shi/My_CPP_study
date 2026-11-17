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
    int num = 0;
    while(str1[num] == str2[num] && str1[num] != '\0'){ // it can't read '\0' in the end.
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
    std::size_t i = 0;
    while (str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
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
    while(i+1 < capacity){
        if(compare(array[i],array[i+1]) == -1 || compare(array[i],array[i+1]) == 0){
            i++;
        }else{
            return i;
        }
    }
    return capacity;
}

void insert( char *array[], std::size_t capacity ){
    if (capacity < 2) {  // add boundry to capacity less than 2
        return;
    }
    bool find_location{false};
    std::size_t i = 0;
    
    while(! find_location){
        if (i == capacity-1){
            find_location = true;
            break;
        }
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
    std::size_t *num = new std::size_t[capacity];
    for (std::size_t i = 0; i < capacity; i++){
        if (compare(array[i], str) == 0){
            return i;
        }
    }

    for (std::size_t i = 0; i < capacity; i++){
        num[i] = distance(array[i], str); // get all distances
    }

    std::size_t min_num{num[0]};
    std::size_t min_num_index{0};
    for (std::size_t i = 0; i < capacity; i++){
        if(num[i] < min_num){
            min_num = num[i];
            min_num_index = i;
        }
    }
    delete[] num;
    num = nullptr;
    return min_num_index;
}

void free_word_array( char** word_array ){
    delete[] word_array[0];
    delete[] word_array;
    word_array = nullptr;
    
}


