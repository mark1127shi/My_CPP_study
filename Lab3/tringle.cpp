#include <iostream>

int main();
int main(){
    int n;
    std::cin >> n;
    for (int a{1}; a <= n; ++a){
        for (int b{1}; b <= (a-1); ++b ){
            std::cout << "  ";

        }
        for (int c{a+1};c <=n; ++c ){
            std::cout <<"* ";
        } 
        std::cout << std::endl;
    }
}