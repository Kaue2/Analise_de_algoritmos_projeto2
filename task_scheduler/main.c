int retornarMaximo(int a, int b) {
    return a > b ? a : b;
}

int leastInterval(char* tasks, int tasksSize, int n) {

    int contagemAlfabeto[26] = {0};

    for (int i = 0; i < tasksSize; i++) {
        contagemAlfabeto[tasks[i] - 'A']++;
    }

    int frequenciaMaxima = 0;

    for (int i = 0; i < 26; i++) {
        if (contagemAlfabeto[i] > frequenciaMaxima) {
            frequenciaMaxima = contagemAlfabeto[i];
        }
    }

    int repeticaoDeMaximos = 0;

    for (int i = 0; i < 26; i++) {
        if (contagemAlfabeto[i] == frequenciaMaxima) {
            repeticaoDeMaximos++;
        }
    }

    int intervalosNecessarios = (frequenciaMaxima - 1) * (n + 1) + repeticaoDeMaximos;

    return retornarMaximo(tasksSize, intervalosNecessarios);
}