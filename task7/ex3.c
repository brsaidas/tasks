#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

int main(int argc, char *argv[]){

    srand(time(NULL));

    bool bandeira, erro = true;
    int mat[5][7], min, max;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            mat[i][j] = rand() % 100;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }


    min = 10;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            if(mat[i][j] < min){
                min = mat[i][j];
            }
        }
        for(int j = 0; j < 7; j++){
            if(mat[i][j] == min){
                max = mat[i][j];
                bandeira = true;
                for(int k = 0; k < 5; k++){
                    if(mat[k][j] > max){
                        bandeira = false;
                        break;
                    }
                }
                if(bandeira == true){
                    erro = false;
                    printf("MAT[%d][%d] = %d\n", i, j, mat[i][j]);
                }
            }
        }
    }

    if(erro = true){
        printf("Erro: Nao existe ponto de sela");
    }

    return 0;
}
