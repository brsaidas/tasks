#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_LIN 25
#define MAX_COL 25

typedef enum{false, true} bool;

int main(int argc, char *argv[]){
    srand(time(NULL));

    bool sair = false;
    int lin = MAX_LIN/2, col = MAX_COL/2;
    char tab[MAX_LIN][MAX_COL], mov = ' ';
    clock_t temp = 0, _temp = 0;

    for(int i = 0; i < MAX_LIN; i++){
        for(int j = 0; j < MAX_COL; j++){
            tab[i][j] = ' ';
        }
    }

    tab[lin][col] = 'o';

    while(sair == false){
        if(kbhit()){
            mov = getch();
            switch(mov){
                case 'w':
                    tab[lin][col] = ' ';
                    tab[lin-1][col] = 'o';

                    lin--;
                    break;
                case 's':
                    tab[lin][col] = ' ';
                    tab[lin+1][col] = 'o';

                    lin++;
                    break;
                case 'd':
                    tab[lin][col] = ' ';
                    tab[lin][col+1] = 'o';

                    col++;
                    break;
                case 'a':
                    tab[lin][col] = ' ';
                    tab[lin][col-1] = 'o';

                    col--;
                    break;
                case 'j':
                    tab[lin-1][col] = ':';
                    break;
                default:
                    break;
            }
            mov = ' ';
        }

        temp = clock();
        if(temp - _temp >= CLOCKS_PER_SEC/10){

            for(int i = MAX_LIN-1; i >= 0; i--){
                for(int j = MAX_COL-1; j >= 0; j--){
                    if(tab[i][j] == '*' && i == MAX_LIN-1){
                        tab[i][j] = ' ';
                    }else if(tab[i][j] == '*' && tab[i+1][j] == ' '){
                        tab[i][j] = ' ';
                        tab[i+1][j] = '*';
                    }else if(tab[i][j] == '*' && tab[i+1][j] == 'o'){
                        sair = true;
                        tab[i][j] = ' ';
                        tab[i+1][j] = '+';
                    }else if(tab[i][j] == '*' && tab[i+1][j] == ':'){
                        tab[i][j] = ' ';
                        tab[i+1][j] = ' ';
                    }
                }
            }

            for(int i = 0; i < MAX_LIN; i++){
                for(int j = 0; j < MAX_COL; j++){
                    if(tab[i][j] == ':' && i == 0){
                        tab[i][j] = ' ';
                    }else if(tab[i][j] == ':' && tab[i-1][j] == ' '){
                        tab[i][j] = ' ';
                        tab[i-1][j] = ':';
                    }
                }
            }

            tab[0][(rand() % MAX_COL)] = '*';

            system("cls");
            printf("TEMPO = %d\n", temp);

            for(int i = 0; i < MAX_LIN; i++){
                for(int j = 0; j < MAX_COL; j++){
                    printf("[%c]", tab[i][j]);
                }
                printf("\n");
            }

            _temp = temp;
        }
    }

    system("pause");

    return 0;
}
