#include <stdio.h>

int main(int argc, char argv[]){

    float joao, jose;

    printf("Digite o salario de Joao: ");
    scanf("%f", &joao);

    jose = (1.0/3.0)*joao;

    int cont = 0;
    while(jose < joao){
        joao = joao + joao*0.02;
        jose = jose + jose*0.05;
        cont++;
    }

    printf("Em %d meses", cont);

    return 0;
}
