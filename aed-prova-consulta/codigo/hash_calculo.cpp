#include <iostream>
#include <string>
using namespace std;

// Para prova conceitual:
// balde = hash % capacidade

int balde(long long hash, int capacidade) {
    return hash % capacidade;
}

int main() {
    int capacidade = 10;

    cout << balde(77341, capacidade) << "\n"; // 1
    cout << balde(21850, capacidade) << "\n"; // 0
    cout << balde(44921, capacidade) << "\n"; // 1
    cout << balde(90360, capacidade) << "\n"; // 0
}
