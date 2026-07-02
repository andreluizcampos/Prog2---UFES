#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "vector.h"
#include "movel.h"

int main()
{
    Fila *f = FilaConstruct();
    char ENTRADA[30];
    char PRODUZIR[30];
    int qtd = 0;
    char option[30];

    scanf("%d\n", &qtd);
    strcpy(ENTRADA, "ENTRADA");
    strcpy(PRODUZIR, "PRODUZIR");

    for (int i = 0; i < qtd; i++)
    {

        scanf("%s\n", option);

        if (strcmp(option, ENTRADA) == 0)
        {
            tMovel *m = LeMovel();
            FilaPush(f, m);
        }

        else if (strcmp(option,PRODUZIR) == 0)
        {
            tMovel *m = (tMovel *)FilaPop(f);
            ImprimeMovel(m);
            DestroiMovel(m);
        }
    }

    FilaDestroy(f, DestroiMovel);

}