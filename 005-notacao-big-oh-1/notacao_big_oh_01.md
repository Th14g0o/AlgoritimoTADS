## Questão 1
Enunciado: Um algoritmo realiza `n^2 + 2n + 2` operações primitivas no pior caso. Determine a sua complexidade (big-O) e explique.

**Resposta:** O termo de maior ordem domina quando `n` cresce. O termo dominante é `n^2`. Portanto a complexidade é **O(n^2)**.

**Explicação curta:** `n^2 + 2n + 2 = Θ(n^2)`. Ao tomar apenas o comportamento assintótico superior, descartamos constantes e termos de ordem inferior.

## Questão 2
Ordene as funções pela ordem de complexidade (do menor para o maior):

Funções: `n^2`, `n`, `log2 n`, `2^n`, `n log2 n`, `n^3`.

**Resposta (do menor para o maior):**
1. `log2 n`
2. `n`
3. `n log2 n`
4. `n^2`
5. `n^3`
6. `2^n`

**Breve justificativa:** logarítmico < polinomial linear < polinomial com fator log < polinomial quadrático < cúbico < exponencial.

## Questão 3
Enunciado: Dado um array `A` de `n` inteiros, retornar a maior diferença entre dois elementos consecutivos de `A`.

### Questão 3(a)
**Equação de tempo de execução:**
- O algoritmo percorre o array uma vez calculando diferenças consecutivas, realiza `n-1` subtrações e comparações.
- Equação: `T(n) = c*(n-1)` para alguma constante `c`.

### Questão 3(b)
**Complexidade (pior caso):** **O(n)**.

### Questão 3(c)
**Programa em C++ (usando `new` / arrays simples):**
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int *A = new int[n];
    for (int i = 0; i < n; ++i) cin >> A[i];

    int maior = abs(A[1] - A[0]);
    for (int i = 1; i < n; ++i) {
        int d = abs(A[i] - A[i-1]);
        if (d > maior) maior = d;
    }

    cout << maior << '\n';
    delete[] A;
    return 0;
}
```

### Questão 3(d)
Tabela de exemplo (tempos fictícios medidos):

| n (tamanho) | tempo (ms) |
|-----------:|-----------:|
| 100        | 0.1        |
| 1.000      | 0.8        |
| 10.000     | 6.5        |
| 100.000    | 62         |


## Questão 4
Enunciado: Retornar a quantidade (comprimento) da maior sublista contígua não decrescente em `A`.

### Questão 4(a)
**Equação de tempo de execução:**
- Percorre o array uma vez, mantendo um contador para o comprimento da sequência corrente e o melhor até agora.
- `T(n) = c * n`.

### Questão 4(b)
**Complexidade (pior caso):** **O(n)**.

### Questão 4(c)
**Programa em C++:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int *A = new int[n];
    for (int i = 0; i < n; ++i) cin >> A[i];

    int melhor = 1;
    int atual = 1;
    for (int i = 1; i < n; ++i) {
        if (A[i-1] <= A[i]) {
            atual++;
        } else {
            if (atual > melhor) melhor = atual;
            atual = 1;
        }
    }
    if (atual > melhor) melhor = atual;

    cout << melhor << '\n';
    delete[] A;
    return 0;
}
```

### Questão 4(d)
Tabela de exemplo (tempos fictícios):

| n | tempo (ms) |
|--:|-----------:|
| 100 | 0.1 |
| 1.000 | 0.9 |
| 10.000 | 7.0 |

## Questão 5
Enunciado: Dado `A` de n inteiros e um inteiro `s`, determine se existe um par cuja soma seja `s`.

### Questão 5(a)
**Equação de tempo (força bruta):** testar todos os pares `i<j` → `T(n) = c * n*(n-1)/2 = O(n^2)`.

**Observação (algoritmo ótimo):** com uma tabela de hashing ou com ordenação + dois ponteiros é possível obter `O(n)` (hash) ou `O(n log n)` (ordenar) no pior caso. Porém o enunciado pede implementar — aqui apresentamos a versão força bruta e uma versão com contagem quando os valores estão em intervalo limitado.

### Questão 5(b)
**Complexidade (pior caso, força bruta):** **O(n^2)**.

### Questão 5(c)**
**Implementação força bruta em C++ (arrays):**
```cpp
#include <iostream>
using namespace std;

int main() {
    int n, s;
    if (!(cin >> n >> s)) return 0;
    int *A = new int[n];
    for (int i = 0; i < n; ++i) cin >> A[i];

    bool existe = false;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (A[i] + A[j] == s) { existe = true; break; }
        }
        if (existe) break;
    }

    cout << (existe ? 'S' : 'N') << '\n';
    delete[] A;
    return 0;
}
```

> Versão com contagem (quando valores são pequenos e não negativos, seguindo a dica): aloque `int C[MAXV+1]` inicializado com zeros, percorra `A` e para cada `A[i]` verifique se `s-A[i]` está dentro do intervalo e `C[s-A[i]]>0`. Complexidade `O(n + MAXV)` e memória `O(MAXV)`.

### Questão 5(d)
Tabela de exemplo (tempos fictícios, força bruta):

| n | tempo (ms) |
|--:|-----------:|
| 100 | 2.0 |
| 1.000 | 180 |
| 5.000 | 4800 |


## Questão 6
Para cada expressão determine O(...):

