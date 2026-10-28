/*
assignment operator
*/
#include <iostream>

int main();
int main(){
    //linear algebra
    //for loop
    for ( int k{1}; k != 0 ; ++k ){ // unlimited loop
        std::cout << "Hello world!!!"  << k << std::endl;
    }

    int factorial {1};

    for ( int k{1}; k <= 100; ++k ){
        factorial *= k;
        std::cout << factorial << std::endl;
        if (factorial == 0){
            std::cout << k << std::endl;
            return 0;
        }
    }
    return 0;
}
