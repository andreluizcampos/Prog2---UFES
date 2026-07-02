#include<stdlib.h>
#include"utils_char.h"
#include<stdio.h>
#include<string.h>

int main (){


    int tamanho = 0;
    scanf("%d\n",&tamanho);

    char *vetor;
    
    vetor = CriaVetor(tamanho);
    ImprimeString(vetor,tamanho);
    LeVetor(vetor,tamanho);
    ImprimeString(vetor, tamanho);
    LiberaVetor(vetor);

            return 0;


}