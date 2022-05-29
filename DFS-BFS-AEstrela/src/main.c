#include "labirinto.h"
#include <time.h>

int Menu();
int main() {

    int opcao = -1;

    while (opcao != 0) {
        clock_t time;
        double sec;
        double ter;
        double qua;
        double qui;

        time = clock();

        sec = ((clock() - time) / (double)CLOCKS_PER_SEC);

        system("clear");

        opcao = Menu();

        if (opcao > 0 && opcao <= 7) {
            printf("Fazendo com BFS:\n");
            time = clock();
            FazBFS(opcao);
            sec = ((clock() - time) / (double)CLOCKS_PER_SEC);

            printf("\nFazendo com DFS:\n");
            time = clock();
            FazDFS(opcao);
            ter = ((clock() - time) / (double)CLOCKS_PER_SEC);
            printf("\n");

            printf("Fazendo com Euclidiana:\n");
            time = clock();
            FazBFS_Euclidiana(opcao);
            qua = ((clock() - time) / (double)CLOCKS_PER_SEC);
            printf("\n");

            printf("Fazendo com Manhattan:\n");
            time = clock();
            FazBFS_Manhattan(opcao);
            qui = ((clock() - time) / (double)CLOCKS_PER_SEC);
            printf("\n");

            printf("Tempo BFS: %lf\nTempo DFS: %lf\nTempo Euclidiana: %lf\nTempo Manhattan: %lf\n", sec, ter,qua, qui);

        } else if (opcao == 0) {
            printf("O programa sera finalizado\n");
            break;
        } else {
            printf("Opcao invalida\n");
        }
        system("read -p \"\nPressione enter para continuar...\" continue");
    }
    return 0;
}

int Menu() {
    int opcao;

    printf("\n============\n");
    printf("    MENU\n");
    printf("============\n\n");
    printf("1 - BFS - DFS - Euclidiana - Manhattan - Entrada 1\n");
    printf("2 - BFS - DFS - Euclidiana - Manhattan - Entrada 2\n");
    printf("3 - BFS - DFS - Euclidiana - Manhattan - Entrada 3\n");
    printf("4 - BFS - DFS - Euclidiana - Manhattan - Entrada 4\n");
    printf("5 - BFS - DFS - Euclidiana - Manhattan - Entrada 5\n");
    printf("6 - BFS - DFS - Euclidiana - Manhattan - Entrada 6\n");
    printf("7 - BFS - DFS - Euclidiana - Manhattan - Entrada 7\n");
    printf("0 - SAIR \n");

    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");

    return opcao;
}