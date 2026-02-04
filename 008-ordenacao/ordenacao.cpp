#include "ordenacao.hpp"

/* TODO: Implementar função */
bool ordenado(int a[], int t) {
    int i, ordenado = true;
    for (i = 1; i < t; ++i)
        if (a[i - 1] > a[i]) {
            ordenado = false;
            break;
        }
    return ordenado;
}

/* TODO: Implementar função */
void selecao(int a[], unsigned int t){
    unsigned int i, j; 
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

/* TODO: Implementar função */
void insercao(int a[], unsigned int t){
    unsigned int i,x;
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


/* TODO: Implementar função */
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

void merge_sort(int a[], unsigned int primeiro, unsigned int ultimo){
    int meio;
    if (primeiro < ultimo) {
        meio = (primeiro + ultimo) / 2;
        merge_sort(a, primeiro, meio);
        merge_sort(a, meio + 1, ultimo);
        merge(a, primeiro, meio, meio + 1, ultimo);
    }
};
