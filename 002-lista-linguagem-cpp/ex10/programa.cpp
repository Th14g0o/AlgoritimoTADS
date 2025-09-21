#include <iostream>
#include <iomanip>

double metodo_babilonico(double &n){
    double candidato = n / 2.0;
    double r = (candidato + n / candidato) / 2.0;

    while (candidato - r > 0.001) {
        candidato = r;
        r = (candidato + n / candidato) / 2.0;
    }

    return r;
}

int main(){
    double n;
    std::cin >> n;
    double rq = metodo_babilonico(n);
    std::cout << "Raiz: " << std::fixed << std::setprecision(3) << rq << std::endl;
    return 0;
}