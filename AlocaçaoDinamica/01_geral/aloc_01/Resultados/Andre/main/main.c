#include<stdlib.h>
#include<stdio.h>
#include"utils.h"


int main (){


    int  tamanho;
    scanf("%d",&tamanho);
    int *vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);

        printf("%.2f",CalculaMedia(vetor, tamanho));
        LiberaVetor(vetor);
            return 0;

}