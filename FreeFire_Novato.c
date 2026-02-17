#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// Código da Ilha – Edição Free Fire
// Nível: Novato

struct Item {
    char nome[50];
    char tipo[30];
    int quantidade;
};

int main() {
    struct Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao;
    int i, j;
    char nomeBusca[50];

    do {
        printf("\n===== INVENTARIO BASICO =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                if (totalItens < MAX_ITENS) {
                    printf("Nome do item: ");
                    scanf(" %[^\n]", mochila[totalItens].nome);

                    printf("Tipo do item: ");
                    scanf(" %[^\n]", mochila[totalItens].tipo);

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);

                    totalItens++;
                    printf("Item adicionado com sucesso!\n");
                }
                break;

            case 2:
                if (totalItens > 0) {
                    printf("Digite o nome do item a remover: ");
                    scanf(" %[^\n]", nomeBusca);

                    for (i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

                            for (j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }

                            totalItens--;
                            printf("Item removido com sucesso!\n");
                            break;
                        }
                    }
                }
                break;

            case 3:
                if (totalItens > 0) {
                    printf("\n===== ITENS NA MOCHILA =====\n");
                    printf("%-20s %-15s %-10s\n", "NOME", "TIPO", "QUANTIDADE");
                    printf("-------------------------------------------------\n");

                    for (i = 0; i < totalItens; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                }
                break;

            case 0:
                printf("Acabou...\n");
                break;
        }

    } while(opcao != 0);

    return 0;
}
