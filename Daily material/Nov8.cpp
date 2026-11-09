#include <iostream>

int main();
/*
Local variables aren't always enough.(static memory allocation)
*/

void local_demo(){
    int a {100}; // this a will end after call this function.
}


int main(){
    int *p_int{new int{42}};
    // p_int is stack.
    // 42 is heap.
    std::cout << p_int << std::endl; // An address
    std::cout << p_int << std::endl; // 42

    *p_int = 91; // change the integer at the address p_int
    // this is not change the address itself
    delete p_int; // release the integer and release its storage for reuse.
    p_int = nullptr; //  changes the pointer ro indecate that it points to no object.
    // this is like a combe in restaurant
    // if we lose access with one object, it will cause a memory leak.
}
/*
Stack and heap the 2 areas of memory a program uses to store data.
stack will be deleted after function terminated but heap will not unless deleting manually.
*/
