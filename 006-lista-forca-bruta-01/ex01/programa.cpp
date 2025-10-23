#include <iostream>

int main(){
    int x, y, l1, h1, l2, h2;
    std::cin >> x >> y;
    std::cin >> l1 >> h1;
    std::cin >> l2 >> h2;
    if ((((l1 + l2 <= x and h1 <= y and h2 <= y)) or ((h1 + h2 <= y and l1 <= x and l2 <= x)))) 
        std::cout << "S" << std::endl;
    else 
        std::cout << "N" << std::endl;
    return 0;
}