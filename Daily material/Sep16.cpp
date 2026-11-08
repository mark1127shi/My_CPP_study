/*
Conditional Statements
*/


/*
#include <iostream>

int main();
int main(){
    std::cout << "Please enter a four digit number:";
    int number {};
    std::cin >> number;
    int front;
    front = number / 1000;
//  std::cout << front << std::endl;
    int back {number % 1000};
//  std::cout << back << std::endl;
    std::cout << front << ",";
    if (back < 10) {
        std::cout <<"00";
    } else if (back < 100){
        std::cout << "0";
    }
    std::cout << back <<std::endl;
    return 0;
}
*/
#include <iostream>

int main();
int main(){
    float a{}, b{}, c{};
    std::cout << "Please eneter a:";
    std::cin >> a;
    std::cout << "Please eneter b:";
    std::cin >> b;
    std::cout << "Please eneter c:";
    std::cin >> c;

    if (a == 0){
        std::cout << "This is not a quadratic function."
        << std::endl;
        return 0;
    }

    std::cout << a << "x^2";

    if (b != 0) {
        if (b > 0) {
            std::cout << "+";
        }
        std::cout << b << "x";
    }

    if (c != 0) {
        if (c > 0) {
            std::cout << "+";
        }
        std::cout << c;
    }

    std::cout << std::endl;
 /*   if (a == 0){
        std::cout << "This is not a quadratic function, please enter another one or enter 0 to exit"
        << std::endl;
        std::cin >> a;
        if (a == 0){ return 0; }
    }else if (b < 0 && c==0){
        float co_b = -b;
        std::cout << a <<"x^2-" << co_b <<"x";
    }else if (b > 0 && c==0){
        std::cout << a <<"x^2+" << b <<"x";
    }else if (b == 0 && c<0){
        float co_c = -c;
        std::cout << a <<"x^2-" << co_c ;
    }else if (b == 0 && c>0){
        std::cout << a <<"x^2+" << c;
    }
    else if (b == 0 && c == 0){
        std::cout << a <<"x^2";
    }else{
        std::cout << a <<"x^2+" << b << "x" << c;
    }
    std::cout << std::endl;*/
}


// Afternoon class
/*
conditional statement 
< > <= >= == !=
&& and       || or
logical &&and first always and || second

so we can use this sentence in program.
bool eq {m == n};



*/
