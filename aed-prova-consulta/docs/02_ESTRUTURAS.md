# 02 — Estruturas de dados

## Tabela-mãe

| Estrutura | Operação forte | Operação fraca / cuidado |
|---|---|---|
| Vetor | acesso por índice `O(1)` | inserir/remover no início/meio `O(n)` |
| Lista encadeada | inserir no início `O(1)` | acessar posição `O(n)` |
| Pilha | push/pop/top `O(1)` | não escolhe elemento arbitrário |
| Fila circular | enqueue/dequeue `O(1)` | precisa controlar `inicio`, `fim`, `tamanho` |
| Deque | inserir/remover nas 2 pontas `O(1)` | não é busca geral |
| Heap | consultar prioridade `O(1)`, inserir/remover `O(log n)` | buscar qualquer valor `O(n)` |
| Hash | busca média `O(1)` | pior caso `O(n)`, não mantém ordem |
| ABB balanceada | busca/inserção/remoção `O(log n)` | ABB degenerada pode virar `O(n)` |

---

## Vetor

Memória contígua.

```cpp
v[i]
```
é `O(1)` porque o endereço é calculado diretamente.

### Inserir no início
Precisa deslocar todos para a direita → `O(n)`.

### Remover posição
```cpp
for (int i = pos; i < tam - 1; i++)
    v[i] = v[i + 1];
```
Pior caso `O(n)`.

---

## Lista encadeada

```cpp
struct No {
    int valor;
    No* prox;
};
```

Cada nó guarda valor + ponteiro.

### Inserir no início
```cpp
novo->prox = cabeca;
cabeca = novo;
```
`O(1)`.

### Acessar posição i
Precisa caminhar nó a nó → `O(n)`.

### Inserir no fim
- sem `cauda`: `O(n)`;
- mantendo ponteiro `cauda`: `O(1)`.

### Pegadinha fatal
Isto está certo:
```cpp
novo->prox = cabeca;
cabeca = novo;
```

Se fizer:
```cpp
cabeca = novo;
novo->prox = cabeca;
```
o novo nó aponta para ele mesmo e você perde a referência da lista antiga.

---

## Pilha

**LIFO**: Last In, First Out.

```text
push 10
push 20
push 30

topo -> 30
        20
        10
```

`pop()` devolve `30`.

Aplicações:
- Ctrl+Z;
- voltar;
- parênteses balanceados;
- pilha de chamadas;
- inverter sequência.

Operações típicas `O(1)` porque **não há laço nem deslocamento**.

---

## Fila

**FIFO**: First In, First Out.

Entra no fim, sai no início.

Aplicações:
- pedidos por ordem de chegada;
- impressão;
- atendimento FIFO.

### Fila ruim em vetor com deslocamento
```cpp
for (int i = 1; i < tam; i++)
    fila[i - 1] = fila[i];
```
Desenfileirar = `O(n)`.

### Fila circular
Não desloca os elementos.

```cpp
fim = (fim + 1) % CAP;
inicio = (inicio + 1) % CAP;
```
Enfileirar e desenfileirar = `O(1)`.

`tamanho` é importante porque:
```text
inicio == fim
```
pode significar **vazia ou cheia**.

---

## Deque

Double-ended queue.

Insere e remove nas duas pontas, normalmente `O(1)`.

- usando a mesma ponta → pode agir como pilha;
- usando pontas opostas → pode agir como fila.

---

## Heap / fila de prioridade

Max-heap:
```text
pai >= filhos
```

Não é totalmente ordenado. Só garante a relação pai-filho.

Índices no vetor:
```text
esquerdo(i) = 2*i + 1
direito(i)  = 2*i + 2
pai(i)      = (i - 1) / 2
```

Custos:
- consultar maior prioridade: `O(1)`;
- inserir: `O(log n)` → bubble up;
- remover raiz: `O(log n)` → bubble down;
- buscar valor qualquer: `O(n)`.

---

## Tabela hash

Fórmula:
```text
balde = hash(chave) % capacidade
```

### Colisão
Duas chaves diferentes caem no mesmo balde.

Com encadeamento:
```text
balde 3 -> [chave A] -> [chave B]
```

Custos:
- buscar: `O(1)` médio, `O(n)` pior;
- inserir: `O(1)` amortizado;
- remover: `O(1)` médio.

Não preserva ordenação.

### Fator de carga
```text
fator = quantidade / capacidade
```
Se cresce demais, aumenta colisões. Ao redimensionar, precisa recalcular os baldes porque `% capacidade` mudou.

---

## Árvore binária de busca (ABB)

Regra:
```text
esquerda < nó < direita
```

Exemplo inserindo:
```text
45, 25, 70, 15, 30, 60

       45
      /  \
    25    70
   / \    /
 15  30  60
```

### Percursos
- em ordem: esquerda, nó, direita → sai ordenado;
- pré-ordem: nó, esquerda, direita;
- pós-ordem: esquerda, direita, nó;
- largura: usa fila.

### Busca
Balanceada: `O(log n)`.
Degenerada:
```text
1
 \
  2
   \
    3
```
vira `O(n)`.

---

## Como escolher

Pergunte: **qual é a operação dominante?**

Exemplos:
- acesso por posição repetido → vetor;
- desfazer última ação → pilha;
- processar chegada → fila;
- prioridade → heap;
- chave → valor sem ordem → hash;
- dados ordenados com operações eficientes → árvore balanceada;
- últimos N itens com memória fixa → buffer/fila circular;
- parênteses balanceados → **pilha**.
