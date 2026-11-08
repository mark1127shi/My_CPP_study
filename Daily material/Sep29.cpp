#include <iostream>
#include <cmath>

//define the variables
int result{1};

// 1 + 1 + 2 + 3 + 5 + 8 ... find a fibonacci number in order
int Fibonacci(int a){

    //special situation
    if (a == 1){
        return 1;
    }else if(a == 2){
        result = 2;
        return 1;
    }else if(a < 1){
        return 0;
    }
    if (a >= 1 ){
        result = Fibonacci(a-1) + Fibonacci(a-2);
        // --a;
    }
    return result;
}

int main();
int main(){
    Fibonacci(100);
    std::cout << result << std::endl;
    return 0;
}

/*



*/