(a) `2^n + 8 + 2n` → **O(2^n)** 

(b) `10n + 50` → **O(n)**

(c) `10 + 2n^2 + n` → **O(n^2)**

(d) `100 + 20 log2 n` → **O(log n)**

(e) `50n + 2^n + 200` → **O(2^n)** 

(f) `1000 + 3 n log2 n + 300 n` → **O(n log n)** 

(g) `log2 n + 5n` → **O(n)**

(h) `n^2 - 400n + 50 n^3` → **O(n^3)**

## Questão 7
Estime o tempo de execução (big-O) das funções em C++.

### Questão 7(a)
```cpp
int fA(int n){
  int i,a=1;
  for (i=0; i<n; i++){
    a += i;
  }
  return a;
}
```
**Complexidade:** O(n)

### Questão 7(b)
```cpp
int fB(int n){
  int i, a=1;
  for (i=1; i<=n; i*=2){
    a += i;
  }
  return a;
}
```
**Complexidade:** O(log n) — o loop dobra `i` a cada iteração.

### Questão 7(c)
```cpp
int fC(int n){
  int i,j,x=1,y;
  for (i=0; i<n; i++){
    y = 2;
    for (j=1; j<=n; j++){
      y += j;
    }
    x *= y;
  }
  return x;
}
```
**Complexidade:** O(n^2) — loop externo n vezes e interno n vezes.

### Questão 7(d)
```cpp
int fD(int n){
  int i,x=n,y=0;
  for (i=0; i<512; i++){
    y += x;
    if (i%7==0 && i<2*n) x++;
  }
  return y;
}
```
**Complexidade:** O(1) — o número de iterações é constante (512), independente de n; incrementos condicionais não mudam a ordem assintótica.

### Questão 7(e)
```cpp
int fE(int n){
  int i,j,x=1,y=0;
  for (i=n; i>0; i=i/2){
    y += x;
    for (j=0; j<n/2; j++){
      if (n%j==0) y++;
    }
  }
  return y;
}
```
**Análise e Complexidade:**
- O loop externo executa O(log n) iterações (i reduz pela metade cada vez).
- O loop interno, como escrito, é `for (j=0; j<n/2; j++)` → executa ~n/2 vezes; a operação interna é O(1) (a expressão `n%j` é O(1)).
- Total: O((n) * log n) = **O(n log n)**.

> Observação: cuidado com `n%j` quando `j==0` — no código real é necessário evitar divisão por zero. Aqui mantivemos a estrutura como no enunciado e assumimos `j` inicia em 1.

## Questão 8
Vírus que dobra a cada dia: dado população `P`, quantos dias até todos estarem infectados (começando com 1 infectado)?

**Solução:** o número de infectados no dia `d` é `2^d`. Queremos o menor `d` tal que `2^d >= P`. Então `d = ceil(log2 P)`.

**Complexidade:** calcular por loop que dobra um contador até alcançar `P` leva O(log P).

**Implementação em C++:**
```cpp
#include <iostream>
using namespace std;

int main(){
  long long P;
  if (!(cin >> P)) return 0;
  long long infect = 1;
  int dias = 0;
  while (infect < P) { infect *= 2; dias++; }
  cout << dias << " dia(s)\n";
  return 0;
}
```

---
## Questão 9
Material que perde metade da massa a cada período `t` (segundos). Dada massa inicial `mi` (real) e período `t`, determinar quanto tempo (segundos) até a massa ser ≤ 1g.

**Solução:** repetir multiplicação por 0.5 até `mi <= 1`. Cada passo soma `t` segundos. Número de passos `k = ceil(log2(mi))` ⇒ tempo total `k * t`.

**Complexidade:** O(log mi) passos ⇒ **O(log mi)**.

**Implementação em C++:**
```cpp
#include <iostream>
using namespace std;

int main(){
  int t; double mi;
  if (!(cin >> t >> mi)) return 0;
  int segundos = 0;
  while (mi > 1.0) { mi /= 2.0; segundos += t; }
  cout << segundos << " segundos(s)\n";
  return 0;
}
```

## Questão 10
Enunciado: Dado `A` (n inteiros, `1 <= n <= 1e5`), determinar a quantidade de elementos distintos em `A`.

### Questão 10(a)
**Complexidade usando contagem (dica):**
- Se os valores de `A[i]` estão limitados (por exemplo `0 <= A[i] <= MAXV` com `MAXV = 100000`), podemos usar um array `C[0..MAXV]` para contar ocorrências em `O(n + MAXV)` tempo e `O(MAXV)` memória. Para o problema prático isso é aceitável. Assim a complexidade é **O(n + MAXV)**, que para `MAXV` constante é **O(n)**.

### Questão 10(b)
**Implementação em C++ (usando array de contagem):**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int n;
  if (!(cin >> n)) return 0;
  const int MAXV = 100000; 
  int *C = new int[MAXV+1];
  for (int i = 0; i <= MAXV; ++i) C[i] = 0;

  int *A = new int[n];
  int maxSeen = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    if (A[i] >= 0 && A[i] <= MAXV) {
      C[A[i]]++;
      if (A[i] > maxSeen) maxSeen = A[i];
    }
  }

  int distinct = 0;
  for (int v = 0; v <= maxSeen; ++v) if (C[v] > 0) distinct++;

  cout << distinct << '\n';

  delete[] A;
  delete[] C;
  return 0;
}
```

