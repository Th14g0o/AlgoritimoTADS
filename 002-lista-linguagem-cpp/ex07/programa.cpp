#include <iostream>

bool primo(unsigned int &a, unsigned int &b){
    bool primos = true;
    unsigned int &n = a > b ? b : a;
    for (unsigned int i = 2; i <= n; i++){
        if (a % i == 0 && b % i == 0) primos = false;
    }
    return primos;
}

int main(){
    unsigned int a, b;
    std::cin >> a >> b;
    bool p = primo(a, b);
    std::cout << (p ? "São primos entre si" : "Não são primos entre si");
    return 0;
}