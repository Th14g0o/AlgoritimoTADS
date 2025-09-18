#include <iostream>

int perimetro(int l1, int l2){
    return 2 * (l1 + l2)
}

void main(){
    int l1, l2;
    std::cin >> l1 >> l2 >> endl;
    int p = perimetro(l1, l2)
    std::cout << p << endl;
}