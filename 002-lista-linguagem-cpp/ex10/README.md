```bash
Entrada: n ∈ N+
Saída: Raiz quadrada no metodo babilonico
    candidato ← (n / 2) 
    r ← (candidato + n / candidato) / 2
    para candidato - r != 0.001 faça
        candidato ← r
        r ←  (candidato + n / candidato) / 2
    fim para
    retorne r
```