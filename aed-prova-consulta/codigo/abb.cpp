#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esq;
    No* dir;
};

No* inserir(No* raiz, int valor) {
    if (raiz == nullptr)
        return new No{valor, nullptr, nullptr};

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

bool buscar(No* raiz, int alvo) {
    if (raiz == nullptr) return false;
    if (raiz->valor == alvo) return true;

    if (alvo < raiz->valor)
        return buscar(raiz->esq, alvo);
    else
        return buscar(raiz->dir, alvo);
}

void emOrdem(No* raiz) {
    if (raiz == nullptr) return;
    emOrdem(raiz->esq);
    cout << raiz->valor << " ";
    emOrdem(raiz->dir);
}

void preOrdem(No* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->valor << " ";
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void posOrdem(No* raiz) {
    if (raiz == nullptr) return;
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    cout << raiz->valor << " ";
}
