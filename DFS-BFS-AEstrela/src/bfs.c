#include "labirinto.h"

void FazBFS(int op) {
    int **matriz = lerEntrada(op);

    Fila fila;

    ItemFila itemFila;
    ItemControle ctr;

    FFVazia(&fila);

    int i, j, iA, jA, cont;
    int linha, coluna;
    int bkp_i, bkp_j;
    int v_controle[4];
    int soma = 0;

    i = j = iA = jA = cont = 0;
    linha = coluna = TAMVETOR;

    if (matriz[i][j] != 0 || matriz[TAMVETOR - 1][TAMVETOR - 1] != 0) {
        printf("Primeira ou ultima posicao do matriz impossibilita os testes\n");
        return;
    }

    if (matriz[i][j] == 0)
        matriz[i][j] = ++cont;

    while (i < linha && j < coluna) {
        bkp_i = i;
        bkp_j = j;
        soma++;

        v_controle[0] = v_controle[1] = v_controle[2] = v_controle[3] = 0;

        if (i == 0) {
            v_controle[0] = 1;
            if (!(j == coluna - 1)) v_controle[1] = 1;
            if (!(j == 0))          v_controle[2] = 1;
        }
        else if (i == linha - 1) {
            if (!(j == coluna - 1)) v_controle[1] = 1;
            if (!(j == 0))          v_controle[2] = 1;
            v_controle[3] = 1;
        }
        else if (j == 0)
            v_controle[0] = v_controle[1] = v_controle[3] = 1;
        else if (j == coluna - 1)
            v_controle[0] = v_controle[2] = v_controle[3] = 1;
        else
            v_controle[0] = v_controle[1] = v_controle[2] = v_controle[3] = 1;

        ctr.i = i;
        ctr.j = j;
        ctr.bkp_i = bkp_i;
        ctr.bkp_j = bkp_j;

        pathBFS(ctr, &cont, matriz, v_controle, &fila);

        if (i == linha - 1 && j == coluna - 1) {
            if (matriz[i][j] == 0)
                matriz[i][j] = ++cont;
            break;
        }
        Desenfileira(&fila, &itemFila);

        i = itemFila.x1;
        j = itemFila.y1;

        if (bkp_i == i && bkp_j == j) {
            printf("impossivel chegar no caminho final\n");
            return;
        }
    }
    result(matriz, soma);
}

void pathBFS(ItemControle ctr, int *cont, int **matriz, int v_controle[4], Fila *f){
    ItemFila itemFila;

    if (v_controle[0] == 1 && matriz[ctr.i + 1][ctr.j] == 0) { // 1
        matriz[ctr.i + 1][ctr.j] = ++(*cont);

        itemFila.x1 = ctr.i+1;
        itemFila.y1 = ctr.bkp_j;
        Enfileira(f, itemFila);
    }
    if (v_controle[1] == 1 && matriz[ctr.i][ctr.j + 1] == 0) { // 2
        matriz[ctr.i][ctr.j + 1] = ++(*cont);

        itemFila.x1 = ctr.bkp_i;
        itemFila.y1 = ctr.j+1;
        Enfileira(f, itemFila);
    }
    if (v_controle[2] == 1 && matriz[ctr.i][ctr.j - 1] == 0) { // 3
        matriz[ctr.i][ctr.j - 1] = ++(*cont);

        itemFila.x1 = ctr.bkp_i;
        itemFila.y1 = ctr.j - 1;
        Enfileira(f, itemFila);
    }
    if (v_controle[3] == 1 && matriz[ctr.i - 1][ctr.j] == 0) { // 4
        matriz[ctr.i - 1][ctr.j] = ++(*cont);

        itemFila.x1 = ctr.i - 1;
        itemFila.y1 = ctr.bkp_j;
        Enfileira(f, itemFila);
    }
}