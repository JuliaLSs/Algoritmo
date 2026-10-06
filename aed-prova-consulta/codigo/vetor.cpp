#include <iostream>
using namespace std;

const int CAP = 100;
int v[CAP];
int tam = 0;

bool inserirFim(int valor) {
    if (tam == CAP) return false;
    v[tam++] = valor;
    return true;
}

bool inserirInicio(int valor) {
    if (tam == CAP) return false;
    for (int i = tam; i > 0; i--)
        v[i] = v[i - 1];
    v[0] = valor;
    tam++;
    return true;
}

bool remover(int pos) {
    if (pos < 0 || pos >= tam) return false;
    for (int i = pos; i < tam - 1; i++)
        v[i] = v[i + 1];
    tam--;
    return true;
}

int maior() {
    if (tam == 0) return -1;
    int m = v[0];
    for (int i = 1; i < tam; i++)
        if (v[i] > m) m = v[i];
    return m;
}

int buscarLinear(int alvo) {
    for (int i = 0; i < tam; i++)
        if (v[i] == alvo) return i;
    return -1;
}

void inverter() {
    for (int i = 0; i < tam / 2; i++) {
        int j = tam - 1 - i;
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}
