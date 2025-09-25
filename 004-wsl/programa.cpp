#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i<n; i++){
        int g;
        std::cin >> g;
        a[i] = g;
    }
    std::cout << n << "\n";
    for (int i = 0; i<n; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}