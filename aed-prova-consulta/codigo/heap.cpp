#include <iostream>
using namespace std;

const int CAP = 100;
int heapv[CAP];
int tam = 0;

int pai(int i) { return (i - 1) / 2; }
int esq(int i) { return 2 * i + 1; }
int dir(int i) { return 2 * i + 2; }

void trocar(int& a, int& b) {
    int t = a; a = b; b = t;
}

// MAX-HEAP
bool inserir(int valor) {
    if (tam == CAP) return false;

    int i = tam;
    heapv[tam++] = valor;

    // bubble up
    while (i > 0 && heapv[pai(i)] < heapv[i]) {
        trocar(heapv[pai(i)], heapv[i]);
        i = pai(i);
    }
    return true;
}

int topoPrioridade() {
    if (tam == 0) return -1;
    return heapv[0];
}

int removerMaior() {
    if (tam == 0) return -1;

    int resposta = heapv[0];
    heapv[0] = heapv[tam - 1];
    tam--;

    // bubble down
    int i = 0;
    while (true) {
        int maior = i;
        int l = esq(i), r = dir(i);

        if (l < tam && heapv[l] > heapv[maior]) maior = l;
        if (r < tam && heapv[r] > heapv[maior]) maior = r;

        if (maior == i) break;

        trocar(heapv[i], heapv[maior]);
        i = maior;
    }

    return resposta;
}
