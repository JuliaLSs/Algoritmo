#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

No* cabeca = nullptr;
No* cauda = nullptr;
int qtd = 0;

void inserirInicio(int valor) {
    No* novo = new No{valor, cabeca};
    cabeca = novo;
    if (cauda == nullptr) cauda = novo;
    qtd++;
}

void inserirFim(int valor) {
    No* novo = new No{valor, nullptr};

    if (cabeca == nullptr) {
        cabeca = cauda = novo;
    } else {
        cauda->prox = novo;
        cauda = novo;
    }
    qtd++;
}

bool buscar(int valor) {
    No* p = cabeca;
    while (p != nullptr) {
        if (p->valor == valor) return true;
        p = p->prox;
    }
    return false;
}

int posicaoDe(int valor) {
    int pos = 0;
    for (No* p = cabeca; p != nullptr; p = p->prox, pos++)
        if (p->valor == valor) return pos;
    return -1;
}

int contarPercorrendo() {
    int total = 0;
    for (No* p = cabeca; p != nullptr; p = p->prox)
        total++;
    return total;
}

void inverter() {
    No* anterior = nullptr;
    No* atual = cabeca;
    cauda = cabeca;

    while (atual != nullptr) {
        No* proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    cabeca = anterior;
}

void liberar() {
    while (cabeca != nullptr) {
        No* temp = cabeca;
        cabeca = cabeca->prox;
        delete temp;
    }
    cauda = nullptr;
    qtd = 0;
}
