#include <iostream>
#include <cassert>


void pattern (unsigned int n){ // unsigned keeps the n >= 0
    //first loop
    for (unsigned int i = 0; i < n; ++i){
        for (unsigned int k = (2*(n - i) + 1); k > 0; --k){
            std::cout << "*";
        }
        std::cout << std::endl;
        for (unsigned int j = 0; j < (i+1); ++j){
            std::cout << " ";
        }
    }

    //star in the middle
    std::cout << "*" << std::endl;

    // another loop
    for (unsigned int i = 0; i < n; ++i){
        for (unsigned int k = n - i - 1; k > 0; --k ){
            std::cout << " ";
        }
        for (unsigned int j = 0; j < (2*(i+1)+1) ; ++j){ // cause n start with 0(the reason why use that condition); and should start with ***
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

unsigned int log10(unsigned int n){
    assert(n != 0);

    unsigned int m {0};
    while (n >= 10){
        n /= 10;
        ++m;
    }
    /*double m {std::log10(n)};
    int m_int = static_cast<int>(m); this is the method to simply get rid of the fractional part from float/double.*/
    //std::cout << m << std::endl;
    return m;
}

// Question will those include all 0 even it not do anything to the whole
unsigned int count(unsigned int n, unsigned int bit){
    assert(bit == 0 || bit == 1);
    unsigned int times{0};
    for (unsigned i {0}; i < 32; i++){
        if ((n & 1u) == bit){
            ++times;
        }
        n >>= 1;        
    }
    //std::cout << times << std::endl;
    return times;
}

// should be like 33333333 22222222 11111111 00000000
unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1){
    assert(b0 <= 3 && b1 <= 3); // cause unsigned means it must >=0
    if (b0 == b1) {
        return n;
    }
    unsigned int byte_b0 = (n >> (8 * b0) & 0xFFu);
    unsigned int byte_b1 = (n >> (8 * b1) & 0xFFu);
    unsigned int musk = (0xFFu << (8 * b0)) | (0xFFu << (8 * b1));
    
    unsigned int new_byte = n & ~musk;
    new_byte |= byte_b0 <<(8 *b1);
    new_byte |= byte_b1 <<(8 *b0);
    // std::cout << new_byte <<std::endl;
    return new_byte;
}

int main();
int main(){
    pattern(1);
    pattern(3);
    pattern(5);
    pattern(2);
    return 0;
}
