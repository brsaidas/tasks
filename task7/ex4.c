#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    srand(time(NULL));

    int mat[10][10], aux[10][10];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mat[i][j] = rand() % 10;
        }
    }

    printf("MATRIZ ORIGINAL\n");

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            aux[i][j] = mat[i][j];
        }
    }

    for(int j = 0; j < 10; j++){
        mat[1][j] = aux[7][j];
        mat[7][j] = aux[1][j];
    }

    printf("TROCA LINHA 2 COM LINHA 8\n");

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            aux[i][j] = mat[i][j];
        }
    }

    for(int i = 0; i < 10; i++){
        mat[i][3] = aux[i][9];
        mat[i][9] = aux[i][3];
    }

    printf("TROCA COLUNA 3 COM COLUNA 10\n");

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            aux[i][j] = mat[i][j];
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mat[i][j] = aux[i][9-j];
            mat[i][9-j] = aux[i][j];
        }
    }

    printf("DIAGONAL PRINCIPAL E SECUNDARIA\n");

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
