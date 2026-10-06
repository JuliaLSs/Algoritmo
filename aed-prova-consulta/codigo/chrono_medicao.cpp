#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Exemplo de função a medir
int buscaLinear(int v[], int n, int alvo) {
    for (int i = 0; i < n; i++)
        if (v[i] == alvo) return i;
    return -1;
}

int main() {
    int N = 100000;
    int* v = new int[N];

    // preparação FORA do cronômetro
    for (int i = 0; i < N; i++) v[i] = i;

    long menor = 999999999;

    for (int rep = 0; rep < 3; rep++) {
        auto t0 = high_resolution_clock::now();

        int r = buscaLinear(v, N, N - 1);

        auto t1 = high_resolution_clock::now();

        long us = duration_cast<microseconds>(t1 - t0).count();
        if (us < menor) menor = us;

        // usa o resultado
        if (r == -999) cout << r;
    }

    cout << "menor tempo = " << menor << " us\n";

    delete[] v;
    return 0;
}
