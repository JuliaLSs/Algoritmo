#include <iostream>
using namespace std;

const int CAP = 5;
int fila[CAP];
int inicio = 0;
int fim = 0;
int qtd = 0;

bool enfileirar(int valor) {
    if (qtd == CAP) return false;

    fila[fim] = valor;
    fim = (fim + 1) % CAP;
    qtd++;
    return true;
}

int desenfileirar() {
    if (qtd == 0) return -1;

    int valor = fila[inicio];
    inicio = (inicio + 1) % CAP;
    qtd--;
    return valor;
}

int primeiro() {
    if (qtd == 0) return -1;
    return fila[inicio];
}

bool vazia() { return qtd == 0; }
bool cheia() { return qtd == CAP; }
