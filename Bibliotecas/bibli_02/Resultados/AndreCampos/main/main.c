#include <stdio.h>
#include "matrix_utils.h"

int main()
{

    int rows1, cols1, rows2, cols2, option = -1, choice = 0, scalar = 0;

    scanf("%d %d", &rows1, &cols1);
    int M1[rows1][cols1];
    matrix_read(rows1, cols1, M1);

    scanf("%d %d", &rows2, &cols2);
    int M2[rows2][cols2];
    matrix_read(rows2, cols2, M2);


    while (1)
    {

        if (option == 6)
        {

            break;
        }

        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n ");

        scanf("%d", &option);

        switch (option)
        {

        case 1:

            if (possible_matrix_sum(rows1, cols1, rows2, cols2))
            {

                int result[rows1][cols1];
                matrix_add(rows1, cols1, M1, rows2, cols2, M2, result);
                matrix_print(rows1, cols1, result);
                printf("\n");
            }

            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
               // printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }

            break;

        case 2:

            if (possible_matrix_sub(rows1, cols1, rows2, cols2))
            {

                int result[rows1][cols1];
                matrix_sub(rows1, cols1, M1, rows2, cols2, M2, result);
                matrix_print(rows1, cols1, result);
                  printf("\n");
            }
            else
            {
                 printf("Erro: as dimensoes da matriz nao correspondem\n");
                //printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }

            break;

        case 3:

            if (possible_matrix_multiply(cols1, rows2))
            {

                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, M1, rows2, cols2, M2, result);
                matrix_print(rows1, cols2, result);
                  printf("\n");
            }
            else
            {

 printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            

            }

            break;

        case 4:
            scanf("%d", &scalar);
            scanf("%d", &choice);

            if (choice == 1)
            {
                scalar_multiply(rows1, cols1, M1, scalar);
                matrix_print(rows1, cols1, M1);
                  printf("\n");
            }

            else
            {

                scalar_multiply(rows2, cols2, M2, scalar);
                matrix_print(rows2, cols2, M2);
                  printf("\n");
            }
            break;

        case 5:
      if(1)  {

            int r1[cols1][rows1];
            int r2[cols2][rows2];

            transpose_matrix(rows1, cols1, M1, r1);
            transpose_matrix(rows2, cols2, M2, r2);

            matrix_print(cols1, rows1, r1);
              printf("\n");
            matrix_print(cols2, rows2, r2);
              printf("\n");
        }
        break;

        case 6:

            break;
        }
    }
}