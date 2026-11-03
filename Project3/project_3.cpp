// Project 3
#include <iostream>
#include <cassert>

// function declaration;
double *geometric( double a, double ratio, std::size_t cap);
double *cross_correlation(
    double array0[], std::size_t cap0, double array1[], std::size_t cap1
);
std::size_t shift_duplicates (int array[], std::size_t capacity);
void deallocate (double *&ptr, bool is_array, std::size_t capcity = 0);


double *geometric( double a, double ratio, std::size_t cap){
    double *array0 = new double[cap];
    double temp = a;
    for (std::size_t i =0; i < cap; i++ ){
        array0[i] = temp;
        temp *= ratio;
    }
    return array0;
}

double *cross_correlation(
    double array0[], std::size_t cap0, double array1[], std::size_t cap1
){
    assert(cap0 +cap1 >= 1);
    double *array2 = new double[(cap0 +cap1 -1)];// will give i+j enough space
    for (std::size_t i =0; i < (cap0 +cap1 - 1); i++){
        array2[i] = 0.0; // Initialized to zero;
    }
    for (std::size_t i =0; i < cap0; i++){
        for (std::size_t j = 0; j < cap1; j++){
            array2[i+j] += array0[i] * array1[j]; 
        }
    }
    return array2;
}

std::size_t shift_duplicates (int array[], std::size_t capacity){
    std::size_t front = 0; // this is for front one.
    if (capacity == 0) {
        return 0;
    } //to avoid end = -1
    std::size_t end = capacity-1;
    for (std::size_t j =0; j <= end; j++){
        bool found = false;
        for (std::size_t i{0}; i < j; i++ ){
            if (array[j] == array[i]){
                found = true;
                int temp = array[j];
                for (std::size_t k{j}; k < end; k++){
                    array[k] = array[k+1];
                }
                array[end] = temp;
                end--;
                j--;
                break;
            }
        }
        if(! found){
            front ++;
        }
    }
    return front;
}

void deallocate (double *&ptr, bool is_array, std::size_t capcity){ // do not need to claim that capcity = 0 otherwise conflict.
    if(is_array){
        for (std::size_t i = 0; i < capcity; i++){
            ptr[i] = 0.0;
        }
        delete[] ptr;
        ptr = nullptr;
    }else{
        *ptr = 0.0;
        delete ptr;
        ptr = nullptr;
    }
}



