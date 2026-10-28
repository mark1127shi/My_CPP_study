#include <iostream>

int main ();
int main () {
    
     int row{0};
     //int max{10};
     while (row < 5 ){
          for (int col {0}; col < row; ++col){
               std::cout << "  ";
          }

          for (int col {5}; col > row; --col){
               std::cout << "* ";
          }
          std::cout << std::endl;
          ++row;
    
     }
     return 0;
}