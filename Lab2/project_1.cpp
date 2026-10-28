#include <iostream>
#include <cmath>

int main();
int main(){
    // final
    double max_final {}, ave_final {}; // max must be a interger

    std::cout << "Enter the maximum grade on the final examination:";
    std::cin >> max_final;
    while (max_final <= 0 || max_final != std::round(max_final)){
        std::cout << "Enter the maximum grade on the final examination:";
        std::cin >> max_final;
    }

    std::cout << "Enter your grade on the final examination:";
    std::cin >> ave_final;
    while (max_final < ave_final || ave_final < 0){
        std::cout << "Enter your grade on the final examination:";
        std::cin >> ave_final;
    }

    // midterm 
    double max_mid {}, ave_mid {};
    std::cout << "Enter the maximum grade on the mid examination:";
    std::cin >> max_mid;
    while (max_mid <= 0 || max_mid != std::round(max_mid)){ // use round to check whether it is a interger or not
        std::cout << "Enter the maximum grade on the mid examination:";
        std::cin >> max_mid;
    }

    std::cout << "Enter your grade on the mid examination:";
    std::cin >> ave_mid;
    while (max_mid < ave_mid || ave_mid < 0){
        std::cout << "Enter your grade on the mid examination:";
        std::cin >> ave_mid;
    }
    ave_mid = std::round(ave_mid); // round

    //Project 1
    double max_1, max_2, max_3, max_4, max_5;
    double p1, p2, p3, p4, p5;
    std::cout << "Enter the maximum grade on project 1:";
    std::cin >> max_1;
    while (max_1 <= 0 || max_1 != std::round(max_1)){
        std::cout << "Enter the maximum grade on project 1:";
        std::cin >> max_1;
    }

    std::cout << "Enter your grade on the P1 examination:";
    std::cin >> p1;
    while (max_1 < p1 || p1 < 0){
        std::cout << "Enter your grade on the P1 examination:";
        std::cin >> p1;
    }
    p1 = std::round(p1); // round

    std::cout << "Enter the maximum grade on project 2:";
    std::cin >> max_2;
    while (max_2 <= 0 || max_2 != std::round(max_2)){
        std::cout << "Enter the maximum grade on project 2:";
        std::cin >> max_2;
    }
    std::cout << "Enter your grade on the P2 examination:";
    std::cin >> p2;
    while (max_2 < p2|| p2 < 0){
        std::cout << "Enter your grade on the P2 examination:";
        std::cin >> p2;
    }
    p2 = std::round(p2);

    std::cout << "Enter the maximum grade on project 3:";
    std::cin >> max_3;
    while (max_3 <= 0 || max_3 != std::round(max_3)){
        std::cout << "Enter the maximum grade on project 3:";
        std::cin >> max_3;
    }
    std::cout << "Enter your grade on the P3 examination:";
    std::cin >> p3;
    while (max_3 < p3 || p3 < 0){
        std::cout << "Enter your grade on the P3 examination:";
        std::cin >> p3;
    }
    p3 = std::round(p3);

    std::cout << "Enter the maximum grade on project 4:";
    std::cin >> max_4;
    while (max_4 <= 0 || max_4 != std::round(max_4)){
        std::cout << "Enter the maximum grade on project 4:";
        std::cin >> max_4;
    }
    std::cout << "Enter your grade on the P4 examination:";
    std::cin >> p4;
    while (max_4 < p4|| p4 < 0){
        std::cout << "Enter your grade on the P4 examination:";
        std::cin >> p4;
    }
    p4 = std::round(p4);

    std::cout << "Enter the maximum grade on project 5:";
    std::cin >> max_5;
    while (max_5 <= 0 || max_5 != std::round(max_5)){
        std::cout << "Enter the maximum grade on project 5:";
        std::cin >> max_5;
    }
    std::cout << "Enter your grade on the P5 examination:";
    std::cin >> p5;
    while (max_5 < p5 || p5 < 0){
        std::cout << "Enter your grade on the P5 examination:";
        std::cin >> p5;
    }
    p5 = std::round(p5);

    double f100, m100, p1100, p2100, p3100, p4100, p5100;
    f100 = 100.0 * ave_final / max_final;
    m100 = 100.0 * ave_mid / max_mid ;
    p1100 = 100.0 * p1 / max_1;
    p2100 = 100.0 * p2 / max_2;
    p3100 = 100.0 * p3 / max_3;
    p4100 = 100.0 * p4 / max_4;
    p5100 = 100.0 * p5 / max_5;

    if (f100>m100){
        m100 = f100;
    }
    if (f100>p1100){
        p1100 = f100;
    }
    if (f100>p2100){
        p2100 = f100;
    }
    if (f100>p3100){
        p3100 = f100;
    }
    if (f100>p4100){
        p4100 = f100;
    }
    if (f100>p5100){
        p5100 = f100;
    }


    double e100;
    e100 = 0.75 * f100 + 0.25 * m100;

    double p100{};
    p100 = 0.2 * p1100 + 0.2 * p2100 + 0.2 * p3100 + 0.2 * p4100 + 0.2 * p5100;

    if (e100 <= 40){
        std::cout << "Final Grade:" << std::round(e100 + 1e-12)
                  << std::endl;
    }else if (e100 >= 60){
        std::cout << "Final Grade:" << std::round(2.0 / 3.0 * e100 + 1.0/3.0 * p100 + 1e-12)
                  <<std::endl;
    }else{
        std::cout << "Final Grade:" << std::round(-1.0*e100*e100/60.0 +5.0*e100/3.0 + p100*e100/60.0 - 2.0 *p100 / 3.0 +1e-12)
                  <<std::endl;
    }
    return 0;
}   
