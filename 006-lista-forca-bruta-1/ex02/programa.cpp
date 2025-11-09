#include <iostream>
#include <chrono>
#include <cstdlib> // For rand() and srand(

bool soma_array(int vetor[], int& n, int& s){
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (vetor[i] + vetor[j] == s) 
                return true;
    return false;
}

int main(){
    int n, s;
    std::cin >> n >> s;
    int vetor[n];
    for (int i = 0; i < n; i++) vetor[i] = rand() % 100 + 1;
    // Início do cronômetro
    auto beg = std::chrono::high_resolution_clock::now();
    bool p = soma_array(vetor, n, s);
    // Fim do cronômetro
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << (p ? "Existe" : "Não existe") << std::endl;

    auto dur = end - beg; // Duração do cronômetro
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
    std::cerr << "Tempo de processamento: "  << duration.count() << " millisecond(s)" << std::endl;
    std::cout << n  << " | " << duration.count()  << std::endl;

    return 0;
}