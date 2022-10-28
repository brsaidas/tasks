#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

int main(int argc, char *argv[]){

    while(true){

        bool fim;
        char matriz[10][10], jogar;
        int movimento, linha = 4, coluna = 4, vida, contador, aux;

        srand(time(NULL));

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                matriz[i][j] = ' ';
            }
        }

        matriz[linha][coluna] = 'o';

        int cont = 0;
        while(cont < 40){
            int lin = rand() % 9;
            int col = rand() % 9;

            if(matriz[lin][col] == ' '){
                matriz[lin][col] = '-';
                cont++;
            }
        }

        aux = 0;
        vida = 3;
        contador = 0;

        do{

            system("cls");

            printf("VIDAS: %d|MOVIMENTOS: %d|COLETADAS: %d\n", vida, contador, aux);

            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    printf("[%c]", matriz[i][j]);
                }
                printf("\n");
            }

            movimento = getch();

            switch(movimento){
                case 'w':
                    if(linha-1 >= 0){
                        if(matriz[linha-1][coluna] == '-'){
                            aux++;
                            vida++;
                        }else{
                            vida--;
                        }
                        matriz[linha][coluna] = ' ';
                        matriz[linha-1][coluna] = 'o';
                        linha--;
                        contador++;
                    }
                    break;

                case 'a':
                    if(coluna-1 >= 0){
                        if(matriz[linha][coluna-1] == '-'){
                            aux++;
                            vida++;
                        }else{
                            vida--;
                        }
                        matriz[linha][coluna] = ' ';
                        matriz[linha][coluna-1] = 'o';
                        coluna--;
                        contador++;
                    }
                    break;

                case 'd':
                    if(coluna+1 <= 9){
                        if(matriz[linha][coluna+1] == '-'){
                            aux++;
                            vida++;
                        }else{
                            vida--;
                        }
                        matriz[linha][coluna] = ' ';
                        matriz[linha][coluna+1] = 'o';
                        coluna++;
                        contador++;
                    }
                    break;

                case 's':
                    if(linha+1 <= 9){
                        if(matriz[linha+1][coluna] == '-'){
                            aux++;
                            vida++;
                        }else{
                            vida--;
                        }
                        matriz[linha][coluna] = ' ';
                        matriz[linha+1][coluna] = 'o';
                        linha++;
                        contador++;
                    }
                    break;

                default:
                    break;
            }

        }while((vida >= 0 && contador <= 80) && (aux < 40));

        if(aux == 40){

            system("cls");

            printf("VIDAS: %d|MOVIMENTOS: %d|COLETADAS: %d\n", vida, contador, aux);

            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    printf("[%c]", matriz[i][j]);
                }
                printf("\n");
            }

            printf("\n");
            printf("------------------------\n");
            printf("| VOCE E O BIXAO MESMO |\n");
            printf("------------------------\n");

        }else{

            printf("\n");

            if(vida < 0){
                printf("------------------\n");
                printf("| VIDA ACABARAM |\n");
                printf("------------------\n");
            }

            if(contador > 100){

                printf("---------------------\n");
                printf("| MUITOS MOVIMENTOS |\n");
                printf("---------------------\n");

            }

        }

        fim = false;
        while(true){

            printf("\nJOGAR NOVAMENTE (y/n): ");
            jogar = getch();

            if(jogar == 'y'){
                break;
            }else if(jogar == 'n'){
                fim = true;
                break;
            }

        }

        if(fim == true){
            printf("\n");
            break;
        }

    }

    return 0;
}
