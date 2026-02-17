#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITENS 10

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.
struct Item {
    char nome[50];
    char tipo[30];
    int quantidade;
    int prioridade;
};

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).
enum CriterioOrdenacao {
    POR_NOME = 1,
    POR_TIPO,
    POR_PRIORIDADE
};

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).
struct Item mochila[MAX_ITENS];
int numItens = 0;
int comparacoes = 0;
bool ordenadaPorNome = false;

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.
void limparTela() {
    for (int i = 0; i < 30; i++)
        printf("\n");
}

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.
void exibirMenu() {
    printf("===== CODIGO DA ILHA =====\n");
    printf("Status ordenacao por nome: %s\n", ordenadaPorNome ? "SIM" : "NAO");
    printf("1 - Adicionar item\n");
    printf("2 - Remover item\n");
    printf("3 - Listar itens\n");
    printf("4 - Ordenar itens\n");
    printf("5 - Busca binaria por nome\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".
void inserirItem() {
    if (numItens < MAX_ITENS) {
        printf("Nome: ");
        scanf(" %[^\n]", mochila[numItens].nome);

        printf("Tipo: ");
        scanf(" %[^\n]", mochila[numItens].tipo);

        printf("Quantidade: ");
        scanf("%d", &mochila[numItens].quantidade);

        printf("Prioridade (1-5): ");
        scanf("%d", &mochila[numItens].prioridade);

        numItens++;
        ordenadaPorNome = false;
    }
}

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.
void removerItem() {
    char nomeBusca[50];
    printf("Nome do item a remover: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            for (int j = i; j < numItens - 1; j++)
                mochila[j] = mochila[j + 1];
            numItens--;
            break;
        }
    }
}

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.
void listarItens() {
    printf("\n%-20s %-15s %-10s %-10s\n",
           "NOME", "TIPO", "QTD", "PRIORIDADE");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < numItens; i++) {
        printf("%-20s %-15s %-10d %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade,
               mochila[i].prioridade);
    }
}

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)
void insertionSort(enum CriterioOrdenacao criterio) {
    comparacoes = 0;

    for (int i = 1; i < numItens; i++) {
        struct Item chave = mochila[i];
        int j = i - 1;

        while (j >= 0) {
            comparacoes++;

            int condicao = 0;

            if (criterio == POR_NOME)
                condicao = strcmp(mochila[j].nome, chave.nome) > 0;
            else if (criterio == POR_TIPO)
                condicao = strcmp(mochila[j].tipo, chave.tipo) > 0;
            else if (criterio == POR_PRIORIDADE)
                condicao = mochila[j].prioridade < chave.prioridade;

            if (!condicao)
                break;

            mochila[j + 1] = mochila[j];
            j--;
        }

        mochila[j + 1] = chave;
    }

    ordenadaPorNome = (criterio == POR_NOME);
}

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).
void menuDeOrdenacao() {
    int opcao;
    printf("1 - Nome\n2 - Tipo\n3 - Prioridade\n");
    printf("Escolha criterio: ");
    scanf("%d", &opcao);

    insertionSort(opcao);

    printf("Comparacoes realizadas: %d\n", comparacoes);
}

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
void buscaBinariaPorNome() {
    if (!ordenadaPorNome) {
        printf("Ordene por nome antes de usar busca binaria.\n");
        return;
    }

    char nomeBusca[50];
    printf("Nome do item: ");
    scanf(" %[^\n]", nomeBusca);

    int inicio = 0, fim = numItens - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int resultado = strcmp(mochila[meio].nome, nomeBusca);

        if (resultado == 0) {
            printf("\nItem encontrado:\n");
            printf("Nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);
            printf("Prioridade: %d\n", mochila[meio].prioridade);
            return;
        }
        else if (resultado < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    printf("Item nao encontrado.\n");
}

int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: menuDeOrdenacao(); break;
            case 5: buscaBinariaPorNome(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
