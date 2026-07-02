#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "missil.h"

struct missil
{
    float x;
    float y;
    float p;
    char *nome;
};

/**
 * @brief Lê a entrada do usuário e cria um novo míssil.
 *
 * @return tMissil Ponteiro para o míssil criado.
 */
tMissil LeMissil()
{

    tMissil mi = malloc(sizeof(struct missil));

    mi->nome = malloc(MAX_TAM + 1 * sizeof(char));

    mi->x = 0;
    mi->y = 0;
    mi->p = 0;

    scanf("%[^ ] %f %f %f", mi->nome, &mi->x, &mi->y, &mi->p);

    return mi;
}

/**
 * @brief Imprime as informações do míssil.
 *
 * @param missil Ponteiro para o míssil que será impresso.
 */
void ImprimeMissil(tMissil missil)
{

    printf("M-%s: %.2f\n", missil->nome, missil->p);
}

/**
 * @brief Libera a memória alocada para o míssil.
 *
 * @param missil Ponteiro para o míssil que terá a memória liberada.
 */
void LiberaMissil(tMissil missil)
{

    free(missil->nome);
    free(missil);
}

/**
 * @brief Obtém a coordenada y do míssil.
 *
 * @param missil Ponteiro para o míssil que terá a coordenada y obtida.
 * @return float Coordenada y do míssil.
 */
float GetMissilY(tMissil missil)
{

    return missil->y;
}

/**
 * @brief Obtém a coordenada x do míssil.
 *
 * @param missil Ponteiro para o míssil que terá a coordenada x obtida.
 * @return float Coordenada x do míssil.
 */
float GetMissilX(tMissil missil)
{

    return missil->x;
}

/**
 * @brief Obtém o poder de ataque do míssil.
 *
 * @param missil Ponteiro para o míssil que terá o poder de ataque obtido.
 * @return float Poder de ataque do míssil.
 */
float GetMissilPoder(tMissil missil)
{

    return missil->p;
}

/**
 * @brief Reduz o poder de ataque do míssil.
 *
 * @param missil Ponteiro para o míssil que terá o poder de ataque reduzido.
 * @param valor Valor a ser subtraído do poder de ataque do míssil.
 */
void ReduzPoder(tMissil missil, float valor)
{

    missil->p -= valor;
    
    if (missil->p < 0)
    {

        missil->p = 0;
    }
}
