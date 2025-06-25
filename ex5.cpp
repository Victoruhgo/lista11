#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100
#define MAX_NOME 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
} ItemMenu;

typedef struct {
    ItemMenu item;
    int quantidade;
} Pedido;

int main() {
    FILE *menuFile = fopen("menu.txt", "r");
    if (!menuFile) {
        perror("Erro ao abrir menu.txt");
        return 1;
    }

    int qtdItens;
    fscanf(menuFile, "%d", &qtdItens);
    ItemMenu menu[MAX_ITENS];

    // Lê o menu
    for (int i = 0; i < qtdItens; i++) {
        fscanf(menuFile, "%d %s %f", &menu[i].id, menu[i].nome, &menu[i].preco);
    }

    Pedido pedidos[MAX_ITENS];
    int totalPedidos = 0;

    int opcao, quantidade;
    do {
        printf("\n====== MENU ======\n");
        rewind(menuFile);
        fscanf(menuFile, "%d", &qtdItens); // lê novamente qtd para realinhar leitura
        for (int i = 0; i < qtdItens; i++) {
            fscanf(menuFile, "%d %s %f", &menu[i].id, menu[i].nome, &menu[i].preco);
            printf("%d - %-15s R$ %.2f\n", menu[i].id, menu[i].nome, menu[i].preco);
        }

        printf("Digite o número do item (0 para finalizar): ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        int encontrado = 0;
        for (int i = 0; i < qtdItens; i++) {
            if (menu[i].id == opcao) {
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                pedidos[totalPedidos].item = menu[i];
                pedidos[totalPedidos].quantidade = quantidade;
                totalPedidos++;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Item inválido. Tente novamente.\n");
        }

    } while (1);

    fclose(menuFile);

    // Gerar boleto
    FILE *boleto = fopen("boleto.txt", "w");
    if (!boleto) {
        perror("Erro ao criar boleto.txt");
        return 1;
    }

    float total = 0;
    fprintf(boleto, "====== BOLETO DO PEDIDO ======\n");
    for (int i = 0; i < totalPedidos; i++) {
        float subt = pedidos[i].quantidade * pedidos[i].item.preco;
        fprintf(boleto, "%dx %-15s - R$ %.2f\n", pedidos[i].quantidade, pedidos[i].item.nome, subt);
        total += subt;
    }
    fprintf(boleto, "------------------------------\n");
    fprintf(boleto, "TOTAL: R$ %.2f\n", total);
    fclose(boleto);

    printf("\nPedido finalizado! Boleto salvo em 'boleto.txt'\n");
    return 0;
}
