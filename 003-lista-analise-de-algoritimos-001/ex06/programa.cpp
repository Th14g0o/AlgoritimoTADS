#include <chrono>
#include <iostream>

bool primo_algo1(long long n) {
    int divs = 0;
    for (long long d = 1; d <= n; ++d)
        if (n % d == 0) divs = divs + 1;
    return divs == 2;
}

bool primo_algo2(long long n) {
    int divs = 0;
    for (long long d = 1; d <= n / 2; ++d)
        if (n % d == 0) divs = divs + 1;
    return divs == 1;
}

bool primo_algo3(long long n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int q_divs = 1;
    for (long long d = 3; d <= n / 2; ++d)
        if (n % d == 0) q_divs = q_divs + 1;
    return q_divs == 1;
}

bool primo_algo4(long long n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    bool p = true;
    long long d = 3;
    while (p && d <= n / 2){
        if (n % d == 0) p = false;
        d = d + 2;
    }
    return p;
}

int main() {
    for (int i = 0; i < 20; i++){
        long long n;
        std::cin >> n;

        // Início do cronômetro
        auto beg = std::chrono::high_resolution_clock::now();
        bool p = primo_algo1(n);
        // Fim do cronômetro
        auto end = std::chrono::high_resolution_clock::now();

        if (p) std::cout << "algo1 : "<< i << " | " << n << " is prime" << std::endl;
        else std::cout << "algo1 : "<< i << " | " << n << " is not prime" << std::endl;

        auto dur = end - beg; // Duração do cronômetro
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
        std::cerr << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;

        std::cout << "algo1 : "<< i << " | " << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;
    }

    for (int i = 0; i < 20; i++){
        long long n;
        std::cin >> n;

        // Início do cronômetro
        auto beg = std::chrono::high_resolution_clock::now();
        bool p = primo_algo2(n);
        // Fim do cronômetro
        auto end = std::chrono::high_resolution_clock::now();

        if (p) std::cout << "algo2 : "<< i << " | " << n << " is prime" << std::endl;
        else std::cout << "algo2 : "<< i << " | " << n << " is not prime" << std::endl;

        auto dur = end - beg; // Duração do cronômetro
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
        std::cerr << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;

        std::cout << "algo2 : "<< i << " | " << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;
    }

    for (int i = 0; i < 20; i++){
        long long n;
        std::cin >> n;

        // Início do cronômetro
        auto beg = std::chrono::high_resolution_clock::now();
        bool p = primo_algo3(n);
        // Fim do cronômetro
        auto end = std::chrono::high_resolution_clock::now();

        if (p) std::cout << "algo3 : "<< i << " | " << n << " is prime" << std::endl;
        else std::cout << "algo3 : "<< i << " | " << n << " is not prime" << std::endl;

        auto dur = end - beg; // Duração do cronômetro
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
        std::cerr << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;

        std::cout << "algo3 : "<< i << " | " << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;
    }

    for (int i = 0; i < 20; i++){
        long long n;
        std::cin >> n;

        // Início do cronômetro
        auto beg = std::chrono::high_resolution_clock::now();
        bool p = primo_algo4(n);
        // Fim do cronômetro
        auto end = std::chrono::high_resolution_clock::now();

        if (p) std::cout << "algo4 : "<< i << " | " << n << " is prime" << std::endl;
        else std::cout << "algo4 : "<< i << " | " << n << " is not prime" << std::endl;

        auto dur = end - beg; // Duração do cronômetro
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
        std::cerr << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;

        std::cout << "algo4 : "<< i << " | " << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;
    }

    for (int i = 0; i < 20; i++){
        long long n;
        std::cin >> n;

        // Início do cronômetro
        auto beg = std::chrono::high_resolution_clock::now();
        bool p = primo_algo1(n);
        // Fim do cronômetro
        auto end = std::chrono::high_resolution_clock::now();

        if (p) std::cout << "algo1 : "<< i << " | " << n << " is prime" << std::endl;
        else std::cout << "algo1 : "<< i << " | " << n << " is not prime" << std::endl;

        auto dur = end - beg; // Duração do cronômetro
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
        std::cerr << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;

        std::cout << "algo1 : "<< i << " | " << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;
    }

    for (int i = 0; i < 20; i++){
        long long n;
        std::cin >> n;

        // Início do cronômetro
        auto beg = std::chrono::high_resolution_clock::now();
        bool p = primo_algo2(n);
        // Fim do cronômetro
        auto end = std::chrono::high_resolution_clock::now();

        if (p) std::cout << "algo2 : "<< i << " | " << n << " is prime" << std::endl;
        else std::cout << "algo2 : "<< i << " | " << n << " is not prime" << std::endl;

        auto dur = end - beg; // Duração do cronômetro
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
        std::cerr << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;

        std::cout << "algo2 : "<< i << " | " << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;
    }

    for (int i = 0; i < 20; i++){
        long long n;
        std::cin >> n;

        // Início do cronômetro
        auto beg = std::chrono::high_resolution_clock::now();
        bool p = primo_algo3(n);
        // Fim do cronômetro
        auto end = std::chrono::high_resolution_clock::now();

        if (p) std::cout << "algo3 : "<< i << " | " << n << " is prime" << std::endl;
        else std::cout << "algo3 : "<< i << " | " << n << " is not prime" << std::endl;

        auto dur = end - beg; // Duração do cronômetro
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
        std::cerr << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;

        std::cout << "algo3 : "<< i << " | " << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;
    }

    for (int i = 0; i < 20; i++){
        long long n;
        std::cin >> n;

        // Início do cronômetro
        auto beg = std::chrono::high_resolution_clock::now();
        bool p = primo_algo4(n);
        // Fim do cronômetro
        auto end = std::chrono::high_resolution_clock::now();

        if (p) std::cout << "algo4 : "<< i << " | " << n << " is prime" << std::endl;
        else std::cout << "algo4 : "<< i << " | " << n << " is not prime" << std::endl;

        auto dur = end - beg; // Duração do cronômetro
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
        std::cerr << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;

        std::cout << "algo4 : "<< i << " | " << n << " Processing time: "  << duration.count() << " milliseconds(s)" << std::endl;
    }
    
    return 0;
}