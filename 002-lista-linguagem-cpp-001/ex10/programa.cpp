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

// professor
double metodo_babilonico_rec(double &n, double r){
    double r_candidato = (r + (n/r)) / 2;
    double resultado = r_candidato - r;
    if (resultado < 0) resultado = resultado * -1;
    if (resultado < 0.001) return r_candidato;
    return metodo_babilonico_rec(n, r_candidato); 
}

double metodo_babilonico_laco_apartir_prof(double &n, double r){
    double r_antigo = r;
    double r_candidato = (r_antigo + (n/r_antigo)) / 2;
    double resultado = r_candidato - r_antigo;
    if (resultado < 0) resultado = resultado * -1;
    while (resultado > 0.001) {
        r_antigo = r_candidato;
        r_candidato = (r_antigo + (n/r_antigo)) / 2;
        resultado = r_candidato - r_antigo;
        if (resultado < 0) resultado = resultado * -1;
    }
    return r_candidato; 
}

int main(){
    double n;
    std::string continua = "s";
    while (continua == "s"){
        std::cout << "Digite um numero" << std::endl;
        std::cin >> n;
        double rq = metodo_babilonico(n);
        std::cout << "Raiz(Minha tentativa): " << std::fixed << std::setprecision(3) << rq << std::endl;

        rq = metodo_babilonico_rec(n, n / 2.0);
        std::cout << "Raiz(Professor, rec): " << std::fixed << std::setprecision(3) << rq << std::endl;

        rq = metodo_babilonico_laco_apartir_prof(n, n / 2.0);
        std::cout << "Raiz(A partir da do professor): " << std::fixed << std::setprecision(3) << rq << std::endl;
        std::cout << "-------------" << std::endl;
        std::cin >> continua;
    }
   
    return 0;
}