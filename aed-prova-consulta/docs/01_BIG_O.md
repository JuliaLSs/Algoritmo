# 01 — Big-O, previsão e razões

## 1. O que a notação mede

Big-O descreve **como o trabalho cresce quando `n` cresce**. Ela não é “quantos segundos demora”.

| Big-O | Nome | Se `n` dobra | Se `n` × 10 | Pista no código |
|---|---|---:|---:|---|
| `O(1)` | constante | ×1 | ×1 | acesso direto, nenhuma repetição dependente de `n` |
| `O(log n)` | logarítmica | + ~1 passo | ×1,1 a ×1,4 | divide problema pela metade |
| `O(n)` | linear | ×2 | ×10 | um laço até `n` |
| `O(n log n)` | linearítmica | pouco > ×2 | ×10 a ×12 | `n` trabalho em `log n` níveis |
| `O(n²)` | quadrática | ×4 | ×100 | dois trabalhos de tamanho `n`, normalmente laços aninhados |

## 2. Como classificar código

### `O(1)`
```cpp
int x = v[n / 2];
topo++;
```
O índice pode depender de `n`, mas acessar aquela posição do vetor é direto.

### `O(n)`
```cpp
for (int i = 0; i < n; i++)
    soma += v[i];
```

### Dois laços em sequência continuam `O(n)`
```cpp
for (int i = 0; i < n; i++) soma += v[i];
for (int i = 0; i < n; i++) maior = max(maior, v[i]);
```
Trabalho: `n + n = 2n`. Ignora constante → `O(n)`.

### Laço `n` com laço constante continua `O(n)`
```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < 10; j++)
        soma += v[i];
```
Trabalho: `10n` → `O(n)`.

### Dois laços dependentes de `n` → `O(n²)`
```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        soma++;
```

### Divide pela metade → `O(log n)`
```cpp
while (e <= d) {
    int m = (e + d) / 2;
    if (v[m] < alvo) e = m + 1;
    else d = m - 1;
}
```

## 3. A pegadinha dos laços não aninhados

```cpp
for (...) { ... }  // O(n)
for (...) { ... }  // O(n)
```
Soma: `O(n) + O(n) = O(n)`.

```cpp
for (...)           // O(n)
    for (...)       // O(n)
```
Multiplica: `O(n) * O(n) = O(n²)`.

## 4. Cálculo da razão

Fórmula:
```text
razão = tempo_novo / tempo_anterior
```

Exemplo:
```text
N=1.000  -> 20 us
N=10.000 -> 210 us

razão = 210 / 20 = 10,5
```
Como `N` foi multiplicado por 10 e o tempo ficou perto de ×10 → **O(n)**.

### Quando `N` DOBRA
- ~×1 → `O(1)`
- cresce pouquíssimo → `O(log n)`
- ~×2 → `O(n)`
- ~×2,1 a ×2,5 → `O(n log n)`
- ~×4 → `O(n²)`

### Quando `N` ×10
- ~×1 → `O(1)`
- ~×1,1 a ×1,4 → `O(log n)`
- ~×10 → `O(n)`
- ~×10 a ×12 → `O(n log n)`
- ~×100 → `O(n²)`

## 5. Previsão de quantidade de operações

### Busca linear
Pior caso:
```text
passos ≈ n
```
Para 50.000 elementos: ~50.000 comparações.

### Busca binária
```text
passos ≈ log2(n)
```
Para 50.000:
```text
2^15 = 32768
2^16 = 65536
```
Logo, cerca de **16 passos**.

### Bubble sort
Comparações aproximadas:
```text
n(n-1)/2
```
Para 1.000:
```text
1000*999/2 = 499.500
```

### Inserir sempre no início do vetor
Também desloca:
```text
0 + 1 + 2 + ... + (n-1)
= n(n-1)/2
= O(n²)
```

## 6. Custo total vs custo de UMA operação

Importantíssimo.

- `push` de pilha individual: `O(1)`.
- Fazer `n` pushes: `O(n)` **total**.
- `push_back` de lista com `cauda`: `O(1)` cada.
- Construir uma lista com `n` inserções: `O(n)` total.

## 7. Custo amortizado

Vetor dinâmico normalmente dobra capacidade.
A maioria dos `push_back` custa `O(1)`, mas às vezes precisa copiar `n` elementos.

Por isso:
```text
push_back = O(1) amortizado
```
Uma inserção específica durante realocação pode ser `O(n)`.

## 8. Frase pronta de justificativa

> “A complexidade é `O(...)` porque o número de operações cresce ______ em relação a `n`. O trecho responsável é ______.”

Exemplo:
> “É O(n²) porque, para cada elemento inserido no início, vários elementos anteriores são deslocados. A soma dos deslocamentos é 0+1+...+(n−1).”
