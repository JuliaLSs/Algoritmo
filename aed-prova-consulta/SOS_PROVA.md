# ⚡ SOS PROVA AED

## Big-O em 15 segundos
- sem laço dependente de N → `O(1)`
- divide pela metade → `O(log n)`
- 1 percurso → `O(n)`
- `n` em `log n` níveis → `O(n log n)`
- laço `n` dentro de laço `n` → `O(n²)`

## Se N dobra
`O(1)` ×1 | `O(log n)` cresce pouco | `O(n)` ×2 | `O(n log n)` pouco >×2 | `O(n²)` ×4

## Se N ×10
`O(1)` ×1 | `O(log n)` ~×1,1–1,4 | `O(n)` ×10 | `O(n log n)` ×10–12 | `O(n²)` ×100

## Fórmulas
- razão = `novo / antigo`
- busca binária ≈ `log2(n)`
- soma `0+...+(n-1)` = `n(n-1)/2`
- fila circular: `(indice + 1) % capacidade`
- heap: esq=`2i+1`, dir=`2i+2`, pai=`(i-1)/2`
- hash: `hash % capacidade`

## Estrutura pela frase
- posição → vetor
- última ação / desfazer / parênteses → pilha
- ordem de chegada → fila
- duas pontas → deque
- prioridade → heap
- chave → hash
- ordenado + busca → ABB balanceada
- últimos N com memória fixa → buffer circular

## Erros para NÃO repetir
- `v[n/2]` = `O(1)`, não `O(n)`
- parênteses = pilha
- busca binária exige ordenado
- ABB 45,25,70,15,30,60:
```
       45
      /  \
    25    70
   / \    /
 15  30  60
```
- busca 30 nessa ABB = 3 comparações
- hash % 10: 77341→1, 21850→0, 44921→1, 90360→0
