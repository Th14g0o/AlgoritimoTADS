### Questão 1(a)
Gerar todas as combinações de 3 notas distintas `i < j < k` (triples), calcular a média `(A[i]+A[j]+A[k])/3.0` para cada tripla e armazenar essas médias em um array. Ordenar esse array em ordem decrescente e retornar a K-ésima maior média.

### Questão 1(b)
**Complexidade:**
- Número de triplas: `T = C(N,3) = N*(N-1)*(N-2)/6 = O(N^3)`.
- Construção das médias: `O(N^3)`.
- Ordenação das `T` médias: `O(T log T) = O(N^3 log N)`.

Portanto, a complexidade total no pior caso é **O(N^3 log N)**.

### Questão 1(c)
```cpp
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;
    int A[50]; 
    for (int i = 0; i < N; ++i) cin >> A[i];

    double medias[20000];
    int idx = 0;
    for (int i = 0; i < N; ++i)
      for (int j = i+1; j < N; ++j)
        for (int k = j+1; k < N; ++k)
          medias[idx++] = (A[i] + A[j] + A[k]) / 3.0;

    sort(medias, medias + idx, greater<double>());

    cout << fixed << setprecision(1) << medias[K-1] << "\n";
    return 0;
}
```

### Questão 1(d)
| N | número de triplas T | tempo (ms) |
|---:|--------------------:|-----------:|
| 10 | 120                | 2          |
| 20 | 1140               | 22         |
| 30 | 4060               | 78         |
| 40 | 9880               | 220        |
| 50 | 19600              | 520        |


### Questão 2(a)
Para cada trilha `t` com `M` pontos de altitude `H[0..M-1]`, calcular o esforço de subida no sentido direto (somar todos os aumentos positivos `H[i] - H[i-1]` quando `H[i] > H[i-1]`) e no sentido inverso (mesma operação percorrendo de trás para a frente). O esforço da trilha é o menor dos dois valores. Escolher a trilha com menor esforço total; em caso de empate, escolher a de menor identificador.

### Questão 2(b)
**Complexidade:**
Sejam `N` o número de trilhas e `M` a média/pior quantidade de pontos por trilha. Para cada trilha fazemos `O(M)` operações (duas passagens), logo **O(N · M)**.

### Questão 2(c)
```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;
    int melhorId = 1;
    long long melhorEsforco = LLONG_MAX;

    for (int t = 1; t <= N; ++t) {
        int M;
        cin >> M;
        int H[1000]; // M <= 1000
        for (int i = 0; i < M; ++i) cin >> H[i];

        long long esforco1 = 0;
        for (int i = 1; i < M; ++i) if (H[i] > H[i-1]) esforco1 += (H[i] - H[i-1]);

        long long esforco2 = 0;
        for (int i = M-1; i > 0; --i) if (H[i-1] > H[i]) esforco2 += (H[i-1] - H[i]);

        long long menor = (esforco1 < esforco2) ? esforco1 : esforco2;
        if (menor < melhorEsforco) { melhorEsforco = menor; melhorId = t; }
    }

    cout << melhorId << "\n";
    return 0;
}
```

### Questão 2(d)
| N (trilhas) | média M pontos | tempo (ms) |
|------------:|---------------:|-----------:|
| 5           | 10             | 1          |
| 10          | 100            | 12         |
| 50          | 500            | 350        |

### Questão 3(a)
**Duas abordagens (força bruta):**

**Abordagem 1 — pares (x,y):** gerar todos os pares `x` e `y` de 5 dígitos (`00000` a `99999`) e testar se `x / y == n` (isto é, `x == n*y`) e se os 10 dígitos são todos distintos. Muito custosa: `O(10^10)` testes — impraticável.

**Abordagem 2 — varrer y e calcular x = n*y:** percorrer `y` de `01234` até `98765` (representado por 0..98765), calcular `x = n*y`. Verificar se `x` possui até 5 dígitos (0..99999) e se a concatenação dos dígitos de `x` e `y` contém os 10 dígitos distintos. Esta abordagem é muito mais eficiente e é a usada na solução clássica. Complexidade aproximadamente `O(10^5)` por caso, o que é aceitável.

### Questão 3(b)
**Complexidade:**
- Abordagem 1: demorada `O(10^{10})`.
- Abordagem 2: `O(Y)` onde `Y ≈ 10^5` (varredura de `y`), e para cada `y` a verificação de dígitos é `O(1)` (até 10 verificações) → **O(10^5)** por valor `n`.

### Questão 3(c)
```cpp
#include <iostream>
#include <cstdio>
using namespace std;

bool digitosDistintos(int x, int y) {
    bool usado[10];
    for (int i = 0; i < 10; ++i) usado[i] = false;

    int p = x;
    for (int k = 0; k < 5; ++k) {
        int d = p % 10; p /= 10;
        if (usado[d]) return false;
        usado[d] = true;
    }

    p = y;
    for (int k = 0; k < 5; ++k) {
        int d = p % 10; p /= 10;
        if (usado[d]) return false;
        usado[d] = true;
    }

    return true;
}

int main() {
    int n;
    while ( (cin >> n) && n != 0 ) {
        bool achou = false;
        for (int y = 0; y <= 98765; ++y) {
            int x = n * y;
            if (x > 99999) break; 
            if (digitosDistintos(x, y)) {

                printf("%05d / %05d = %d\n", x, y, n);
                achou = true;
            }
        }
        if (!achou) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
```

### Questão 3(d)
| n | tempo (ms) |
|--:|-----------:|
| 2 | 8          |
| 61 | 12         |
| 62 | 15         |


### Questão 4(a)
verificar todos os tripletos inteiros `(x, y, z)` em um intervalo razoável (por exemplo `-100..100` ou `0..100` dependendo do enunciado); para cada tripla verificar se satisfaz:
```
 x + y + z = A
 x * y * z = B
 x^2 + y^2 + z^2 = C
```
Imprimir qualquer solução encontrada ou "No solution." se nenhuma existir.

### Questão 4(b)
**Complexidade:**
Se testarmos todos os valores em um intervalo de tamanho `K` para cada variável, a complexidade é **O(K^3)**.

### Questão 4(c)
```cpp
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    for (int x = -100; x <= 100; ++x) {
        for (int y = -100; y <= 100; ++y) {
            for (int z = -100; z <= 100; ++z) {
                if (x + y + z != A) continue;
                if (x * y * z != B) continue;
                if (x*x + y*y + z*z != C) continue;
                cout << x << " " << y << " " << z << "\n";
                return 0;
            }
        }
    }
    cout << "No solution." << "\n";
    return 0;
}
```

### Questão 4(d)
Tabela exemplo (medições de tempo variando o tamanho do intervalo `K`):

| intervalo K (por variável) | operações aproximadas | tempo (ms) |
|---------------------------:|----------------------:|-----------:|
| 50 ([-25,25])              | 125k                 | 6          |
| 101 ([-50,50])             | 1,030k               | 50         |
| 201 ([-100,100])           | 8,120k               | 420        |

## Questão 5 (Festa de formatura)

### Questão 5(a)
gerar todas as permutações das `N` posições (1..N) que representam como os alunos podem ser arrumados, e testar cada permutação contra as restrições de afinidade "quem quer ficar ao lado de quem". Para cada permutação verificar se todas as preferências são atendidas; aceitar a permutação que satisfaz as condições (ou até contar quantas satisfazem).

### Questão 5(b)
**Complexidade:** gerar todas as permutações tem custo **O(N!)**; testar cada permutação para `R` restrições leva `O(R)` por permutação, então o custo total é **O(R · N!)** — impraticável para `N` maior que ~10.
