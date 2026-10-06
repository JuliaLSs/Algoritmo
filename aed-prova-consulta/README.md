
## Ordem de consulta
1. [`docs/01_BIG_O.md`](docs/01_BIG_O.md) — descobrir e prever complexidade.
2. [`docs/02_ESTRUTURAS.md`](docs/02_ESTRUTURAS.md) — vetor, lista, pilha, fila, deque, heap, hash e ABB.
3. [`docs/03_RASTREAMENTO_CALCULOS.md`](docs/03_RASTREAMENTO_CALCULOS.md) — fila circular, heap, ABB, hash, razões.
4. [`docs/04_COMO_QUEBRAR_CODIGO.md`](docs/04_COMO_QUEBRAR_CODIGO.md) — bugs propositais e o que explicar.
5. [`docs/05_MODELOS_DE_RESPOSTA.md`](docs/05_MODELOS_DE_RESPOSTA.md) — frases curtas de justificativa.
6. [`docs/06_ERROS_DA_PROVA_ANTERIOR.md`](docs/06_ERROS_DA_PROVA_ANTERIOR.md) — pegadinhas que já apareceram.
7. [`codigo/`](codigo/) — bases prontas em C++.

## Regra mental principal

> **Não pergunte “qual estrutura é melhor?”. Pergunte “qual operação precisa ser barata?”**

### Se a questão falar...
- **posição `i`** → vetor.
- **último que entrou sai primeiro** → pilha.
- **primeiro que entrou sai primeiro** → fila.
- **duas pontas** → deque.
- **maior/menor prioridade** → heap.
- **buscar rapidamente por chave** → tabela hash.
- **dados ordenados + busca/inserção** → ABB balanceada.
- **inserir/remover nós sem deslocar elementos** → lista encadeada.

## Compilar
```bash
g++ -O0 -std=c++17 arquivo.cpp -o programa
./programa
```

`-O0` é especialmente importante em exercícios de medição para o compilador não otimizar o trecho que você quer medir.
