## Backtracking

A abordagem utilizada para a resolucao foi a de backtracking.

Inicialização: Aloco o array `resultado` para guardar todas as combinacoes geradas e o array `tamanhos` para armazenar o tamanho de cada uma (sempre k).

Caso base: quando `escolhidos == k`

A funcao `backtrack` recebe `inicio` (proximo numero candidato), `escolhidos` (quantos ja foram colocados em `combinacao`), `n`, `k` e o ponteiro `qtd` (quantas combinacoes ja foram salvas).


O Loop `for` percorre os numeros de `inicio` ate `n`:
   Colocamos `i` na posicao `escolhidos` do vetor `combinacao`.
   Chamamos `backtrack`, garantindo que o proximo numero escolhido seja sempre maior que o atual, evitando combinacoes repetidas.

retornamos `resultado` junto com `returnSize` e `returnColumnSizes`

Complexidade de Tempo: O(C(n, k) * k)
Complexidade de Espaço: O(C(n, k) * k)