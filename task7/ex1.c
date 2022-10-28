#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

int main(int argc, char *argv[]){

    srand(time(NULL));

    char opcao;
    bool bandeira;
    int vet1[10], vet2[10], vetUniao[20], contador;

    printf("(A) - UNIAO\n");
    printf("(B) - SOMA\n");
    printf("(C) - PRODUTO\n");
    printf("QUAL OPCAO: ");
    scanf("%c", &opcao);

    for(int i = 0; i < 10; i++){
        vet1[i] = rand() % 20;
        vet2[i] = rand() % 20;
    }

    printf("VET1: ");

    for(int i = 0; i < 10; i++){
        printf("[%d]", vet1[i]);
    }

    printf("\nVET2: ");

    for(int i = 0; i < 10; i++){
        printf("[%d]", vet2[i]);
    }

    printf("\n");

    switch(opcao){

        case 'A':

            for(int i = 0; i < 20; i++){
                vetUniao[i] = -1;
            }

            contador = 0;

            for(int i = 0; i < 10; i++){
                bandeira = true;
                for(int k = 0; k < 20; k++){
                    if(vet1[i] == vetUniao[k]){
                        bandeira = false;
                        break;
                    }
                }
                if(bandeira == true){
                    vetUniao[contador] = vet1[i];
                    contador++;
                }
            }

            for(int i = 0; i < 10; i++){
                bandeira = true;
                for(int k = 0; k < 20; k++){
                    if(vet2[i] == vetUniao[k]){
                        bandeira = false;
                        break;
                    }
                }
                if(bandeira == true){
                    vetUniao[contador] = vet2[i];
                    contador++;
                }
            }

            printf("UNIAO: ");

            for(int i = 0; i < 20; i++){
                if(vetUniao[i] != -1){
                    printf("[%d]", vetUniao[i]);
                }else{
                    break;
                }
            }

            break;

        case 'B':

            printf("SOMA: ");

            for(int i = 0; i < 10; i++){
                printf("[%d]", vet1[i]+vet2[i]);
            }

            break;

        case 'C':

            printf("PRODUTO: ");

            for(int i = 0; i < 10; i++){
                printf("[%d]", vet1[i]*vet2[i]);
            }

            break;

        default:
            break;
    }

    return 0;
}
