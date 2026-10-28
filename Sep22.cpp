#include <iostream>

int main();
int main(){
    std::cout << "This is the note for Sep 22 ECE150." << std::endl;
    // use 2 loop to print example1
    for (int i{1}; i <= 6; ++i){
        for (int j{1}; j<= i; ++j){
            std::cout << "* " ;
        }
        std::cout << std::endl;
    }

    std::cout << " " << std::endl;
    
    // second one.
    int n;
    std::cin >> n;
    for (int a{1}; a <= n; ++a){
        for (int b{1}; b <= (a-1); ++b ){
            std::cout << "  ";

        }
        std::cout << "o ";
        for (int c{a+1};c <=n; ++c ){
            std::cout <<"* ";
        } 
        std::cout << std::endl;
    }
    
    //break
    bool is_prime {true};
    int m {};
    std::cin >> m;
    if ( n%2 == 0 ){
        is_prime = false;
    }else{
        for(int k{3}; is_prime && k*k <= m; ++k){
            if( m%k==0 ){
                is_prime = false;
                break;
            }
        }
    }
    if (is_prime){
        std::cout << m << " is a prime." <<std::endl;
    }else{
        return 0;
    }
}
/*
Break statements

*/
