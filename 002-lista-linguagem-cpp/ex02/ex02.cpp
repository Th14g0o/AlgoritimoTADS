#include <iostream>

double perimetro(int l1, int l2){
    return 2 * (l1 + l2)
}

int main(){
    double l1, l2;
    std::cin >> l1 >> l2;
    double p = perimetro(l1, l2);
    std::cout << p << endl;
    return 0;
}