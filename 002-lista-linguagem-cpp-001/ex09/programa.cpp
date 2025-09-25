#include <iostream>

int MDC(unsigned int a, unsigned int b){
    while (b != 0){
        unsigned int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int MMC(unsigned int a, unsigned int b){
    return a * (b / MDC(a,b));
}

struct fracao{
    int numerador;
    int denominador;
};

fracao soma(fracao &f1, fracao &f2){
  int m = MMC(f1.denominador, f2.denominador);
  fracao f3;
  f3.numerador = (f1.numerador * (m / f1.denominador)) + (f2.numerador * (m / f2.denominador));
  f3.denominador = m; 
  return f3;
}

int main(){
  fracao f1, f2;
  std::cin >> f1.numerador >> f1.denominador >> f2.numerador >> f2.denominador;
  fracao s = soma(f1, f2);
  std::cout << "Fração:\n" << s.numerador << "/" << s.denominador << std::endl;
  return 0;
}