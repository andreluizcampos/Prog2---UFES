#include<stdio.h>
#include<string.h>
#include"vetor.h"


int soma( int n1, int n2){

    return n1+n2;

}

int multiplicacao( int n1, int n2){

    return n1*n2;
}

int main(){


    Vetor vetor;

    LeVetor(&vetor);

    int sum = 0, mult = 0;
    
    sum = AplicarOperacaoVetor(&vetor, soma);
    mult = AplicarOperacaoVetor(&vetor, multiplicacao);

    printf("Soma: %d\n Produto: %d", sum,mult);

}