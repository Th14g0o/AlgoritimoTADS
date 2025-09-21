#include <iostream>
#include <cmath>

int main(){
    int rua, dist, dist_ultimos, qtd;
    std::cout << "Digite a rua e a distancia, nessa ordem, separados por espaço: ";
    std::cin >> rua >> dist;

    qtd = rua / dist + 1;
    dist_ultimos = dist;
    if (rua % dist != 0) {
        qtd = qtd + 1;
        dist_ultimos = 1000 - dist * (qtd - 2);
    }
    
    std::cout << "Qtd Postes: " << qtd << "\nDistancias entre ultimo poste: " << dist_ultimos << std::endl;
    return 0;
}