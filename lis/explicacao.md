## Programação Dinâmica

A abordagem utilizada para a resolucao do problema foi a de um algoritmo de programacao dinamica, assim como o ensinado em sala

Inicialização:  Cada posição `dp[i]` começa com valor `1`.

O Loop Externo `i` Percorre cada elemento do array, considerando como o possível último elemento de uma subsequência.
O Loop Interno `j` Para cada `i`, percorre todos os elementos que atendem `(j < i)`
   Se `nums[j] < nums[i]`, então `nums[i]` estende a subsequencia que termina em `j`.
   Atualizamos `dp[i] = max(dp[i], dp[j] + 1)`, mantendo sempre o maior valor encontrado.

A cada iteração, comparamos `dp[i]` com `maior_global` para guardar o tamanho da maior LIS encontrada até então. Ao final, retornamos esse valor.


Complexidade de Tempo: O(N^2)
Complexidade de Espaço: O(N)
