#include <stdio.h>
#include "matrix_utils.h"

tMatrix MatrixCreate(int rows, int cols)
{

    tMatrix matrix;

    matrix.cols = cols;
    matrix.rows = rows;
    return matrix; // Ok
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 * @return A matriz lida.
 */
tMatrix MatrixRead(tMatrix matrix)
{

    for (int i = 0; i < matrix.rows; i++)
    {

        for (int j = 0; j < matrix.cols; j++)
        {

            scanf("%d", &matrix.data[i][j]); // ok
        }
    }

    return matrix;
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix matrix)

{

    for (int i = 0; i < matrix.rows; i++)
    {

        printf("|");

        for (int j = 0; j < matrix.cols; j++)
        {

            if (j != matrix.cols - 1)
            {
                printf("%d ", matrix.data[i][j]);
            }
            else
            {

                printf("%d|", matrix.data[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2)
{

    return (matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows);
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2)
{

    return (matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows);
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2)
{

    return (matrix1.rows == matrix2.cols);
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2)
{

    tMatrix matrix3;

    matrix3.cols = matrix1.cols, matrix3.rows = matrix1.rows;

    for (int i = 0; i < matrix1.rows; i++)
    {

        for (int j = 0; j < matrix1.cols; j++)
        {

            matrix3.data[i][j] = 0;
        }
    }

    for (int i = 0; i < matrix1.rows; i++)
    {

        for (int j = 0; j < matrix1.cols; j++)
        {

            matrix3.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }

    return matrix3;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2)
{

    tMatrix matrix3;

    matrix3.cols = matrix1.cols, matrix3.rows = matrix1.rows;

    for (int i = 0; i < matrix1.rows; i++)
    {

        for (int j = 0; j < matrix1.cols; j++)
        {

            matrix3.data[i][j] = 0;
        }
    }

    for (int i = 0; i < matrix1.rows; i++)
    {

        for (int j = 0; j < matrix1.cols; j++)
        {

            matrix3.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }

    return matrix3;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2)
{

    tMatrix matrix3;

    matrix3.cols = matrix2.cols;
    matrix3.rows = matrix1.rows;

    for (int i = 0; i < matrix1.rows; i++)
    {

        for (int j = 0; j < matrix2.cols; j++)
        {

            matrix3.data[i][j] = 0;
        }
    }


    for (int i = 0; i < matrix1.rows; i++)
    {

        for (int j = 0; j < matrix2.cols; j++)
        {

            for (int k = 0; k < matrix1.cols; k++)
            {

                matrix3.data[i][j] += matrix2.data[k][j] * matrix1.data[i][k];
            }
        }
    }

    return matrix3;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix TransposeMatrix(tMatrix matrix)
{

    tMatrix matrix2;

    matrix2.rows = matrix.cols;
    matrix2.cols = matrix.rows;

    for (int i = 0; i < matrix.rows; i++)
    {

        for (int j = 0; j < matrix.cols; j++)
        {

            matrix2.data[j][i] = matrix.data[i][j];
        }
    }

    return matrix2;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar)
{

    for (int i = 0; i < matrix.rows; i++)
    {

        for (int j = 0; j < matrix.cols; j++)
        {

            matrix.data[i][j] = matrix.data[i][j] * scalar;
        }
    }

    return matrix;
}
