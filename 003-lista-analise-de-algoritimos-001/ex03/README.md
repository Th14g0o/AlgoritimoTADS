```
Entrada: n pertence aos naturais
Saída: verdadeiro s en for primo. falso senão.

divs <- 0               -- 1
para i <- 1 até n faça  -- n
  se n mod i = 0 então  -- n
    divs <- divs + 1    -- 2n
  fim se  
fim para
se divs = 2 então       -- 2
  retorne verdadeiro
senão
  retorne falso
fim se
```

#### 4n + 3