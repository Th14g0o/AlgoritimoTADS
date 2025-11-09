#include <iostream>

char usando_se(int x, int y, int l1, int h1, int l2, int h2){
    // nenhuma foto girada
    if ((l1 + l2 <= x && h1 <= y && h2 <= y) ||
        (l1 + l2 <= y && h1 <= x && h2 <= x) ||
        (l1 <= x && l2 <= x && h1 + h2 <= y) ||
        (l1 <= y && l2 <= y && h1 + h2 <= x)) 
        return 'S';
    
    // foto1 girada, foto2 normal
    if (((h1 + l2) <= x && l1 <= y && h2 <= y) ||
        ((h1 + l2) <= y && l1 <= x && h2 <= x) ||
        (h1 <= x && l2 <= x && l1 + h2 <= y) ||
        (h1 <= y && l2 <= y && l1 + h2 <= x)) 
        return 'S';
    
    // foto1 normal, foto2 girada
    if (((l1 + h2) <= x && h1 <= y && l2 <= y) ||
        ((l1 + h2) <= y && h1 <= x && l2 <= x) ||
        (l1 <= x && h2 <= x && h1 + l2 <= y) ||
        (l1 <= y && h2 <= y && h1 + l2 <= x)) 
        return 'S';
    
    // ambas giradas
    if (((h1 + h2) <= x && l1 <= y && l2 <= y) ||
        ((h1 + h2) <= y && l1 <= x && l2 <= x) ||
        (h1 <= x && h2 <= x && l1 + l2 <= y) ||
        (h1 <= y && h2 <= y && l1 + l2 <= x)) 
        return 'S';

    return 'N';
}

int main(){
    int x, y, l1, h1, l2, h2;
    std::cin >> x >> y;
    std::cin >> l1 >> h1;
    std::cin >> l2 >> h2;
    usando_se(x, y, l1, h1, l2, h2);
    return 0;
}