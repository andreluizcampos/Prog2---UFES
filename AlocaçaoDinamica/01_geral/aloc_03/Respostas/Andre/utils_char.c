#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

char *CriaVetor(int tamanho)
{

    char *vetor;

    vetor = malloc(sizeof(char) * tamanho);

    for (int i = 0; i < tamanho; i++)
    {

        vetor[i] = '_';
    }

        return vetor;
}

/**
 * Lê uma string do tamanho especificado.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 */
void LeVetor(char *vetor, int tamanho)
{

    char copy;
    int i = 0;

    while ((scanf("%c", &copy)) == 1)
    {   
        if( copy=='\n'){

            break;
        }

        tamanho--;
        vetor[i] = copy;
        i++;

        if (tamanho == 0)
        {

            break;
        }
        
    }

}

/**
 * Imprime a string
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
 */
void ImprimeString(char *vetor, int tamanho)
{

        for( int i  = 0;i<tamanho;i++){

            printf("%c",vetor[i]);
        }
        printf("\n");
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 *
 * @param vetor Ponteiro para o vetor a ser liberado.
 */
void LiberaVetor(char *vetor){

    free(vetor);
}