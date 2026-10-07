#include <iostream>

int n{}; // this is a uninitialized variables.


int main();
int main(){
    int* ptr = &n;
    std::cout << ptr <<std::endl;
    std::cout << n <<std::endl;
    std::cout << sizeof(int) << std::endl;
}
