#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// Código da Ilha – Edição Free Fire
// Nível: Aventureiro

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
        printf("\n===== MOCHILA COM BUSCA =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item por nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1: // Adicionar
                if (totalItens < MAX_ITENS) {
                    printf("Nome do item: ");
                    scanf(" %[^\n]", mochila[totalItens].nome);

                    printf("Tipo do item: ");
                    scanf(" %[^\n]", mochila[totalItens].tipo);

                    printf("Quantidade: ");
                    scanf("%d", &mochila[totalItens].quantidade);

                    totalItens++;
                    printf("Item adicionado com sucesso!\n");
                } else {
                    printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
                }
                break;

            case 2: // Remover
                if (totalItens > 0) {
                    printf("Digite o nome do item a remover: ");
                    scanf(" %[^\n]", nomeBusca);

                    int encontrado = 0;

                    for (i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                            encontrado = 1;

                            for (j = i; j < totalItens - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }

                            totalItens--;
                            printf("Item removido com sucesso!\n");
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("Item nao encontrado.\n");
                    }

                } else {
                    printf("A mochila esta vazia.\n");
                }
                break;

            case 3: // Listar
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
                } else {
                    printf("A mochila esta vazia.\n");
                }
                break;

            case 4: // Buscar
                if (totalItens > 0) {
                    printf("Digite o nome do item a buscar: ");
                    scanf(" %[^\n]", nomeBusca);

                    int encontrado = 0;

                    for (i = 0; i < totalItens; i++) {
                        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                            encontrado = 1;

                            printf("\n===== ITEM ENCONTRADO =====\n");
                            printf("Nome: %s\n", mochila[i].nome);
                            printf("Tipo: %s\n", mochila[i].tipo);
                            printf("Quantidade: %d\n", mochila[i].quantidade);
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("Item nao encontrado na mochila.\n");
                    }

                } else {
                    printf("A mochila esta vazia.\n");
                }
                break;

            case 0:
                printf("Acabou...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);

    return 0;
}
