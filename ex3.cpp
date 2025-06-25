#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CARTELAS 3
#define TAM 5

// Função para gerar números únicos dentro de um intervalo
void gerar_numeros(int *vetor, int inicio, int fim) {
    int count = 0;
    while (count < TAM) {
        int num = rand() % (fim - inicio + 1) + inicio;
        int repetido = 0;
        for (int i = 0; i < count; i++) {
            if (vetor[i] == num) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            vetor[count++] = num;
        }
    }
}

// Função de troca para ordenar os números (opcional)
void ordenar(int *vetor) {
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = i + 1; j < TAM; j++) {
            if (vetor[i] > vetor[j]) {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    FILE *arquivo = fopen("cartelas_bingo.csv", "w");
    if (!arquivo) {
        perror("Erro ao criar arquivo");
        return 1;
    }

    fprintf(arquivo, "B,I,N,G,O\n");

    for (int c = 0; c < CARTELAS; c++) {
        int B[TAM], I[TAM], N[TAM], G[TAM], O[TAM];
        gerar_numeros(B, 1, 15);
        gerar_numeros(I, 16, 30);
        gerar_numeros(N, 31, 45);
        gerar_numeros(G, 46, 60);
        gerar_numeros(O, 61, 75);

        ordenar(B);
        ordenar(I);
        ordenar(N);
        ordenar(G);
        ordenar(O);

        for (int i = 0; i < TAM; i++) {
            fprintf(arquivo, "%d,%d,", B[i], I[i]);
            if (i == 2)
                fprintf(arquivo, "FREE,");
            else
                fprintf(arquivo, "%d,", N[i]);
            fprintf(arquivo, "%d,%d\n", G[i], O[i]);
        }

        if (c < CARTELAS - 1) {
            fprintf(arquivo, "\n");
        }
    }

    fclose(arquivo);
    printf("Cartelas geradas com sucesso no arquivo 'cartelas_bingo.csv'\n");
    return 0;
}
