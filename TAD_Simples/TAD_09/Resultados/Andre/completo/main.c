#include <stdio.h>
#include "funcionario.h"
#include "empresa.h"

int main()
{

    int qtd_empresas = 0;

    scanf("%d", &qtd_empresas);

    tEmpresa empresas[qtd_empresas];

    for (int i = 0; i <qtd_empresas; i++)
    {

        empresas[i] = leEmpresa();
    }

    for (int i = 0; i < qtd_empresas; i++)
    {
        imprimeEmpresa(empresas[i]);
        printf("\n");
    }
    return 0;
}
