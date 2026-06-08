## Técnica: Programação Dinâmica

## Explicação da Solução

- Alocação de vetor com tamanho troco + 1, representando em cada posição uma quantia de troco específica, o valor armazenado será a quantidade mínima de moedas necessárias para formar aquela quantia.

- Atribuição de falso infinito a cada uma das posições do vetor armazenado.

- Atribuição de 0 a posição inicial do vetor, representando que são necessárias 0 moedas para dar um troco de valor 0.

- Nos laços de repetição, laço externo percorre todas as quantias de 1 até o valor total do troco. Laço interno tenta aplicar cada uma das moedas disponíveis para aquela quantia específica obtida no laço externo.

- Dentro dos laços a quantidade de moedas necessária para aquele valor específico do troco é verificada e atualizada.

- Por fim, caso o resultado obtido seja diferente do valor de (troco + 1), valor utilizado no começo do algoritmo para delimitação de limite superior, é então retornado o resultado. Caso contrário, é retornado o valor -1.

## Análise de Complexidade

#### Complexidade de Tempo: O(S x N)

Neste cenário, o S é o valor do troco e N é o número de tipos de moedas diferentes. Para cada valor de 1 até S, é iterado N moedas no laço interno. E, dentro dos laços, são realizadas operaçoes matemáticas e de comparação que tem custo O(1).

#### Complexidade de Espaço: O(S)

É alocado um vetor de tamanho troco + 1. Com isso, a quantidade de memória extra é proporcional a S, onde S é o valor do troco.