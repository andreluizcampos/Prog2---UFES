#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector
{
    DataType *elementos;
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
    v->elementos = (DataType *)malloc(sizeof(Vector));
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

    v->elementos[v->size] = val;
    v->size++;
    v->elementos = (DataType *)realloc(v->elementos, sizeof(DataType) * (v->size + 1));
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

    return v->elementos[i];
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

        destroy(v->elementos[i]);
    }
    free(v->elementos);

    free(v);
}

void VectorRemove(Vector *v, int i)
{


    for (int j = i+1; j < v->size; j++)
    {
        v->elementos[j-1] = v->elementos[j];
    }

    v->elementos = realloc(v->elementos, v->size * sizeof(DataType));
    v->size--;
}