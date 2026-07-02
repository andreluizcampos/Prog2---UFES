#include <stdio.h>
#include "utils.h"
#include <limits.h>
/**
 * @brief Lê uma sequência de inteiros da entrada padrão e os armazena em um array.
 * @param array Ponteiro para o array onde os inteiros serão armazenados.
 * @param tamanho O tamanho do array.
 */
void LeNumeros(int *array, int tamanho)
{

    int num = 0;
    for (int i = 0; i < tamanho; i++)
    {

        scanf("%d", &num);
        array[i] = num;
    }
}

/**
 * @brief Encontra o maior, o menor e a média dos valores em um array de inteiros.
 * @param array Ponteiro para o array de inteiros.
 * @param tamanho O tamanho do array.
 * @param maior Ponteiro para a variável que armazenará o maior valor.
 * @param menor Ponteiro para a variável que armazenará o menor valor.
 * @param media Ponteiro para a variável que armazenará a média dos valores.
 */
void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media)
{

    *maior = INT_MIN;
    *menor = INT_MAX;
    *media = 0;

    for (int i = 0; i < tamanho; i++)
    {

        if (array[i] > *maior)
        {

            *maior = array[i];
        }

        if (array[i] < *menor)
        {

            *menor = array[i];
        }

        *media += array[i];
    }

    *media = *media / (float)tamanho;
}