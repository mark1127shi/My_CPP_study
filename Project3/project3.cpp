// Project 3
#include <iostream>
#include <cassert>

// function declaration;
double *geometric( double a, double ratio, std::size_t cap);
double *cross_correlation(
    double array0[], std::size_t cap0, double array1[], std::size_t cap1
);


double *geometric( double a, double ratio, std::size_t cap){
    double *array0 = new double[cap];
    double temp = a;
    for (int i =0; i < cap; i++ ){
        array0[i] = temp;
        temp *= ratio;
    }
}


