#include <iostream>
#include <string>
using namespace std;

const int CAP = 100;
int pilha[CAP];
int topo = 0; // quantidade; próximo espaço livre

bool empilhar(int valor) {
    if (topo == CAP) return false;
    pilha[topo++] = valor;
    return true;
}

bool vazia() {
    return topo == 0;
}

int desempilhar() {
    if (vazia()) return -1;
    topo--;
    return pilha[topo];
}

int espiar() {
    if (vazia()) return -1;
    return pilha[topo - 1];
}

int tamanho() {
    return topo;
}

bool parentesesBalanceados(const string& s) {
    int t = 0;
    char p[1000];

    for (char c : s) {
        if (c == '(') {
            p[t++] = c;
        } else if (c == ')') {
            if (t == 0) return false; // fechou sem abrir
            t--;
        }
    }
    return t == 0; // se >0, abriu e não fechou
}
