#include <iostream>
/*
int main();
int f(int a, int b =1, int c =2);

int main (){
    f(1,2,3);
    f(4,5);
    f(6);
    return 0;
}

int f(int a, int b, int c){
    std::cout << a << b << c << std::endl;
}
*/
//6
// This is the function to output the same rusult as f(0) for a integer through the function f
// and print all of them in the terminal.

//7
//5 , 13, 91, 17 ,29
// only 91 is not the prime and 91=7*13
//g(5,3) b=1
//g(91,3) b=7

//8
/*
int main(){
    unsigned int n{};
    std::cin >> n;
    unsigned int times = 0;
    double a = static_cast<double>(n); 
    unsigned int digit = 0;

    while (a >= 10.0){
        a /= 10.0;
        times ++;
    }
    while (n%10 == 0){
        n /= 10;
        digit ++;
    }

    std::cout.precision(times - digit);
    std::cout << std::fixed << a <<"e" << times <<std::endl;
    return 0;
}


//8
int main();
int main(){
    unsigned short m{};
    unsigned short n{};
    std::cin >> m;
    std::cin >> n;

    if (m<n){
        std::cout <<m << " - " << n << " = " << 0xFFFF << std::endl;
        return 0;
    }
    
    unsigned short n2s = static_cast<unsigned short> (~n +1);
    unsigned short ans = static_cast<unsigned short>(m+n2s);
    std::cout <<m << " - " << n << " = " << ans << std::endl;

    return 0;
}
*/
#include <cassert>
void set(unsigned int &value, unsigned int m, unsigned int n, unsigned int bit){
    assert ((bit ==0)||(bit ==1));
    // 1 0      and& 1          or| 0    

    for (int i = m; i < n; i++ ){
        unsigned int mask = 1 << i;
        if (bit == 1){
            value |= mask;
        }else{
            value &= ~mask;
        }
    }
}

//12
void clean( char str[] ) {
    for (int i =0; str[i] != '\0'; i++){
        if (str[i] == '\t' || str[i]=='\n'|| str[i]=='\r'){
            str[i] = ' ';
        }
    }
}



void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sort( int &a, int &b, int &c){
    if (a >b){
        swap(a,b);
    }
    if (b>c){
        swap(b,c);
    }
    if (a>b){
        swap(a,b);
    }
}



