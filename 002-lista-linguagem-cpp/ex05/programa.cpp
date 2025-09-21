#include <iostream>

unsigned short qtd_divs(unsigned int &n){
    unsigned short divs = 0;
    for (unsigned int i = 1; i < n; i++){
        if (n % i == 0) divs = divs + 1;
    }
    return divs;
}

int main(){
    unsigned int n;
    std::cin >> n;
    unsigned short divs = qtd_divs(n);
    std::cout << divs;
    return divs;
}