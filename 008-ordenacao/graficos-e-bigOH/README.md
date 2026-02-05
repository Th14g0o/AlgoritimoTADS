
## Algoritimo de ordenação com seleção

### BigOH = O(t²)

```cpp
void selecao(int a[], int t){
    int i, j; 
    int min, aux;
    for (i = 0; i < (t-1); i++){
        min = i;
        for (j = (i+1); j < t; j++) {
            if(a[j] < a[min])
            min = j;
        }
        if (a[i] != a[min]) {
            aux = a[i];
            a[i] = a[min];
            a[min] = aux;
        }
    }
}
```

## Algoritimo de ordenação com inserção

### BigOH = O(t²)

```cpp
void insercao(int a[], int t){
    int i,x;
    for (i=0 ; i<t ; ++i){
        int key = a[i];
        x = i - 1;
        while (x >= 0 && a[x] > key) {
            a[x + 1] = a[x];
            x = x - 1;
        }
        a[x + 1] = key;
    }
}
```

## Algoritimo de ordenação com merge-sort

### BigOH = O((n log n))

```cpp
void merge(int a[], int i1, int j1, int i2, int j2) {
    int* temp = new int[((j1 - i1) + (j2 - i2) + 2)];
    int i, j, k;
    i = i1;
    j = i2;
    k = 0;
    while (i <= j1 && j <= j2) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= j1)
        temp[k++] = a[i++];
    while (j <= j2)
        temp[k++] = a[j++];
    for (i = i1, j = 0;i <= j2;i++, j++)
        a[i] = temp[j];
    delete[] temp;
}

void merge_sort(int a[], int primeiro, int ultimo){
    int meio;
    if (primeiro < ultimo) {
        meio = (primeiro + ultimo) / 2;
        merge_sort(a, primeiro, meio);
        merge_sort(a, meio + 1, ultimo);
        merge(a, primeiro, meio, meio + 1, ultimo);
    }
};
```

## Melhor escolha

### O merge-sort é o mais eficiente em todos os casos testados

> Nos casos 3 e 5 a seleção é mais eficiente que o de inserção

> nos casos 2, 4 e 1 o insert é mais eficiente que o de seleção

> No caso 2 a inserção e o merge tiveram valores tão proximos que a barra do insert é desenhado embaixo do merge.