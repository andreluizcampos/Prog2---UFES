
#include "vendedor.h"
#include <string.h>
#include "loja.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int qtd_loja = 0, j = 0, salario, id, i = 0, option = -1, flag = 0;

    char name[50];
    float percentage, aluguel;
    scanf("%d", &qtd_loja);
    tLoja lojas[qtd_loja];
    tVendedor vendedor;


    while (1)
    {

        if (option == 0)
        {

            break;
        }

        scanf("%d", &option);

        switch (option)
        {

        case 1:

            scanf("%d %f", &id, &aluguel);
            lojas[id - 1] = AbreLoja(id, aluguel);
            break;

        case 2:
            scanf(" %[^ ]", name);
            scanf("%d %f %d", &salario, &percentage, &id);
            vendedor = RegistraVendedor(name, salario, percentage);
            lojas[id - 1] = ContrataVendedor(lojas[id - 1], vendedor);
            break;

        case 3:

            scanf("%d %[^ ] %f", &id, name, &aluguel);

            for (int l = 0; l < MAX_VENDEDORES; l++)
            {

                if (!strcmp(lojas[id - 1].vendedores[l].nome, name))
                {

                    lojas[id - 1].vendedores[l] = ContabilizaVenda(
                        lojas[id - 1].vendedores[l], aluguel);
                    break;
                }
            }
            break;

        case 4:

            for( int i = 0;i<qtd_loja;i++){

                lojas[i] = CalculaLucro(lojas[i]);
            }

            for (int i = 0; i < qtd_loja; i++)
            {

                ImprimeRelatorioLoja(lojas[i]);
            }

            break;
        }
    }
}
