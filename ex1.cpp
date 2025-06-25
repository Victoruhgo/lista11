#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool eh_primo(int n) { //função para primos
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <inicio> <fim>\n", argv[0]);
        return 1;
    }

    int inicio = atoi(argv[1]);
    int fim = atoi(argv[2]);

    if (inicio > fim) { //Para teste de erros
        printf("Erro: o valor de início deve ser menor ou igual ao valor de fim.\n");
        return 1;
    }

    printf("Números primos entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (eh_primo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
