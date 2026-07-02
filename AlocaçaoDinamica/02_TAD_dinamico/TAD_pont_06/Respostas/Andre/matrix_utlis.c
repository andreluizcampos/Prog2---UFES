#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_utils.h"

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado. Alocar dinamicamente o espaço na memória para a matriz bidimensional
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix *MatrixCreate(int rows, int cols)
{

    tMatrix *matrix = malloc(sizeof(tMatrix));

    matrix->cols = cols;
    matrix->rows = rows;

    matrix->data = malloc(sizeof(int *) * rows);

    for (int i = 0; i < rows; i++)
    {

        matrix->data[i] = malloc(sizeof(int) * cols);
    }

    return matrix;
}

/**
 * @brief Libera toda a memória alocada por uma matriz
 * @param matrix O ponteiro para a estrutura que armazena uma matriz.
 */
void MatrixFree(tMatrix *matrix)
{

    for (int i = 0; i < matrix->rows; i++)
    {

        free(matrix->data[i]);
    }

    free(matrix->data);
    free(matrix);
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 */
void MatrixRead(tMatrix *matrix)
{

    for (int i = 0; i < matrix->rows; i++)
    {

        for (int j = 0; j < matrix->cols; j++)
        {

            scanf("%d", &matrix->data[i][j]);
        }

        scanf("\n");
    }
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix *matrix)
{

    for (int i = 0; i < matrix->rows; i++)
    {

        for (int j = 0; j < matrix->cols; j++)
        {

            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix *matrix1, tMatrix *matrix2)
{

    return matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix *matrix1, tMatrix *matrix2)
{

    return matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix *matrix1, tMatrix *matrix2)
{

    return matrix1->cols == matrix2->rows;
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix *MatrixAdd(tMatrix *matrix1, tMatrix *matrix2)
{

    for (int i = 0; i < matrix1->rows; i++)
    {

        for (int j = 0; j < matrix2->cols; j++)
        {

            matrix1->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }

    return matrix1;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix *MatrixSub(tMatrix *matrix1, tMatrix *matrix2)
{

    for (int i = 0; i < matrix1->rows; i++)
    {

        for (int j = 0; j < matrix2->cols; j++)
        {

            matrix1->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }

    return matrix1;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix *MatrixMultiply(tMatrix *matrix1, tMatrix *matrix2)
{
    tMatrix *result = MatrixCreate(matrix1->rows, matrix2->cols);

    for (int i = 0; i < matrix1->rows; i++)
    {
        for (int j = 0; j < matrix2->cols; j++)
        {
            result->data[i][j] = 0;

            for (int l = 0; l < matrix2->rows; l++)
            {
                result->data[i][j] += matrix1->data[i][l] * matrix2->data[l][j];
            }
        }
    }

    return result;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix *TransposeMatrix(tMatrix *matrix)
{

    tMatrix *m2 = MatrixCreate(matrix->cols, matrix->rows);

    for (int i = 0; i < m2->rows; i++)
    {

        for (int j = 0; j < m2->cols; j++)
        {

            m2->data[i][j] = matrix->data[j][i];
        }
    }

    return m2; // Possivel problema com free aqui
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix *MatrixMultiplyByScalar(tMatrix *matrix, int scalar)
{

    for (int i = 0; i < matrix->rows; i++)
    {

        for (int j = 0; j < matrix->cols; j++)
        {

            matrix->data[i][j] = matrix->data[i][j] * scalar;
        }
    }

    return matrix;
}