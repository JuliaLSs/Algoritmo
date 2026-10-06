# 03 — Rastreamento e cálculos

## Pilha

Sempre desenhe verticalmente.

```text
push(10)
push(20)
push(30)
pop()      -> 30
push(40)
pop()      -> 40
pop()      -> 20
push(50)

FINAL:
topo -> 50
        10
```

Dica: nunca “adivinhe”. Faça uma linha por operação.

---

## Fila circular

Campos:
```text
inicio = índice do próximo que sai
fim    = índice da próxima posição onde entra
tam    = quantidade atual
```

### Enfileirar
```cpp
dados[fim] = valor;
fim = (fim + 1) % CAP;
tam++;
```

### Desenfileirar
```cpp
valor = dados[inicio];
inicio = (inicio + 1) % CAP;
tam--;
```

### Exemplo
Capacidade 4:
```text
índice:    0  1  2  3
conteúdo:  E  _  C  D
inicio=2
fim=1
tam=3
```

Ordem lógica:
```text
C, D, E
```

Próximo `F` entra no índice `1`, pois:
```text
fim = 1
novo fim = (1 + 1) % 4 = 2
```

Se atender:
- sai `C` do índice 2;
- `inicio = (2 + 1) % 4 = 3`.

---

## Hash

Sempre faça:
```text
hash % capacidade
```

Exemplo, capacidade 10:
```text
77341 % 10 = 1
21850 % 10 = 0
44921 % 10 = 1
90360 % 10 = 0
```

Portanto:
```text
balde 0: marina -> sofia
balde 1: pedro  -> julio
```
Há duas colisões.

---

## ABB

### Inserção
Compare desde a raiz:
- menor → esquerda;
- maior → direita;
- repete até achar `nullptr`.

Inserindo:
```text
45,25,70,15,30,60
```

Resultado:
```text
       45
      /  \
    25    70
   / \    /
 15  30  60
```

### Busca por 30
Comparações:
```text
30 < 45  -> vai esquerda   (1)
30 > 25  -> vai direita    (2)
30 == 30 -> achou          (3)
```
Resposta: **3 comparações**.

### Em ordem
```text
15, 25, 30, 45, 60, 70
```

---

## Heap

Índices:
```text
filho esquerdo: 2*i + 1
filho direito:  2*i + 2
pai:            (i - 1) / 2
```

Ao inserir:
1. coloca no fim;
2. compara com pai;
3. troca enquanto violar propriedade.

Ao remover raiz:
1. salva raiz;
2. move último para raiz;
3. diminui tamanho;
4. desce trocando com melhor filho.

---

## Razões experimentais

### Se N ×10
```text
razao = valor_10N / valor_N
```

Exemplo:
```text
49995000 / 499500 ≈ 100
```
→ `O(n²)`.

```text
10000 / 1000 = 10
```
→ `O(n)`.

```text
14 / 10 = 1,4
```
→ compatível com `O(log n)`.

---

## Estimar antes de executar

### Inserções no início
```text
0 + 1 + 2 + ... + (n-1)
= n(n-1)/2
```

### Busca binária
Use potências de 2:
```text
2^10 ≈ 1.000
2^16 ≈ 65.000
2^20 ≈ 1.000.000
```

Logo:
- 1.000 elementos → ~10 comparações;
- 50.000 → ~16;
- 1.000.000 → ~20.
