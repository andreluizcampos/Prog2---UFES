#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector
{

    DataType *data;
    int qtd;
    int qtd_insert;
};

/**
 * @brief Cria um vetor vazio
 *
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
Vector *VectorConstruct()
{

    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->qtd = 0;
    v->data = (DataType *)malloc(sizeof(DataType));
    v->qtd_insert = 0;
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 *
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
 */
void VectorPushBack(Vector *v, DataType val)
{

    v->data[v->qtd_insert] = val;
    v->qtd_insert++;

    if (v->qtd == 0)
    {

        v->qtd = 4;
    }

    else
    {

        v->qtd = v->qtd * 2;
    }

    v->data = realloc(v->data, sizeof(DataType) * v->qtd);
}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja,
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 *
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
 */
DataType VectorPopFront(Vector *v)
{

    DataType *e = v->data[0];

    for (int i = 1; i < v->qtd_insert; i++)
    {

        v->data[i - 1] = v->data[i];
    }

    v->data = realloc(v->data, sizeof(DataType) * (v->qtd - 1));

    v->qtd_insert--;

    return e;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 *
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
 */
DataType VectorGet(Vector *v, int i)
{

    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 *
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
 */
int VectorSize(Vector *v)
{

    return v->qtd;
}

/**
 * @brief Libera a memória alocada para o vetor
 *
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
 */
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{

    for (int i = 0; i < v->qtd_insert; i++)
    {

        destroy(v->data[i]);
    }

    free(v->data);
    
    free(v);
}