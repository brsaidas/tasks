#include <stdio.h>
#define PI 3.14159265359

int main (int argc, char *argv[]){

    float raio, c, v, a;

    printf("Raio: ");
    scanf("%f", &raio);

    c = 2.0*PI*raio;
    a = PI*raio*raio;
    v = (4.0*PI*raio*raio*raio)/3.0;

    printf("Area = %f\n", a);
    printf("Volume = %f\n", v);
    printf("Comprimento = %f\n", c);

    return 0;
}
