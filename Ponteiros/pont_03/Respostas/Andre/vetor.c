#include <stdio.h>
#include "vetor.h"
#include <limits.h>

void LeDadosParaVetor(int *vet, int tam)
{

    int j = 0;

    for (int i = 0; i < tam; i++)
    {

        scanf("%d", &j);
        vet[i] = j;
    }
}

/**
 * @brief Imprime os dados de um vetor na tela.
 *
 * Esta função recebe como parâmetro um vetor e seu tamanho, e imprime na tela os valores armazenados no vetor.
 *
 * @param n Ponteiro para o vetor a ser impresso.
 * @param tam Tamanho do vetor.
 */
void ImprimeDadosDoVetor(int *n, int tam)
{

    for (int i = 0; i < tam; i++)
    {

        printf("%d ", n[i]);
    }
    printf("\n");
}

/**
 * @brief Troca o valor de duas variáveis se o segundo for menor que o primeiro.
 *
 *
 * Obs.: Essa função tem o comportamento de encontrar o menor valor no vetor vet de tamanho tam,
 *  se esse valor for menor do que o valor apontado por paraTrocar, realiza uma troca.
 *  Ao final da execução, a variável apontada por paraTrocar terá o menor valor encontrado no vetor vet.
 *
 * @param vet Ponteiro para o vetor a ser percorrido.
 * @param tam Tamanho do vetor.
 * @param paraTrocar Ponteiro para a variável que armazenará o índice do menor valor encontrado.
 */
void TrocaSeAcharMenor(int *vet, int tam, int *paraTrocar)
{

    *paraTrocar = INT_MAX;

    for (int i = 0; i < tam; i++)
    {

        if (vet[i] < paraTrocar)
        {

            *paraTrocar = vet[i];
        }
    }
}

/**
 * @brief Ordena um vetor em ordem crescente.
 *
 * Esta função recebe como parâmetro um vetor e seu tamanho, e ordena os valores do vetor em ordem crescente.
 *
 * @param vet Ponteiro para o vetor a ser ordenado.
 * @param tam Tamanho do vetor.
 */
void OrdeneCrescente(int *vet, int tam)
{

    int flag = 1;

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < tam - 1; i++)
        {

            if (vet[i] > vet[i + 1])
            {

                int temp = vet[i + 1];
                vet[i + 1] = vet[i];
                vet[i] = temp;
                flag = 1;
            }
        }
    }
}