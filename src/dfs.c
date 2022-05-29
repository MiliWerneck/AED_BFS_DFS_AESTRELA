#include "labirinto.h"

void FazDFS(int op) {
    int **matriz = lerEntrada(op);

    Pilha pilha;
    Lista lista;
    Labirinto lab;
    Labirinto labAux;

    ItemPilha itemPilha;

    int i, j, iA, jA, cont;
    int aux_i, aux_j;
    int linha, coluna;
    int soma;

    int controle[4];

    FLabirintoVazio(&lab);
    FLabirintoVazio(&labAux);

    matrizToLab(matriz, &lista, &lab);

    FPVazia(&pilha);
    FLVazia(&lista);

    i = j = iA = jA = cont = 0;
    aux_i = aux_j = 0;
    soma = 0;

    if (matriz[i][j] != 0 || matriz[TAMVETOR - 1][TAMVETOR - 1] != 0) {
        printf("Primeira ou ultima posicao do matriz impossibilita os testes\n");
        return;
    }

    itemPilha.val_I = 0;
    itemPilha.val_J = 0;

    linha = coluna = TAMVETOR;

    if (matriz[i][j] == 0)
        matriz[i][j] = ++cont;

    POPLAB(&lab, &lista);
    PUSHLAB(&labAux, lista);

    while (i < linha && j < coluna) {
        if (!(itemPilha.val_I == i && itemPilha.val_J == j)) {
            itemPilha.val_I = iA;
            itemPilha.val_J = jA;
            PUSH(&pilha, itemPilha);
        }

        soma++;
        iA = aux_i = i;
        jA = aux_j = j;

        controle[0] = controle[1] = controle[2] = controle[3] = 0;

        if (i == 0) {
            controle[0] = 1;
            if (!(j == coluna - 1)) controle[1] = 1;
            if (!(j == 0))          controle[2] = 1;
        } else if (i == linha - 1) {
            if (!(j == coluna - 1)) controle[1] = 1;
            if (!(j == 0))          controle[2] = 1;
            controle[3] = 1;
        } else if (j == 0)
            controle[0] = controle[1] = controle[3] = 1;
        else if (j == coluna - 1)
            controle[0] = controle[2] = controle[3] = 1;
        else
            controle[0] = controle[1] = controle[2] = controle[3] = 1;

        pathDFS(&i, &j, &cont, matriz, controle, &pilha, itemPilha);

        if (aux_i == i && aux_j == j) {
            printf("impossivel chegar no caminho final\n");
            return;
        }

        if (i == linha - 1 && j == coluna - 1) {
            if (matriz[i][j] == 0)
                matriz[i][j] = ++cont;
            break;
        }
    }
    result(matriz, soma);
}

void pathDFS(int *i, int *j, int *cont, int **matriz, int controle[4], Pilha *pilha, ItemPilha itemPilha) {
    if (controle[0] == 1 && matriz[*i + 1][*j] == 0) {
        matriz[*i + 1][*j] = ++(*cont);
        (*i)++;
    } else if (controle[1] == 1 && matriz[*i][*j + 1] == 0) {
        matriz[*i][*j + 1] = ++(*cont);
        (*j)++;
    } else if (controle[2] == 1 && matriz[*i][*j - 1] == 0) {
        matriz[*i][*j - 1] = ++(*cont);
        (*j)--;
    } else if (controle[3] == 1 && matriz[*i - 1][*j] == 0) {
        matriz[*i - 1][*j] = ++(*cont);
        (*i)--;
    } else {
        POP(pilha, &itemPilha);

        (*i) = itemPilha.val_I;
        (*j) = itemPilha.val_J;
    }
}

void matrizToLab(int **matriz, Lista *lista, Labirinto *lab) {
    ItemLista itemLista;

    for (int i = TAMVETOR - 1; i >= 0; i--) {
        FLVazia(lista);

        for (int j = 0; j < TAMVETOR; j++) {
            itemLista.val = matriz[i][j];
            LInsert(lista, itemLista);
        }
        PUSHLAB(lab, *lista);
    }
}