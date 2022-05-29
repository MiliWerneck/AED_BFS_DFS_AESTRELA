#include "labirinto.h"

void FazBFS_Euclidiana(int op) {

    int **matriz = lerEntrada(op);

    Fila fila;

    ItemFila itemFila;
    Pilha pilha;
    Labirinto lab;

    ItemControle ctr;
    ItemPilha itemPilha;

    FFVazia(&fila);
    FPVazia(&pilha);

    int i, j, cont;
    int linha, coluna;
    int bkp_i, bkp_j;
    int v_controle[4];
    int soma = 0;

    i = j = cont = 0;
    linha = coluna = TAMVETOR;

    if (matriz[i][j] != 0 || matriz[TAMVETOR - 1][TAMVETOR - 1] != 0) {
        printf("Primeira ou ultima posicao do matriz impossibilita os testes\n");
        return;
    }

    linha = coluna = TAMVETOR;

    if (matriz[i][j] == 0)
        matriz[i][j] = ++cont;

    while (i < linha && j < coluna) {
        if (i == linha - 1 && j == coluna - 1) {
            if (matriz[i][j] == 0)
                matriz[i][j] = ++cont;
            break;
        }

        bkp_i = i;
        bkp_j = j;
        soma++;

        v_controle[0] = v_controle[1] = v_controle[2] = v_controle[3] = 0;

        if (i == 0) {
            v_controle[0] = 1;
            if (!(j == coluna - 1))
                v_controle[1] = 1;
            if (!(j == 0))
                v_controle[2] = 1;
        } else if (i == linha - 1) {
            if (!(j == coluna - 1))
                v_controle[1] = 1;
            if (!(j == 0))
                v_controle[2] = 1;
            v_controle[3] = 1;
        } else if (j == 0)
            v_controle[0] = v_controle[1] = v_controle[3] = 1;
        else if (j == coluna - 1)
            v_controle[0] = v_controle[2] = v_controle[3] = 1;
        else
            v_controle[0] = v_controle[1] = v_controle[2] = v_controle[3] = 1;

        ctr.i = i;
        ctr.j = j;
        ctr.bkp_i = bkp_i;
        ctr.bkp_j = bkp_j;

        pathBFS_Euclidiana(ctr, &cont, matriz, v_controle, &fila, &pilha);

        if (fila.last > fila.first) {
            Desenfileira(&fila, &itemFila);

            i = itemFila.x1;
            j = itemFila.y1;
        }
        if (bkp_i == i && bkp_j == j && pilha.top > pilha.base) {
            POP(&pilha, &itemPilha);
            i = itemPilha.val_I;
            j = itemPilha.val_J;
        }

        if (bkp_i == i && bkp_j == j) {
            printf("impossivel chegar no caminho final\n");
            return;
        }
    }
    result(matriz, soma);
}

