#include <iostream>

int main();
int main(){
    std::cout << "Hello" 
              << std::endl;
    std::cout << 1/2 // ans is 0
              << std::endl;
    std::cout << 1.0/2 // ans is 0.5
              << std::endl;
    return 0;
}
/*
Initialization

assignment
int a{42};
a = 11; called a is assigned the value 11.
a will be 11.

int m, n;
m = n = 10; =>>
n = 10; (this will do first and then m = n)
== > m = (n = 10); 
     m = n

(m = n) = 10; =>>
m = 10
*/
/*
Arithmetic operators  // every operator is binary operator except ++ and --.
+ - * /(division) %(remainder) ++ --

evaluation start from left to right except for assignment operator which is right to left.

++a; // pre-increment
a++; // post-increment
--a; // pre-decrement
a--; // post-decrement 

double is a floating point type and with 17 significant digits of precision.
double x{1/2*2.0} // this is equal to 0.0 because 1/2 is 0 and 0*2.0 is 0.0


*/



