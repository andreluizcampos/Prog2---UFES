#include <stdio.h>
#include "data.h"

int main()
{

    int d1 = 0, m1 = 0, a1, d2, m2, a2;
    tData data1, data2;

    scanf("%d/%d/%d %d/%d/%d", &d1, &m1, &a1, &d2, &m2, &a2);

    data1 = CriaData(d1, m1, a1);
    data2 = CriaData(d2, m2, a2);

    if(!VerificaDataValida(data1) || !VerificaDataValida(data2)){

        printf("A primeira e/ou segunda data(s) invalida(s)\n");

            return 0;
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);
    printf("Segunda data: ");
    ImprimeDataExtenso(data2);
 



    if (ComparaData(data1, data2) == -1)
    {

        printf("A primeira data eh mais antiga\n");
    }

    if (ComparaData(data1, data2) == 1)
    {

        printf("A segunda data eh mais antiga\n");
    }
    if (ComparaData(data1, data2) == 0)
    {

        printf("As datas sao iguais\n");
    }

    printf("A diferenca em dias entre as datas eh: %.2d dias\n", CalculaDiferencaDias(data1,data2));
}