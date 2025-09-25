#include <iostream>

bool primo(unsigned int &n){
    unsigned short divs = 0;
    for (unsigned int i = 1; i <= n; i++){
        if (n % i == 0) divs = divs + 1;
    }
    return divs == 2;
}

int main(){
    unsigned int n;
    std::cin >> n;
    bool p = primo(n);
    std::cout << (p ? "É primo" : "Não é primo");
    return 0;
}