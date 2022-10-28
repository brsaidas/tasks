#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

    srand(time(NULL));

    char computador, usuario, resposta;
    int valor_usuario, valor_computador;

    usuario = ' ';

    while(1){

        printf("(r)ocha-(p)apel-(t)esoura-(l)agarto-(s)pock-(e)xit\n");
        printf("Digite a letra da opcao do usuario:\n");

        usuario = getch();
        valor_computador = rand() % 5;

        if(usuario == 'e'){
            break;
        }

        switch(usuario){
            case 's':
                valor_usuario = 0;
                break;
            case 't':
                valor_usuario = 1;
                break;
            case 'p':
                valor_usuario = 2;
                break;
            case 'r':
                valor_usuario = 3;
                break;
            case 'l':
                valor_usuario = 4;
                break;
        }

        switch(valor_computador){
            case 0:
                computador = 's';
                break;
            case 1:
                computador = 't';
                break;
            case 2:
                computador = 'p';
                break;
            case 3:
                computador = 'r';
                break;
            case 4:
                computador = 'l';
                break;
        }

        printf("Usuario = %c | Computador = %c\n", usuario, computador);

        if(valor_usuario == valor_computador){
            resposta = 'e';
        }else if(((valor_usuario + 1)%5 == valor_computador) || ((valor_usuario + 3)%5 == valor_computador)){
            resposta = 'u';
        }else{
            resposta = 'c';
        }

        if(resposta == 'e'){
            printf("R: EMPATE\n\n");
        }else if(resposta == 'u'){
            printf("R: USUARIO\n\n");
        }else{
            printf("R: COMPUTADOR\n\n");
        }

    }

    return 0;
}
