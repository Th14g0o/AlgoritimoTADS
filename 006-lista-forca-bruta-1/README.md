## 1 (a) 
#### testar todas as orientações possiveis das fotos(as duas deitadas, uma deitada e a outra em pe, uma em pé e a outra deita, as duas em pé) e em cada orientação testar se cabem lado a lado ou uma encima da outra

## 1 (b) 
####  O(1), constante

## 1 (c)
```cpp
char usando_se(int x, int y, int l1, int h1, int l2, int h2){
    if ((l1 + l2 <= x && h1 <= y && h2 <= y) ||
        (l1 + l2 <= y && h1 <= x && h2 <= x) ||
        (l1 <= x && l2 <= x && h1 + h2 <= y) ||
        (l1 <= y && l2 <= y && h1 + h2 <= x)) 
        return 'S';
    
    if (((h1 + l2) <= x && l1 <= y && h2 <= y) ||
        ((h1 + l2) <= y && l1 <= x && h2 <= x) ||
        (h1 <= x && l2 <= x && l1 + h2 <= y) ||
        (h1 <= y && l2 <= y && l1 + h2 <= x)) 
        return 'S';
    
    if (((l1 + h2) <= x && h1 <= y && l2 <= y) ||
        ((l1 + h2) <= y && h1 <= x && l2 <= x) ||
        (l1 <= x && h2 <= x && h1 + l2 <= y) ||
        (l1 <= y && h2 <= y && h1 + l2 <= x)) 
        return 'S';
    
    if (((h1 + h2) <= x && l1 <= y && l2 <= y) ||
        ((h1 + h2) <= y && l1 <= x && l2 <= x) ||
        (h1 <= x && h2 <= x && l1 + l2 <= y) ||
        (h1 <= y && h2 <= y && l1 + l2 <= x)) 
        return 'S';

    return 'N';
}
```

### 2 (a) 
#### 2 laços, onde um percorrera todos os n elementos do array e o segundo pegara todos os elementos apos o elemento atual do primeiro laço. No segundo laço se deve vericar soma o elemento do primeiro laço com o do segundo é igual ao valor de S, se for igual retorna true. apos os laços retorne false.
```bash
N = 4, S = 2
v[0] = 10
v[1] = 1
v[2] = 2
v[3] = 0

v[0]
  v[1] não igual 
  v[2] não igual
  v[3] não igual

v[1]
  v[2] não igual
  v[3] não igual

v[2]
  v[3] retorna true
```

### 2 (b) 
#### O(n²)

### 2 (c)
```cpp
bool soma_array(int vetor[], int& n, int& s){
    for (int i = 0; i < n; i++) // n
        for (int j = i + 1; j < n; j++) // n - 1
            if (vetor[i] + vetor[j] == s) // 2
                return true;  // 1
    return false;
}
```

### 2 (d)
```cpp
#include <iostream>

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
    for (int i = 0; i < n; i++) std::cin >> vetor[i];
    std::cout << (soma_array(vetor, n, s) ? "Existe" : "Não existe") << std::endl;
    return 0;
}
```

### 2 (e)
N | Tempo(milisegundos)
:-----:|:-----:
100 | 0
1000 | 3
10000 | 153
100000 | 11889


### 2 (f)
![graf](ex02/graf.png)


## 3(a)
Para cada sublista possível `(i, j)`, some os elementos e mantenha o maior valor.

## 3(b)
 **O(N³)** se somar dentro do loop, **O(N²)** se acumular incrementalmente.

## 3(c)
```cpp
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& A) {
    int n = A.size(), maxSum = A[0];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
```

## 4(a)
Compare a distância entre cada par de pontos `(i, j)` e mantenha o menor.

## 4(b)
**O(N²)**

## 4(c)
```cpp
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Ponto { double x, y; };

double dist(Ponto a, Ponto b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int n; cin >> n;
    vector<Ponto> pts(n);
    for (auto &p : pts) cin >> p.x >> p.y;

    double minDist = 1e9; Ponto p1, p2;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            double d = dist(pts[i], pts[j]);
            if (d < minDist) { minDist = d; p1 = pts[i]; p2 = pts[j]; }
        }
    cout << "(" << p1.x << "," << p1.y << ") e (" << p2.x << "," << p2.y << ")";
}
```

## 5(a)
Verificar todos os trios de pontos `(i, j, k)` e testar se formam triângulo retângulo usando o Teorema de Pitágoras.

## 5(b)
**O(N³)**

## 5(c)
```cpp
#include <cmath>
#include <vector>
using namespace std;

struct P { double x, y; };

bool retangulo(P a, P b, P c) {
    double ab2 = pow(a.x-b.x,2)+pow(a.y-b.y,2);
    double bc2 = pow(b.x-c.x,2)+pow(b.y-c.y,2);
    double ca2 = pow(c.x-a.x,2)+pow(c.y-a.y,2);
    return fabs(ab2+bc2-ca2)<1e-6 || fabs(ab2+ca2-bc2)<1e-6 || fabs(bc2+ca2-ab2)<1e-6;
}
```