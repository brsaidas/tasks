#include <stdio.h>

int main (int argc, char *argv[]){

    int n;

    printf("N: ");
    scanf("%d", &n);

    printf("Sucessor = %d\nAntecessor = %d\n", n+1, n-1);

    return 0;
}
