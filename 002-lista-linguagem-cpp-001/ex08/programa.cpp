#include <iostream>

unsigned int MDC(unsigned int a, unsigned int b){
    while (b != 0){
        unsigned int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    unsigned int a, b;
    std::cout << "Digite dois numeros: ";
    std:: cin >> a >> b;
    unsigned int mdc = MDC(a, b);
    std::cout << "MDC: " << mdc;
    return 0;
}