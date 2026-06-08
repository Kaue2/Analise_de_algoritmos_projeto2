## Técnica: Algoritmo Guloso
A solução implementada combina contagem de frequência com dedução matemática de pior caso, que se aproxima dos princípios de algoritmos gulosos.

## Explicação da Solução

Passo a passo:

- Vetor para conter frequencias de cada letra do alfabeto é criado e inicializado com zero

- Frequência de cada letra é verificada

- Maior frequência existente é obtida e atribuída a variável 'frequenciaMaxima'

- Vetor de frequências é percorrido no intuito de contar quantas vezes a frequência máxima é repetida

- O valor de intervalos necessários é calculado levando em consideração o pior cenários possível, utilizando a fórmula: (frequencia maxima - 1) * (n + 1) + (quantidade de máximos)


## Análise de Complexidade

#### Complexidade de tempo: O(N)

Neste cenário, N é o total de tarefas. O trecho mais custoso do algoritmo é o laço for inicial, que executa N vezes.

#### Complexidade de espaço: O(1)

A lógica aloca apenas variáves do tipo inteiro básico e um array local com exatas 26 posições. 
Como a memória consumida não escala junto com o crescimento da lista, é complexidade de memória é considerada como constante O(1).