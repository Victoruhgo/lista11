#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo = fopen("matriz.txt", "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int n;
    fscanf(arquivo, "%d", &n);

    int matriz1[n][n];
    int matriz2[n][n];
    int soma[n][n];

    // Lê a primeira matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(arquivo, "%d", &matriz1[i][j]);
        }
    }

    // Lê a segunda matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(arquivo, "%d", &matriz2[i][j]);
        }
    }

    fclose(arquivo);

    // Soma as matrizes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Imprime o resultado
    printf("Matriz Soma (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", soma[i][j]);
        }
        printf("\n");
    }

    return 0;
}