void pathBFS_Euclidiana(ItemControle ctr, int *cont, int **matriz, int v_controle[4], Fila *f, Pilha *pilha) {
    ItemFila backup;
    ItemFila itemFila;
    ItemPilha itemPilha;

    if (v_controle[0] == 1 && matriz[ctr.i + 1][ctr.j] == 0) { // 1
        matriz[ctr.i + 1][ctr.j] = ++(*cont);

        itemFila.x1 = ctr.i + 1;
        itemFila.y1 = ctr.bkp_j;
        itemFila.val = _EUCLIDIANA(itemFila.x1, TAMVETOR - 1, itemFila.y1, TAMVETOR - 1);
        Enfileira(f, itemFila);

        itemPilha.val_I = itemFila.x1;
        itemPilha.val_J = itemFila.y1;

        PUSH(pilha, itemPilha);
    }

    if (v_controle[1] == 1 && matriz[ctr.i][ctr.j + 1] == 0) { // 2
        itemFila.x1 = ctr.bkp_i;
        itemFila.y1 = ctr.j + 1;
        itemFila.val = _EUCLIDIANA(itemFila.x1, TAMVETOR - 1, itemFila.y1, TAMVETOR - 1);

        if (f->first < f->last) {
            Desenfileira(f, &backup);

            if (itemFila.val < backup.val) {
                matriz[ctr.i][ctr.j + 1] = ++(*cont);
                Enfileira(f, itemFila);
            } else {
                itemPilha.val_I = ctr.bkp_i;
                itemPilha.val_J = ctr.bkp_j;

                Enfileira(f, backup);
                PUSH(pilha, itemPilha);
            }
        } else {
            matriz[ctr.i][ctr.j + 1] = ++(*cont);
            Enfileira(f, itemFila);
        }
    }

   
    if (v_controle[2] == 1 && matriz[ctr.i][ctr.j - 1] == 0) { // 3
        itemFila.x1 = ctr.bkp_i;
        itemFila.y1 = ctr.j - 1;
        itemFila.val = _EUCLIDIANA(itemFila.x1, TAMVETOR - 1, itemFila.y1, TAMVETOR - 1);

        if (f->first < f->last) {
            Desenfileira(f, &backup);

            if (itemFila.val < backup.val) {
                matriz[ctr.i][ctr.j - 1] = ++(*cont);
                Enfileira(f, itemFila);
            } else {
                itemPilha.val_I = ctr.bkp_i;
                itemPilha.val_J = ctr.bkp_j;

                Enfileira(f, backup);
                PUSH(pilha, itemPilha);
            }
        } else {
            matriz[ctr.i][ctr.j - 1] = ++(*cont);
            Enfileira(f, itemFila);
        }
    }

    if (v_controle[3] == 1 && matriz[ctr.i - 1][ctr.j] == 0) { // 4
        itemFila.x1 = ctr.i - 1;
        itemFila.y1 = ctr.bkp_j;
        itemFila.val = _EUCLIDIANA(itemFila.x1, TAMVETOR - 1, itemFila.y1, TAMVETOR - 1);

        if (f->first < f->last) {
            Desenfileira(f, &backup);

            if (itemFila.val < backup.val) {
                matriz[ctr.i - 1][ctr.j] = ++(*cont);
                Enfileira(f, itemFila);
            } else {
                itemPilha.val_I = ctr.bkp_i;
                itemPilha.val_J = ctr.bkp_j;

                Enfileira(f, backup);
                PUSH(pilha, itemPilha);
            }
        } else {
            matriz[ctr.i - 1][ctr.j] = ++(*cont);
            Enfileira(f, itemFila);
        }
    }
}

void FazBFS_Manhattan(int op) {

    int **matriz = lerEntrada(op);

    Fila fila;

    ItemFila itemFila;
    Pilha pilha;
    Labirinto lab;

    ItemControle ctr;
    ItemPilha itemPilha;

    FFVazia(&fila);
    FPVazia(&pilha);

    int i, j, cont;
    int linha, coluna;
    int bkp_i, bkp_j;
    int v_controle[4];
    int soma = 0;

    i = j = cont = 0;
    linha = coluna = TAMVETOR;

    if (matriz[i][j] != 0 || matriz[TAMVETOR - 1][TAMVETOR - 1] != 0) {
        printf("Primeira ou ultima posicao do matriz impossibilita os testes\n");
        return;
    }

    linha = coluna = TAMVETOR;

    if (matriz[i][j] == 0)
        matriz[i][j] = ++cont;

    while (i < linha && j < coluna) {
        if (i == linha - 1 && j == coluna - 1) {
            if (matriz[i][j] == 0)
                matriz[i][j] = ++cont;
            break;
        }

        bkp_i = i;
        bkp_j = j;
        soma++;

        v_controle[0] = v_controle[1] = v_controle[2] = v_controle[3] = 0;

        if (i == 0) {
            v_controle[0] = 1;
            if (!(j == coluna - 1))
                v_controle[1] = 1;
            if (!(j == 0))
                v_controle[2] = 1;
        } else if (i == linha - 1) {
            if (!(j == coluna - 1))
                v_controle[1] = 1;
            if (!(j == 0))
                v_controle[2] = 1;
            v_controle[3] = 1;
        } else if (j == 0)
            v_controle[0] = v_controle[1] = v_controle[3] = 1;
        else if (j == coluna - 1)
            v_controle[0] = v_controle[2] = v_controle[3] = 1;
        else
            v_controle[0] = v_controle[1] = v_controle[2] = v_controle[3] = 1;

        ctr.i = i;
        ctr.j = j;
        ctr.bkp_i = bkp_i;
        ctr.bkp_j = bkp_j;

        pathBFS_Manhattan(ctr, &cont, matriz, v_controle, &fila, &pilha);

        if (fila.last > fila.first) {
            Desenfileira(&fila, &itemFila);

            i = itemFila.x1;
            j = itemFila.y1;
        }
        if (bkp_i == i && bkp_j == j && pilha.top > pilha.base) {
            POP(&pilha, &itemPilha);
            i = itemPilha.val_I;
            j = itemPilha.val_J;
        }

        if (bkp_i == i && bkp_j == j) {
            printf("impossivel chegar no caminho final\n");
            return;
        }
    }
    result(matriz, soma);
}

