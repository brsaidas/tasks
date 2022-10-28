#include <stdio.h>

int main (int argc, char *argv[]){

    int x, y, z;

    float mg, mp, mh, ma;

    printf("X: ");
    scanf("%d", &x);

    printf("Y: ");
    scanf("%d", &y);

    printf("Z: ");
    scanf("%d", &z);

    mg = (float) pow(x*y*z, 1.0/3.0);
    mp = (float) (x + 2*y + 3*z)/6;
    mh = (float) 1/((1/x)+(1/y)+(1/z));
    ma = (float) (x+y+z)/3;

    printf("MG = %f\nMP = %f\nMH = %f\nMA = %f\n", mg, mp, mh, ma);

    return 0;
}
