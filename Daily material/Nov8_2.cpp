#include <iostream>

int main();

/*
create whole array in heap
array created by new can't change capacity after being created
like: 
int capacity = 10;
new int[capacity]{};
capacity = 100; // this will only change int capacity while capacity of array is still 10.
*/
int main(){
    std::size_t capacity{10};
    int *a_data{new int[capacity]{}};// this will assign each one to 0 and will not be unsigned
    // if we use int *a_data{new int[capacity]} this will leave array unsigned

    delete[] a_data;
    // delete[] gives a delete for array but delete is only for one thing.
    a_data = nullptr;
    return 0;
}

/*
std::nothrow will give us a check for allocation failure using nullptr.
but we still need to create a new array with larger capacity.
*/

int check_capacity(){
    int capacity = 1;
    int *a_data{new (std::nothrow) int[capacity]{}};

    if (a_data == nullptr){
        //handle the failed allocation here.
    }
    delete[] a_data;
    a_data = nullptr;
    return 0;
}
