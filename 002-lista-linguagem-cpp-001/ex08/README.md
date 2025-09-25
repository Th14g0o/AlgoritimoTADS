```bash
Entrada: a ∈ N+
Entrada: b ∈ N+
Saída: Maximo divisor comum de a e b
    para b != 0 faça
        r ← a % b
        a ← b
        b ← r
    fim para
    retorne a`
```