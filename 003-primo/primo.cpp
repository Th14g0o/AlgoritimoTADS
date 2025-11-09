#include <iostream>
#include <chrono>

bool primo(long long n){
    if (n == 1) return false;
    if (n == 2) return true;
    for (long long d = 3; d*d <= n; ++d) if (n%d == 0) return false;
    return true;
}

int main() {
    long long n;
    std::cin >> n;

    // Início do cronômetro
    auto beg = std::chrono::high_resolution_clock::now();
    bool p = primo(n);
    // Fim do cronômetro
    auto end = std::chrono::high_resolution_clock::now();

    if (p) std::cout <<  n << " eh primo" << std::endl;
    else std::cout << n << " nao eh primo" << std::endl;

    auto dur = end - beg; // Duração do cronômetro
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(dur);
    std::cerr << n << " Tempo de processamento: "  << duration.count() << " Microsegundo(s)" << std::endl;

    std::cout << n << " Tempo de processamento: "  << duration.count() << " Microsegundo(s)" << std::endl;
    
    return 0;
}