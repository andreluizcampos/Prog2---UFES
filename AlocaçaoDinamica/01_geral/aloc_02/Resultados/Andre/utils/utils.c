#include <stdio.h>
#include "utils.h"
#include <string.h>
#include <stdlib.h>

int **CriaMatriz(int linhas, int colunas)
{

        int **v = malloc(sizeof(int *) * linhas);

        for (int i = 0; i < linhas; i++)
        {

                v[i] = malloc(sizeof(int) * colunas);
        }

        return v;
}
void LiberaMatriz(int **matriz, int linhas)
{

        for (int i = 0; i < linhas; i++)
        {

                free(matriz[i]);

    
        }

          free(matriz);
        
      
}

void LeMatriz(int **matriz, int linhas, int colunas)
{

        for (int i = 0; i < linhas; i++)
        {

                for (int j = 0; j < colunas; j++)
                {

                        scanf("%d", &matriz[i][j]);
                }
        }
}
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas)
{

        for (int i = 0; i < colunas; i++)
        {

                for (int j = 0; j < linhas; j++)
                {

                        printf("%d ", matriz[j][i]);
                }

                printf("\n");
        }

}
