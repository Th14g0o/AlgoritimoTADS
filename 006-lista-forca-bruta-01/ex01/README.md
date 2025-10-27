## Q1
### (a) 
#### testar todas as orientações possiveis das fotos(as duas deitadas, uma deitada e a outra em pe, uma em pé e a outra deita, as duas em pé) e em cada orientação testar se cabem lado a lado ou uma encima da outra

### (b) 
####  O(1), constante

### (c)
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