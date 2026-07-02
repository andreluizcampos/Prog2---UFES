#include <stdio.h>
#include "matrix_utils.h"

int main()
{
    tMatrix M1, M2;
    int op_code = -1;
    int c1, r1, c2, r2, scalar, option;

    scanf("%d %d ", &r1, &c1);
    M1 = MatrixCreate(r1, c1);
    M1 = MatrixRead(M1);

    scanf("%d %d", &r2, &c2);
    M2 = MatrixCreate(r2, c2);
    M2 = MatrixRead(M2);

    while (1)
    {

        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");

        scanf("%d", &op_code);

        if (op_code == 6)
        {

            break;
        }

        switch (op_code)
        {

        case 1:

            if (PossibleMatrixSum(M1, M2))
            {
                MatrixPrint(MatrixAdd(M1, M2));
            }
            else
            {

                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }

            break;

        case 2:

            if (PossibleMatrixSub(M1, M2))
            {
                MatrixPrint(MatrixSub(M1, M2));
            }
            else
            {

                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
            break;

        case 3:

            if (PossibleMatrixMultiply(M1, M2))
            {
                MatrixPrint(MatrixMultiply(M1, M2));

            }
            else{

                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
            
            break;

        case 4:

            int scalar = 0;

            scanf("%d %d", &scalar, &option);

            if (option == 1)
            {
                MatrixPrint(MatrixMultiplyByScalar(M1, scalar));

                M1 = MatrixMultiplyByScalar(M1, scalar);
            }

            else
            {

                MatrixPrint(MatrixMultiplyByScalar(M2, scalar));
                M2 = MatrixMultiplyByScalar(M2, scalar);
            }

            break;

        case 5:

            MatrixPrint(TransposeMatrix(M1));
            MatrixPrint(TransposeMatrix(M2));

            break;

        case 6:

            break;
        }
    }
}