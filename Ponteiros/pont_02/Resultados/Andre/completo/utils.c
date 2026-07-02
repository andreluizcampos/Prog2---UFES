#include <stdio.h>
#include <string.h>
#include "utils.h"
#include <limits.h>

void LeIntervalo(int *m, int *n)
{

    int n1 = 0, n2 = 0;

    scanf("%d %d", &n1, &n2);

    *m = n1, *n = n2;
}

/**
 * @brief Verifica se um número é primo.
 *
 * Esta função recebe como parâmetro um número inteiro e verifica se ele é primo.
 *
 * @param n Número a ser verificado.
 * @return 1 se o número é primo, 0 caso contrário.
 */
int EhPrimo(int n)
{

    if (n <= 1)
    {

        return 0;
    }

    for (int i = 2; i < n; i++)
    {

        if (n % i == 0)
        {

            return 0;
        }
    }

    return 1;
}

/**
 * @brief Obtém o maior e o menor número primo em um intervalo.
 *
 * Esta função recebe como parâmetro dois números inteiros que representam o início e o fim de um intervalo, e dois ponteiros para inteiros que receberão os valores do maior e do menor número primo encontrado no intervalo.
 *
 * @param m Início do intervalo.
 * @param n Fim do intervalo.
 * @param menor Ponteiro para a variável que receberá o menor número primo encontrado.
 * @param maior Ponteiro para a variável que receberá o maior número primo encontrado.
 */
void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior)
{

    int Menor = INT_MAX, Maior = INT_MIN;

    for (int i = m; i <= n; i++)
    {

        if (EhPrimo(i))
        {
            if (i < Menor)
            {

                Menor = i;
            }

            if (i > Maior)
            {

                Maior = i;
            }
        }
    }

    *maior = Maior;
    *menor = Menor;
}