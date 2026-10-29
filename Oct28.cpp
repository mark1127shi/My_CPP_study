/*     # main memory
main memory provides temporary memory that can be accessed

\ central processing unit ========== main memory \

addresses

assume on a 32-bit computer with 4 GiB memory
 ___    <-- 0x00000000
|   | 
|   |
|   |
|   |
|___|   <- 0xffffffff


*/

#include <iostream>

int main(){
    double voltages[5]{3.7, 4.0, 2.9, 8.6, 1.5};
    int a[4000]{};

    for (int k{0}; k < 4000; ++k) {   
        std::cout<< a[k] ;
    }
}
