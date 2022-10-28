#include <stdio.h>

int main(int argc, char argv[]){

    float A1, A2;
    float B1, B2;
    float C1, C2;
    float D1, D2;
    float E1, E2;
    float F1, F2;
    float MA, MB, MC, MD, ME, MF;

    int num_rep = 0, num_exa = 0, num_apr = 0;

    printf("Digite a primeira nota do aluno A: ");
    scanf("%f", &A1);

    printf("Digite a segunda nota do aluno A: ");
    scanf("%f", &A2);

    printf("Digite a primeira nota do aluno B: ");
    scanf("%f", &B1);

    printf("Digite a segunda nota do aluno B: ");
    scanf("%f", &B2);

    printf("Digite a primeira nota do aluno C: ");
    scanf("%f", &C1);

    printf("Digite a segunda nota do aluno C: ");
    scanf("%f", &C2);

    printf("Digite a primeira nota do aluno D: ");
    scanf("%f", &D1);

    printf("Digite a segunda nota do aluno D: ");
    scanf("%f", &D2);

    printf("Digite a primeira nota do aluno E: ");
    scanf("%f", &E1);

    printf("Digite a segunda nota do aluno E: ");
    scanf("%f", &E2);

    printf("Digite a primeira nota do aluno F: ");
    scanf("%f", &F1);

    printf("Digite a segunda nota do aluno F: ");
    scanf("%f", &F2);

    MA = (A1+A2)/2.0;
    printf("Media do aluno A: %.2f\n", MA);

    MB = (B1+B2)/2.0;
    printf("Media do aluno B: %.2f\n", MB);

    MC = (C1+C2)/2.0;
    printf("Media do aluno C: %.2f\n", MC);

    MD = (D1+D2)/2.0;
    printf("Media do aluno D: %.2f\n", MD);

    ME = (E1+E2)/2.0;
    printf("Media do aluno E: %.2f\n", ME);

    MF = (F1+F2)/2.0;
    printf("Media do aluno F: %.2f\n", MF);

    if(MA < 3){
        num_rep++;
    }else if(3 <= MA && MA <= 7){
        num_exa++;
    }else{
        num_apr++;
    }

    if(MB < 3){
        num_rep++;
    }else if(3 <= MB && MB <= 7){
        num_exa++;
    }else{
        num_apr++;
    }

    if(MC < 3){
        num_rep++;
    }else if(3 <= MC && MC <= 7){
        num_exa++;
    }else{
        num_apr++;
    }

    if(MD < 3){
        num_rep++;
    }else if(3 <= MD && MD <= 7){
        num_exa++;
    }else{
        num_apr++;
    }

    if(ME < 3){
        num_rep++;
    }else if(3 <= ME && ME <= 7){
        num_exa++;
    }else{
        num_apr++;
    }

    if(MF < 3){
        num_rep++;
    }else if(3 <= MF && MF <= 7){
        num_exa++;
    }else{
        num_apr++;
    }

    printf("Aprovados: %d\n", num_apr);
    printf("Exames: %d\n", num_exa);
    printf("Reprovados: %d\n", num_rep);

    return 0;
}
