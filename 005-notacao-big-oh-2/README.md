## 1(a)
A função possui dois loops aninhados, cada um percorrendo `N` vezes.

## 1(b)
O primeiro loop executa `N²` vezes, e o interno `N` vezes. **O(N²)**

## 1(c)
O segundo loop depende de `i`, somando 1 até `i`. A soma total é (N² - N)/2.

Complexidade: **O(N²)**

## 1(d)
Três loops: `i` até `N`, `j` até `N²` e `k` até `j`. O loop mais interno depende de `j`, gerando somatório até `N⁴/2`.

Complexidade: **O(N⁴)**

## 1(e)
O primeiro loop vai até `n`, o segundo vai até `n/2` (porque incrementa de 2 em 2).

Complexidade: **O(N²)**

## 1(f)
O primeiro loop é constante (`50/2 = 25` iterações). O segundo depende de `n/3`.

Complexidade: **O(N)**

## 1(g)
Loop externo até `m`, interno com multiplicação `j *= 2`, o que é logarítmico em `n`.

Complexidade: **O(M log N)**

## 1(h)
Primeiro loop até `m²`, segundo até `m`.

Complexidade: **O(M² + M) = O(M²)**

## 1(i)
Externo até `m`, interno até `n/2`.

Complexidade: **O(MN)**

## 1(j)
Dois loops independentes: um até `m` e outro até `n`.

Complexidade: **O(M + N)**

## 2(a)
**Algoritmo:**

Crie um array `C` com tamanho igual ao valor máximo possível de `A[i]` (ex: `105001`).
Para cada elemento de `A`, incremente `C[A[i]]`. O valor em `C[i]` indica quantas vezes `i` ocorre em `A`.

## 2(b)
Percorremos o array `A` uma vez e o array `C` até o valor máximo.

Complexidade: **O(N + K)** (onde `K` é o valor máximo possível dos elementos, constante limitada por 10⁵ → O(N)).

## 2(c)
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<int> C(100001, 0);
    for (int i = 0; i < n; i++) C[A[i]]++;

    for (int i = 0; i < 100001; i++) {
        if (C[i] > 0)
            cout << i << " ocorre " << C[i] << " vezes\n";
    }
}
```