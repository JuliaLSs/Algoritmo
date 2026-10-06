#include <iostream>
using namespace std;

int buscaLinear(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++)
        if (v[i] == alvo) return i;
    return -1;
}

// EXIGE vetor ordenado
int buscaBinaria(int v[], int n, int alvo) {
    int e = 0, d = n - 1;

    while (e <= d) {
        int m = e + (d - e) / 2;

        if (v[m] == alvo) return m;
        if (v[m] < alvo) e = m + 1;
        else d = m - 1;
    }
    return -1;
}

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = true;
            }
        }

        if (!trocou) break;
    }
}

void merge(int v[], int aux[], int e, int m, int d) {
    int i = e, j = m + 1, k = e;

    while (i <= m && j <= d)
        aux[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];

    while (i <= m) aux[k++] = v[i++];
    while (j <= d) aux[k++] = v[j++];

    for (int x = e; x <= d; x++)
        v[x] = aux[x];
}

void mergeSort(int v[], int aux[], int e, int d) {
    if (e >= d) return;

    int m = (e + d) / 2;
    mergeSort(v, aux, e, m);
    mergeSort(v, aux, m + 1, d);
    merge(v, aux, e, m, d);
}
