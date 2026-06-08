## Técnica: Divisão e Conquista

O algoritmo utilizado é o QuickSelect, implementado com o uso da partição de três vias, agrupando elementos repetidos no centro, tornando a execução mais rápida. Necessário pois o caso final do problema na plataforma LeetCode é constituído de um vetor com maior parte de seus números iguais.

## Explicação da Solução

- Pivô é escolhido, sendo item central do bloco atual.

- Laço que percorre itens com objetivo de construir ordem decrescente. Itens maiores que o pivô são movidos para posições iniciais do bloco, itens menores que o pivô são movidos para o final do bloco, e itens iguais ao pivô permanecem no meio, entre os ponteiros de esquerda e direita.

- A partir do bloco atual, é avaliada a posição em relação ao alvo: Se o alvo for encontrado, a recursão é interrompida. Se o alvo for menor que o ponteiro da esquerda, o alvo esta no bloco de números maiores, fazendo com que a recursão percorra apenas esta parte. E, caso o alvo for maior que a direita, o alvo em questão esta no bloco de números menores, fazendo com que a recursão desça apenas para este lado.

## Análise de Complexidade

#### Complexidade de tempo: O(N) em tempo médio

#### Complexidade de espaço: O(log N) - O(N)
