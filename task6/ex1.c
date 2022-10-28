#include <stdio.h>

int main(int argc, char *argv[]){

    int ce, cc;
    float i, pc, vi, vt, p, p_kg;

    printf("Digite o Codigo de Estado: ");
    scanf("%d", &ce);

    printf("Digite o Codigo da Carga: ");
    scanf("%d", &cc);

    printf("Digite o Peso: ");
    scanf("%f", &p);

    if(10 <= cc && cc <= 20){
        p_kg = 100.0;
    }else if(21 <= cc && cc <= 30){
        p_kg = 250.0;
    }else{
        p_kg = 340.0;
    }

    pc = p*p_kg;

    switch(ce){
        case 1:
            i = 0.35;
            break;
        case 2:
            i = 0.25;
            break;
        case 3:
            i = 0.15;
            break;
        case 4:
            i = 0.5;
            break;
        case 5:
            i = 0.0;
            break;
    }

    vi = i*pc;
    vt = pc + vi;

    printf("Valor Total: %.2f\n", vt);

    return 0;
}
