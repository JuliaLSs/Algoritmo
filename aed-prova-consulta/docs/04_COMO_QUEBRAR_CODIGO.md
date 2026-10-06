# 04 — “Quebre de propósito”: o que pode acontecer

Questões desse tipo querem que você explique **causa → efeito observável → complexidade/erro aparente**.

## 1. Tirar `ops++` de dentro do laço

Original:
```cpp
for (int i = 0; i < N; i++) {
    ops++;
    ...
}
```

Quebrado:
```cpp
ops++;
for (int i = 0; i < N; i++) {
    ...
}
```

O programa ainda executa `N` repetições, mas o contador mostra sempre 1.

Conclusão falsa:
```text
O(1)
```

Frase:
> “O contador deixou de medir o trabalho real do laço; ele conta uma vez embora a operação continue percorrendo N elementos.”

---

## 2. Não zerar o contador

Se remover:
```cpp
ops = 0;
```

as execuções acumulam resultados anteriores.

Efeito:
- números cada vez maiores;
- razões deixam de comparar apenas um `N` com o próximo;
- Big-O inferido fica inválido.

---

## 3. Medir preparação junto

Ruim:
```cpp
auto t0 = now();
int* v = new int[N];
for (...) v[i] = i;
buscaLinear(...);
auto t1 = now();
```

Você está medindo:
- alocação;
- preenchimento;
- busca.

Então pode classificar a busca errado.

Certo:
```cpp
int* v = new int[N];
for (...) v[i] = i;

auto t0 = now();
int r = buscaLinear(...);
auto t1 = now();
```

---

## 4. Não usar o resultado

Em código otimizado, o compilador pode remover trabalho cujo resultado não é usado.

Por isso:
```cpp
int r = buscaLinear(...);
cout << r;
```

E nos materiais da disciplina, compile medição com:
```bash
g++ -O0 ...
```

---

## 5. Lista: trocar ordem dos ponteiros

Certo:
```cpp
novo->prox = cabeca;
cabeca = novo;
```

Errado:
```cpp
cabeca = novo;
novo->prox = cabeca;
```

Efeito:
- perde referência da lista antiga;
- o novo nó pode apontar para ele mesmo;
- travamento/laço infinito/fuga de memória são consequências possíveis dependendo do restante do código.

---

## 6. Fila circular sem `tamanho`

Se usa apenas:
```cpp
inicio == fim
```
não sabe diferenciar:
- completamente vazia;
- completamente cheia.

Pode sobrescrever dados sem aviso.

---

## 7. Fila com laço no lugar errado

Se o laço de desenfileirar ficar **dentro** do laço de enfileirar:

```cpp
for (int i = 0; i < N; i++) {
    enfileira();

    for (int j = 0; j < N; j++) {
        desenfileira();
    }
}
```

Você criou aproximadamente:
```text
N * N = N²
```
Logo, `O(n²)`.

---

## 8. Busca binária em vetor desordenado

Ela pode:
- descartar metade que contém o alvo;
- retornar `-1` mesmo com elemento existente.

A busca binária **exige vetor ordenado**.

---

## 9. Recursão sem caso base

```cpp
void f() {
    f();
}
```

Causa:
- chamadas nunca terminam;
- pilha de chamadas cresce;
- `stack overflow`.

---

## 10. Acessar ponteiro nulo

```cpp
No* p = nullptr;
cout << p->valor;
```

Pode causar falha de segmentação.

Cheque:
```cpp
if (p != nullptr) ...
```
