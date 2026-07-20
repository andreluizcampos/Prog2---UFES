#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supermercado.h"
#include "produto.h"

int main()
{
    Supermercado *s = CriarSupermercado();
    char option[MAX_CARACTERES];

    while (scanf("%s", option) == 1)
    {
        if (!strcmp(option, "ENCERRAR"))
        {
            LiberaSupermercado(s);
            return 0;
        }

        if (!strcmp(option, "CADASTRAR"))
        {
            LerCadastroSupermercado(s);
            continue;
        }

        if (!strcmp(option, "COMPRAR"))
        {
            LerCompraSupermercado(s);
            continue;
        }

        if (!strcmp(option, "FORNECEDOR"))
        {
            LerFornecimento(s);
            continue;
        }

        if (!strcmp(option, "ESTOQUE"))
        {
            ConsultarEstoqueSupermercado(s);
            continue;
        }

        if (!strcmp(option, "LUCRO"))
        {
            ConsultarLucroSupermercado(s);
        }
    }

    LiberaSupermercado(s);
    return 0;
}