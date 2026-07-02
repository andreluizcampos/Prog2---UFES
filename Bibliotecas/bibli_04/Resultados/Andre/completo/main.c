#include <stdio.h>
#include "data.h"

int main()
{

    int d1 = 0, d2 = 0, m1 = 0, m2 = 0, a1 = 0, a2 = 0;

    scanf("%d/%d/%d\n", &d1, &m1, &a1);
  


    if(!verificaDataValida(d1,m1,a1)){

        printf("A data informada eh invalida");
        return 0;
    }


    printf("Data informada: ");
    imprimeDataExtenso(d1,m1,a1);

    if(verificaBissexto(a1)){

        printf("O ano informado eh bissexto\n");
    }
    else{

         printf("O ano informado nao eh bissexto\n");
    }

    printf("O mes informado possui %d dias\n", numeroDiasMes(m1,a1));

    printf("A data seguinte eh: ");
    imprimeProximaData(d1,m1,a1);

}