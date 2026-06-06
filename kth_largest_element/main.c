#include <stdio.h>
#include <stdlib.h>

void realizarTroca(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSelect(int* vetor, int base, int maximo, int alvo) {

    if (base >= maximo)
        return;

    int meio = base + (maximo - base) / 2;
    int pivot = vetor[meio];

    int esquerda = base;
    int direita = maximo;
    int i = base;

    while (i <= direita) {

        if (vetor[i] > pivot) {
            realizarTroca(&vetor[esquerda], &vetor[i]);
            esquerda++;
            i++;
        }
        else {

            if (vetor[i] < pivot) {
                realizarTroca(&vetor[i], &vetor[direita]);
                direita--;
            }
            else {
                i++;
            }
        }
    }

    if (alvo >= esquerda && alvo <= direita) {
        return;
    }
    else {
        if (alvo < esquerda) {
            quickSelect(vetor, base, esquerda - 1, alvo);
        }
        else {
            quickSelect(vetor, direita + 1, maximo, alvo);
        }
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    
    int itemProcurado = k - 1;

    quickSelect(nums, 0, numsSize - 1, itemProcurado);

    return nums[itemProcurado];
}