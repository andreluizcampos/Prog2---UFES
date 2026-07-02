#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main()
{

    int qtd = 0;
    scanf("%d\n", &qtd);

    tEmpresa **empresa = malloc(sizeof(tEmpresa) * qtd);

    for (int i = 0; i < qtd; i++)
    {

        empresa[i] = CriaEmpresa();
        LeEmpresa(empresa[i]);
    }

    for (int i = 0; i < qtd; i++)
    {

        ImprimeEmpresa(empresa[i]);
        ApagaEmpresa(empresa[i]);
    }

    free(empresa);
}