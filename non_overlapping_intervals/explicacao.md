## Técnica Algorítmica: Algoritmo Guloso (Greedy)

A solução utiliza uma abordagem **Gulosa** (Greedy Algorithm). A ideia central de um algoritmo guloso é fazer a escolha que parece ser a melhor no momento (ótimo local) com a expectativa de que isso leve à melhor solução geral (ótimo global).

Neste problema específico, a estratégia ideal é **ordenar os intervalos pelo tempo de término**. A lógica é simples: ao priorizarmos manter na lista os eventos que terminam mais cedo, deixamos o máximo de "tempo livre" possível na linha do tempo para acomodar os próximos intervalos. Isso naturalmente minimiza a quantidade de intervalos que precisarão ser removidos.

## Explicação da Solução

O algoritmo segue uma sequência clara de passos:

1. **Tratamento do Caso Base:** Primeiro, verificamos se a matriz/lista de intervalos está vazia. Se estiver, não há nada a remover, e retornamos `0`.
2. **Ordenação:** Ordenamos todos os intervalos de forma crescente com base exclusivamente no **tempo de término** (índice 1 de cada sub-array).
3. **Definição do Ponto de Referência:** Pegamos o tempo de término do primeiro intervalo da lista já ordenada. Este será o nosso limite seguro (`last_end`).
4. **Iteração e Verificação:** Percorremos os intervalos restantes (a partir do segundo):
   * **Se houver sobreposição:** Se o tempo de início do intervalo atual for menor que o nosso limite seguro (`current_start < last_end`), significa que há um conflito. Como o intervalo atual termina depois (ou no mesmo tempo, devido à ordenação), nós o "removemos" incrementando o contador de remoções.
   * **Se não houver sobreposição:** Se o intervalo atual começa depois ou exatamente no momento em que o limite seguro termina, ele é válido. Nós o mantemos e atualizamos o nosso limite seguro para o tempo de término deste novo intervalo (`last_end = current_end`).

## Análise de Complexidade

* **Complexidade de Tempo:** $O(N \log N)$
  A etapa que exige mais processamento é a ordenação da matriz de intervalos (seja usando `sort` no Python ou `qsort` em C), o que custa $O(N \log N)$, onde $N$ é o número total de intervalos. A passagem subsequente para verificar as sobreposições através do loop `for` visita cada elemento apenas uma vez, o que custa $O(N)$. Como a ordenação é o termo dominante, o tempo total da operação é $O(N \log N)$.

* **Complexidade de Espaço:** $O(1)$ a $O(\log N)$
  A lógica principal do algoritmo utiliza espaço extra constante $O(1)$, pois criamos apenas variáveis inteiras (`removals`, `last_end`, `current_start`, `current_end`) que não escalam com o tamanho da entrada. Contudo, é importante notar que a função de ordenação nativa das linguagens sob o capô (como o Timsort no Python ou o Quicksort em C) pode consumir entre $O(\log N)$ e $O(N)$ de espaço na pilha de chamadas (*call stack*), dependendo da implementação e do estado dos dados.
