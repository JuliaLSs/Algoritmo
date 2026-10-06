# 05 — Modelos curtos de resposta para prova

## “Por que é O(1)?”
> Não há laço dependente de `n` nem deslocamento de elementos; a operação altera/acessa diretamente uma posição ou ponteiro.

## “Por que é O(n)?”
> No pior caso, precisa percorrer uma quantidade de elementos proporcional a `n`.

## “Por que é O(n²)?”
> Para cada uma das `n` iterações, ocorre outro trabalho que pode percorrer até `n` elementos, resultando em crescimento quadrático.

## “Por que busca binária é rápida?”
> Porque elimina aproximadamente metade do espaço restante a cada comparação. Para isso, os dados precisam estar ordenados.

## “Por que não existe estrutura melhor?”
> Cada estrutura otimiza operações diferentes. Vetor acessa posição em O(1), mas inserir no início é O(n); lista encadeada faz o contrário, com inserção no início O(1) e acesso por posição O(n).

## “Pilha vs fila”
> Pilha usa LIFO: o último inserido sai primeiro. Fila usa FIFO: o primeiro inserido sai primeiro.

## “Por que push/pop de pilha é O(1)?”
> Porque opera somente no topo, sem percorrer nem deslocar os demais elementos.

## “Por que fila circular é O(1)?”
> Porque remover apenas avança o índice `inicio`; os elementos não são deslocados.

## “Por que o campo tamanho?”
> Porque em uma fila circular `inicio == fim` pode representar tanto fila vazia quanto cheia.

## “Por que heap é O(log n)?”
> Inserir ou remover percorre no máximo a altura da árvore completa, que é proporcional a `log₂(n)`.

## “Por que hash é O(1) médio?”
> A função hash calcula diretamente o balde. Com boa distribuição e fator de carga controlado, a lista de colisões permanece pequena.

## “Quando hash vira O(n)?”
> Quando muitas chaves colidem no mesmo balde, exigindo percorrer uma lista proporcional ao número de elementos.

## “Por que ABB pode virar O(n)?”
> Se ficar degenerada, por exemplo inserindo valores ordenados, sua altura pode chegar a `n`, fazendo a busca percorrer uma cadeia.

## “Por que árvore balanceada?”
> Ela mantém altura O(log n), garantindo busca, inserção e remoção eficientes mesmo com muitos elementos.

## “Como justificar por tempo medido?”
> Quando `N` [dobra / ×10], o tempo fica aproximadamente [×...]. Esse padrão é o esperado para `O(...)`.

## “Cronômetro e contador deram diferente”
> O contador mede apenas as operações instrumentadas; o cronômetro também inclui custos reais como alocação, acesso à memória e outras instruções dentro do trecho medido.

## “Qual estrutura escolher?”
> Escolho a estrutura cuja operação dominante do problema tem menor custo, e não a que parece mais rápida de forma geral.
