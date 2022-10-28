#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

int main(int argc, char *argv[]){

    srand(time(NULL));

    int vet[10];
    bool bandeira;

    printf("VET: ");

    for(int i = 0; i < 10; i++){
        vet[i] = rand() % 100;
        printf("[%d]", vet[i]);
    }

    printf("\n");

    bandeira = false;
    for(int i = 0; i < 10; i++){
        if(vet[i] > 50){
            printf("VET[%d] = %d\n", i, vet[i]);
            bandeira = true;
        }
    }

    if(bandeira == false){
        printf("Erro: Todos os valores menores que 50");
    }

    return 0;
}
