#include <stdio.h>
#define PI 3.14159265359

int main (int argc, char *argv[]){

    float volume, altura, raio;

    printf("Altura: ");
    scanf("%f", &altura);

    printf("Raio: ");
    scanf("%f", &raio);

    volume = PI * raio * raio * altura;

    printf("Volume = %f", volume);

    return 0;
}

