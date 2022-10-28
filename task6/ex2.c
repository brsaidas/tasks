#include <stdio.h>

int main(){

    float a, b;

    printf("Digite numero a: ");
    scanf("%f", &a);

    printf("Digite numero b: ");
    scanf("%f", &b);

    if(a > 0.0 && b > 0.0){

        int op;

        printf("Digite a Opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("R: %f\n", pow(a, b));
                break;
            case 2:
                printf("R: %f, %f\n", sqrt(a), sqrt(b));
                break;
            case 3:
                printf("R %f, %f\n", cbrt(a), cbrt(b));
                break;
            default:
                printf("Erro: Opcao Invalida\n");
                break;
        }

    }else{
        printf("Erro: Entrada Invalida\n");
    }

    return 0;
}
