#include "labirinto.h"

int **lerEntrada(int op) {
	int **matriz;
	int contador = 0;

	matriz = (int **)malloc(TAMVETOR * sizeof(int *));

	for (int i = 0; i < TAMVETOR; i++)
		matriz[i] = (int *)malloc(TAMVETOR * sizeof(int));

	char *str = (char *)malloc(100);
	sprintf(str, "src/entradas/entrada%d.txt", op);

	FILE *file = fopen(str, "r");

	char *result, linha[400];

	if (file == NULL) {
		printf("Nao foi possivel abrir o arquivo\n");
	} else {
		while (!feof(file)) {
			result = fgets(linha, sizeof(linha), file);

			if (result) {
				tokenizar(linha, matriz, contador);
				contador++;
			}
		}
	}
	fclose(file);
	return matriz;
}

void tokenizar(char *str, int **matriz, int contador) {
	const char sep[] = " ";
	char *tokens;
	int coluna = 0;

	tokens = strtok(str, sep);

	while (tokens != NULL) {
		matriz[contador][coluna++] = atoi(tokens);
		tokens = strtok(NULL, sep);
	}
}