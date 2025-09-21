#include <iostream>
#include <iomanip> //inclui setprecision e fixed
#include <cmath>

void calc_area_circ_double(){
    double d, r, pi;
    std::cout << "Digite o diametro: ";
    std::cin >> std::fixed >> std::setprecision(5) >> d;  // arredonda para 5 casas
    r = d / 2.0;
    pi = 3.14159;
    std::cout << "--------------\nVersão Double\n" << std::fixed << std::setprecision(5) << pi * (r * r) << "\n--------------" << std::endl; 
}

void calc_area_circ_float(){
    float d, r, pi;
    std::cout << "Digite o diametro: ";
    std::cin >> std::fixed >> std::setprecision(5) >> d;  // arredonda para 5 casas
    r = d / 2.0;
    pi = 3.14159;
    std::cout << "--------------\nVersão Float\n" << std::fixed << std::setprecision(5) << pi * (r * r) << "\n--------------" << std::endl; 
}

int main(){
    calc_area_circ_double();
    calc_area_circ_float();
    return 0;
}