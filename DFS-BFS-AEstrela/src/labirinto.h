#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "pilha.h"
#include "fila.h"
#include "lista.h"

#include <math.h>

#define MAXTAM 100
#define TAMVETOR 6

#define _MOD(X)((X) >= 0 ? (X) : -(X))
#define _MANHATTAN(X1, X2, Y1, Y2)(_MOD(X1 - X2) + _MOD(Y1 - Y2))
#define _EUCLIDIANA(X1, X2, Y1, Y2)(raiz(potencia((X1 - X2), 2) + potencia((Y1 - Y2), 2)))

typedef struct ItemControle {
	int i;
	int j;
	int bkp_i;
	int bkp_j;
} ItemControle;

typedef struct ItemLab {
	int val;
} ItemLab;

typedef struct Labirinto {
	Lista vLista[MAXTAM];

	int topo;
	int base;
} Labirinto;

void FLabirintoVazio(Labirinto *s);
void PUSHLAB(Labirinto *s, Lista l);
void LabirintoImprime(Labirinto *s);
void POPLAB(Labirinto *s, Lista *l);

int **lerEntrada(int op);
void tokenizar(char *str, int **matriz, int contador);

void FazBFS_Manhattan(int op);
void FazBFS_Euclidiana(int op);
void FazBFS(int op);
void FazDFS(int op);

void pathDFS(int *i, int *j, int *cont, int **matriz, int controle[4], Pilha *pilha, ItemPilha itemPilha);
void pathBFS(ItemControle ctr, int *cont, int **matriz, int v_controle[4], Fila *f);
void pathBFS_Manhattan(ItemControle ctr, int *cont, int **matriz, int v_controle[4], Fila *f, Pilha *p);
void pathBFS_Euclidiana(ItemControle ctr, int *cont, int **matriz, int v_controle[4], Fila *f, Pilha *p);
void matrizToLab(int **matriz, Lista *lista, Labirinto *lab);

float potencia(float base, int expoente);
float raiz(float val);

void result(int **matriz, int soma);

#endif