#include <stdio.h>

int main (int argc, char *argv[]){

    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("Quadrado = %f\n", pow(n, 2.0));
    printf("Cubo = %f\n", pow(n, 3.0));
    printf("Raiz Quadrada = %f\n", sqrt(n));
    printf("Raiz Cubica = %f\n", cbrt(n));

    return 0;
}
