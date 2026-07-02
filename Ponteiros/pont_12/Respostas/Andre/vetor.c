#include <stdio.h>
#include "vetor.h"

void LeVetor(Vetor *vetor)
{
    int size=0;

    scanf("%d", &vetor->tamanhoUtilizado);

    for (int i = 0; i < vetor->tamanhoUtilizado; i++)
    {
        scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op)
{

    int soma= vetor->elementos[0];

    for (int i = 1; i < vetor->tamanhoUtilizado; i++)
    {

        soma  = op(soma, vetor->elementos[i]);

    }

    return soma;
}