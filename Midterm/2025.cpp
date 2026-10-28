#include <iostream>

void draw(int m, int n);

void draw(int m, int n){
    for (int i = 0; i < m; i++){
        if (i == n){
            break;
        }
        for (int j=0; j<i; j++){
            std::cout << ".";
        }
        
        std::cout << "x";
        for (int k=n; k>i+1; k--){
            std::cout <<"o";
        }
        std::cout << std::endl;
    }
    if (m>n){
        for (int i =0; i<(m-n); i++){
            for (int j=0; j<n; ++j){
                std::cout << ".";
            }
            std::cout << std::endl;
        }
    }


}

int main();
int main(){
    draw(5,3);
       std::cout << std::endl;
    draw(3,5);
}
