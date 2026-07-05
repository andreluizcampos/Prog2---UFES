#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

struct Vector
{
    DataType *data;
    int n;
};

/**
 * @brief Cria um vetor vazio
 *
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
Vector *VectorConstruct()
{

    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->n = 0;
    v->data = (DataType *)malloc(sizeof(DataType));

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

    v->data[v->n] = val;
    v->n++;
    v->data = (DataType *)realloc(v->data, sizeof(DataType) * (v->n + 1));
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

    return v->n;
}

/**
 * @brief Libera a memória alocada para o vetor
 *
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
 */
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{

    for (int i = 0; i < v->n; i++)
    {

        destroy(v->data[i]);
    }

    free(v->data);
    free(v);
}