void pathBFS_Manhattan(ItemControle ctr, int *cont, int **matriz, int v_controle[4], Fila *f, Pilha *pilha) {
    ItemFila backup;
    ItemFila itemFila;
    ItemPilha itemPilha;

    if (v_controle[0] == 1 && matriz[ctr.i + 1][ctr.j] == 0) { // 1
        matriz[ctr.i + 1][ctr.j] = ++(*cont);

        itemFila.x1 = ctr.i + 1;
        itemFila.y1 = ctr.bkp_j;
        itemFila.val = _MANHATTAN(itemFila.x1, TAMVETOR - 1, itemFila.y1, TAMVETOR - 1);
        Enfileira(f, itemFila);

        itemPilha.val_I = itemFila.x1;
        itemPilha.val_J = itemFila.y1;

        PUSH(pilha, itemPilha);
    }

    if (v_controle[1] == 1 && matriz[ctr.i][ctr.j + 1] == 0) { // 2
        itemFila.x1 = ctr.bkp_i;
        itemFila.y1 = ctr.j + 1;
        itemFila.val = _MANHATTAN(itemFila.x1, TAMVETOR - 1, itemFila.y1, TAMVETOR - 1);

        if (f->first < f->last) {
            Desenfileira(f, &backup);

            if (itemFila.val < backup.val) {
                matriz[ctr.i][ctr.j + 1] = ++(*cont);
                Enfileira(f, itemFila);
            } else {
                itemPilha.val_I = ctr.bkp_i;
                itemPilha.val_J = ctr.bkp_j;

                Enfileira(f, backup);
                PUSH(pilha, itemPilha);
            }
        } else {
            matriz[ctr.i][ctr.j + 1] = ++(*cont);
            Enfileira(f, itemFila);
        }
    }

    if (v_controle[2] == 1 && matriz[ctr.i][ctr.j - 1] == 0) { // 3
        itemFila.x1 = ctr.bkp_i;
        itemFila.y1 = ctr.j - 1;
        itemFila.val = _MANHATTAN(itemFila.x1, TAMVETOR - 1, itemFila.y1, TAMVETOR - 1);

        if (f->first < f->last) {
            Desenfileira(f, &backup);

            if (itemFila.val < backup.val) {
                matriz[ctr.i][ctr.j - 1] = ++(*cont);
                Enfileira(f, itemFila);
            } else {
                itemPilha.val_I = ctr.bkp_i;
                itemPilha.val_J = ctr.bkp_j;

                Enfileira(f, backup);
                PUSH(pilha, itemPilha);
            }
        } else {
            matriz[ctr.i][ctr.j - 1] = ++(*cont);
            Enfileira(f, itemFila);
        }
    }

    if (v_controle[3] == 1 && matriz[ctr.i - 1][ctr.j] == 0) { // 4
        itemFila.x1 = ctr.i - 1;
        itemFila.y1 = ctr.bkp_j;
        itemFila.val = _MANHATTAN(itemFila.x1, TAMVETOR - 1, itemFila.y1, TAMVETOR - 1);

        if (f->first < f->last) {
            Desenfileira(f, &backup);

            if (itemFila.val < backup.val) {
                matriz[ctr.i - 1][ctr.j] = ++(*cont);
                Enfileira(f, itemFila);
            } else {
                itemPilha.val_I = ctr.bkp_i;
                itemPilha.val_J = ctr.bkp_j;

                Enfileira(f, backup);
                PUSH(pilha, itemPilha);
            }
        } else {
            matriz[ctr.i - 1][ctr.j] = ++(*cont);
            Enfileira(f, itemFila);
        }
    }
}

float raiz(float numero) {
    float precisao = 0.000001;
    float b = numero, a = 1;

    while ((b - a) >= precisao) {
        b = (a + b) / 2;
        a = numero / b;
    }
    return b;
}

float potencia(float base, int expoente) {
    float res = 1;

    while (expoente-- > 0)
        res = res * base;
    return res;
}