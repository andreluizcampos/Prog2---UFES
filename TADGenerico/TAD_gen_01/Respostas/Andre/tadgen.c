#include <stdio.h>
#include "tadgen.h"
#include <stdlib.h>

struct generic
{

    void *array;
    int qtd;
    int type;
};

tGeneric *CriaGenerico(Type type, int numElem)
{

    tGeneric *g = (tGeneric *)malloc(sizeof(tGeneric));

    g->type = type;

    if (type == FLOAT)
    {

        g->array = (float *)malloc(sizeof(float) * numElem);
    }
    else
    {

        g->array = (int *)malloc(sizeof(int) * numElem);
    }

    g->qtd = numElem;

    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen)
{

    free(gen->array);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen)
{

    switch (gen->type)
    {

    case FLOAT:

        printf("\nDigite o vetor:\n");

        for (int i = 0; i < gen->qtd; i++)
        {

            scanf("%f\n", &((float *)(gen->array))[i]);
        }

        break;

    case INT:

        printf("\nDigite o vetor:\n");

        for (int i = 0; i < gen->qtd; i++)
        {

            scanf("%d\n", &((int *)(gen->array))[i]);
        }

        break;

    default:

        break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric *gen)
{

    switch (gen->type)
    {

    case FLOAT:

        for (int i = 0; i < gen->qtd; i++)
        {

            printf("%.2f ", ((float *)(gen->array))[i]);
        }
        printf("\n");
        break;

    case INT:

        for (int i = 0; i < gen->qtd; i++)
        {

            printf("%d ", ((int *)(gen->array))[i]);
        }
        printf("\n");

        break;

    default:

        break;
    }
}
