## Técnica Algorítmica: Divisão e Conquista

O Merge Sort é um exemplo clássico do paradigma algorítmico conhecido como **Divisão e Conquista** (*Divide and Conquer*). Esta técnica resolve um problema complexo quebrando-o em subproblemas menores e mais simples, resolvendo-os recursivamente e, em seguida, combinando suas soluções.

O processo funciona em três etapas fundamentais:
1. **Dividir:** O array original é dividido pela metade sucessivas vezes até que cada sub-array contenha apenas um elemento (um array com um único elemento já é considerado ordenado).
2. **Conquistar:** Os sub-arrays são ordenados recursivamente.
3. **Combinar:** Os sub-arrays ordenados são mesclados (*merged*) dois a dois para formar arrays maiores e ordenados, até que todo o array original seja reconstruído de forma ordenada.

---

## Explicação da Solução

A solução fornecida está estruturada em três funções para manter o código modular, limpo e otimizado quanto ao uso de memória:

1. `sortArray` (Ponto de Entrada)
* **Validação:** Verifica se o array possui 1 ou 0 elementos, que são os casos base já implicitamente ordenados.
* **Otimização de Memória:** Aloca dinamicamente um único array auxiliar (`temp`) do mesmo tamanho do array original. Passar esse ponteiro como parâmetro para as funções recursivas evita a sobrecarga de múltiplas alocações e liberações de memória (`malloc` / `free`) a cada chamada, melhorando significativamente a performance.
* **Finalização:** Executa o `merge_sort`, liberta a memória alocada para o `temp` e retorna o array ordenado.

2. `merge_sort` (Lógica Recursiva)
* **Condição de Parada:** Se o índice esquerdo (`left`) for maior ou igual ao direito (`right`), a recursão é interrompida.
* **Cálculo Seguro do Ponto Médio:** O cálculo é feito utilizando `mid = left + (right - left) / 2`. Esta abordagem previne problemas de *overflow* de inteiros que poderiam ocorrer com a fórmula tradicional `(left + right) / 2`.
* **Chamadas Recursivas:** Divide o problema ao meio, invocando a si mesma para a metade esquerda e, em seguida, para a metade direita.
* **Interpolação:** Invoca a função `merge` para unir e ordenar as metades processadas.

3. `merge` (Combinação/Mesclagem)
* **Técnica de Dois Ponteiros:** Utiliza variáveis de controle (`i` para a metade esquerda e `j` para a metade direita) para percorrer os sub-arrays em paralelo.
* **Ordenação Estável:** Compara os elementos. O menor elemento é copiado para o array temporário (`temp`), mantendo a estabilidade do algoritmo (elementos iguais mantêm a sua ordem relativa original).
* **Consumação de Restantes:** Se uma das metades for totalmente percorrida antes da outra, os laços subsequentes garantem que todos os elementos restantes da outra metade sejam copiados diretamente para o `temp`.
* **Cópia de Volta:** Por fim, transfere os elementos ordenados do array temporário `temp` de volta para o array original `nums`.

---

## Análise de Complexidade

* Complexidade de Tempo

| Caso | Complexidade | Descrição |
| :--- | :--- | :--- |
| **Pior Caso** | $O(N \log N)$ | Ocorre independentemente da disposição inicial dos dados. |
| **Melhor Caso** | $O(N \log N)$ | Mesmo que o array já esteja ordenado, as divisões e combinações acontecem. |
| **Caso Médio** | $O(N \log N)$ | O comportamento do algoritmo é consistente em qualquer cenário. |

* **Por que $O(N \log N)$?** O algoritmo divide o array consecutivamente ao meio, gerando uma árvore de recursão com altura proporcional a $\log_2 N$. Em cada nível dessa árvore, a função `merge` processa e combina todos os $N$ elementos. Como resultado, o custo total é a multiplicação do número de níveis pelo trabalho feito por nível, ou seja, $O(N \log N)$. Ao contrário do *Quick Sort*, o *Merge Sort* garante este desempenho de forma consistente, sem piorar para $O(N^2)$.

* Complexidade de Espaço

* **Espaço Auxiliar:** $O(N)$
* **Explicação:** A mesclagem não pode ser feita facilmente *in-place* de forma eficiente. Por isso, é necessário um array auxiliar (`temp`) de tamanho $N$ para armazenar temporariamente os elementos durante a combinação. A pilha de chamadas recursivas (*Call Stack*) adiciona uma complexidade de $O(\log N)$, mas como $O(N)$ é o termo dominante, a complexidade de espaço assintótica é $O(N)$.
