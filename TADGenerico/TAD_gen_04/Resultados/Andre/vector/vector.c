#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

struct Vector
{
    DataType *d;
    int size;
};

/**
 * @brief Cria um vetor vazio
 *
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
Vector *VectorConstruct()
{

    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->d = malloc(sizeof(DataType));
    v->size = 0;

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

    if (v != NULL)
    {
        v->d = (DataType *)realloc(v->d, sizeof(DataType) * (v->size + 1));
        v->d[v->size] = val;
        v->size++;
    }
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

    return v->d[i];
}

/**
 * @brief Retorna o tamanho do vetor
 *
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
 */
int VectorSize(Vector *v)
{

    return v->size;
}

/**
 * @brief Libera a memória alocada para o vetor
 *
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
 */
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{

    for (int i = 0; i < v->size; i++)
    {
        destroy(v->d[i]);
    }
    free(v->d);
    free(v);
}