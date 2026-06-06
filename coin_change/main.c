#include <stdio.h>
#include <stdlib.h>

int verificarTroco(int* moedas, int qtdMoedas, int troco) {

    int* moedasNecessarias = (int*)malloc(sizeof(int) * (troco + 1));

    if (moedasNecessarias == NULL)
        return -1;

    for (int i = 0; i < (troco + 1); i++)
        moedasNecessarias[i] = (troco + 1);

    moedasNecessarias[0] = 0;

    int moedaAtual;

    for (int i = 1; i < (troco + 1); i++) {

        for (int j = 0; j < qtdMoedas; j++) {

            moedaAtual = moedas[j];

            if (i - moedaAtual >= 0) {
                if (moedasNecessarias[i - moedaAtual] + 1 < moedasNecessarias[i]) {
                    moedasNecessarias[i] = moedasNecessarias[i - moedaAtual] + 1;
                }
            }
        }
    }

    int resultado = moedasNecessarias[troco];

    free(moedasNecessarias);

    if (resultado != troco + 1)
        return resultado;

    return -1;
}

int coinChange(int* coins, int coinsSize, int amount) {
    return verificarTroco(coins, coinsSize, amount);
}