#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da estrutura que representa cada item da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Protótipos das funções
void inserirItem(Item mochila[], int *numItens);
void removerItem(Item mochila[], int *numItens);
void listarItens(Item mochila[], int numItens);
void buscarItem(Item mochila[], int numItens);

int main() {
    Item mochila[10];  // Vetor que armazena até 10 itens
    int numItens = 0;  // Contador de itens cadastrados
    int opcao;

    do {
        printf("\n===== MOCHILA DE LOOT =====\n");
        printf("1. Cadastrar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                inserirItem(mochila, &numItens);
                break;
            case 2:
                removerItem(mochila, &numItens);
                break;
            case 3:
                listarItens(mochila, numItens);
                break;
            case 4:
                buscarItem(mochila, numItens);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Função para inserir um novo item na mochila
void inserirItem(Item mochila[], int *numItens) {
    if (*numItens >= 10) {
        printf("\nA mochila esta cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novoItem;

    printf("\n=== Cadastro de Item ===\n");
    printf("Nome do item: ");
    fgets(novoItem.nome, 30, stdin);
    novoItem.nome[strcspn(novoItem.nome, "\n")] = 0; // Remove o \n

    printf("Tipo (arma, municao, cura, etc): ");
    fgets(novoItem.tipo, 20, stdin);
    novoItem.tipo[strcspn(novoItem.tipo, "\n")] = 0;

    printf("Quantidade: ");
    scanf("%d", &novoItem.quantidade);
    getchar(); // Limpa buffer

    mochila[*numItens] = novoItem;
    (*numItens)++;

    printf("\nItem adicionado com sucesso!\n");
    listarItens(mochila, *numItens);
}

// Função para remover um item da mochila pelo nome
void removerItem(Item mochila[], int *numItens) {
    if (*numItens == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item a remover: ");
    fgets(nomeRemover, 30, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = 0;

    int encontrado = 0;
    for (int i = 0; i < *numItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            for (int j = i; j < *numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*numItens)--;
            encontrado = 1;
            printf("\nItem removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado)
        printf("\nItem nao encontrado.\n");

    listarItens(mochila, *numItens);
}

// Função para listar todos os itens da mochila
void listarItens(Item mochila[], int numItens) {
    printf("\n=== Itens na mochila (%d/10) ===\n", numItens);
    if (numItens == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    for (int i = 0; i < numItens; i++) {
        printf("Item %d:\n", i + 1);
        printf(" Nome: %s\n", mochila[i].nome);
        printf(" Tipo: %s\n", mochila[i].tipo);
        printf(" Quantidade: %d\n", mochila[i].quantidade);
        printf("----------------------\n");
    }
}

// Função para buscar um item pelo nome (busca sequencial)
void buscarItem(Item mochila[], int numItens) {
    if (numItens == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item para buscar: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf(" Nome: %s\n", mochila[i].nome);
            printf(" Tipo: %s\n", mochila[i].tipo);
            printf(" Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("\nItem nao encontrado na mochila.\n");
}
