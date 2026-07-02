#include <stdio.h>
#include "data.h"

int main()
{

    int d1 = 0, d2 = 0, m1 = 0, m2 = 0, a1 = 0, a2 = 0;

    scanf("%d/%d/%d\n", &d1, &m1, &a1);
    scanf("%d/%d/%d\n", &d2, &m2, &a2);
    


    if (!(verificaDataValida(d1, m1, a1) && verificaDataValida(d2, m2, a2)))
    {

        printf("A primeira e/ou segunda data(s) invalida(s)");
    }

    else
    {

        printf("Primeira data: ");
        imprimeDataExtenso(d1, m1, a1);
        printf("Segunda data: ");
        imprimeDataExtenso(d2, m2, a2);

        if (comparaData(d1, m1, a1, d2, m2, a2) == -1)
        {

            printf("A primeira data eh mais antiga\n");
        }
        else if ((comparaData(d1, m1, a1, d2, m2, a2) == 1))
        {

            printf("A segunda data eh mais antiga\n");
        }

        if (!comparaData(d1, m1, a1, d2, m2, a2))
        {

            printf("As datas sao iguais\n");
        }
        printf("A diferenca em dias entre as datas eh: %.2d dias", calculaDiferencaDias(d1, m1, a1, d2, m2, a2));
    }
}