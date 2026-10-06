# 06 — Pegadinhas detectadas na prova anterior

Este arquivo é especialmente importante: há respostas antigas no material que parecem preenchidas, mas algumas estão incorretas.

## Questão de complexidade: acesso `v[n/2]`
```cpp
int x = v[n / 2];
```
✅ Correto: **O(1)**.

Motivo: calcular `n/2` e acessar uma posição do vetor são operações constantes. O índice depender de `n` **não** transforma acesso direto em `O(n)`.

---

## Medição: função que cresce muito devagar
Se ao dobrar `N` os tempos ficam algo como:
```text
13, 14, 15, 18, 29
```
isso não é evidência de `O(n log n)`. O crescimento é muito menor que linear e pode ser compatível com **O(log n)** ou sofrer bastante ruído de medição.

Regra: `O(n log n)` ao dobrar `N` fica pouco mais que ×2, não “+1”.

---

## Hash capacidade 10

Hashes:
```text
pedro  = 77341 -> balde 1
marina = 21850 -> balde 0
julio  = 44921 -> balde 1
sofia  = 90360 -> balde 0
```

✅ Colisões:
- `pedro` com `julio`;
- `marina` com `sofia`.

---

## ABB inserindo `45,25,70,15,30,60`

✅ Correto:
```text
       45
      /  \
    25    70
   / \    /
 15  30  60
```

Percurso em ordem:
```text
15,25,30,45,60,70
```

Buscar 30:
```text
45 -> 25 -> 30
```
✅ **3 comparações**.

---

## Parênteses balanceados

✅ Estrutura correta: **pilha**.

Algoritmo:
- `(` → push;
- `)` → pop;
- se tentar pop vazia → fechou sem abrir;
- se acabar e pilha não estiver vazia → abriu e não fechou.

---

## Ctrl+Z e lista encadeada

Uma lista encadeada pode, sim, ser usada para implementar uma pilha se as operações forem feitas na cabeça.

O ponto da questão é diferenciar **TAD/comportamento** de **implementação**:
- Ctrl+Z precisa do comportamento LIFO;
- uma pilha pode ser implementada com vetor ou lista encadeada.

Não diga simplesmente que “lista não funcionaria”. Diga que uma **lista genérica sem política LIFO** não garante desfazer a última ação.

---

## “Últimos 50 comandos, memória fixa”

Se a intenção for manter **sempre os 50 mais recentes** e descartar automaticamente o mais antigo quando chega o 51º:
✅ **buffer/fila circular**.

Se a intenção for apenas desfazer comandos:
✅ pilha.

Leia o verbo e o comportamento pedido.
