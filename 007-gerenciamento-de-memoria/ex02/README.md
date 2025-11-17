```cpp
int index_of(int value){
    for (int index = 0; index < size(); index++)      // 1 + n + n
        if (this->data[index] == value) return index; // n
    return -1;                                        // 1
}
```
> 3n + 2
### Complexidade: O(n)
> no pior dos casos percorrera todos os n elementos do vetor