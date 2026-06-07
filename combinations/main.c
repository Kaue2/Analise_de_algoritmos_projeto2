#include <stdlib.h>

int* tamanhos;
int** resultado; 
int combinacao[25];

void backtrack(int inicio, int escolhidos, int n, int k, int *qtd) {

    if (escolhidos == k) {
        resultado[*qtd] = malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            resultado[*qtd][i] = combinacao[i];
        }

        tamanhos[*qtd] = k;
        (*qtd)++;
        return;
    }

    for (int i = inicio; i <= n; i++) {
        combinacao[escolhidos] = i;
        backtrack(i + 1, escolhidos + 1, n, k, qtd);
    }

}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int qtd = 0;

    resultado = malloc(200000 * sizeof(int*));
    tamanhos = malloc(200000 * sizeof(int));

    backtrack(1, 0, n, k, &qtd);

    *returnSize = qtd;
    *returnColumnSizes = tamanhos;
    return resultado;
}
