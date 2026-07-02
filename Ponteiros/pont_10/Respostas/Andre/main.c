#include <stdio.h>
#include "pessoa.h"

int main()
{

    int numero_pessoas = 0, i = 0;
    int numero_pessoas_clone = 0;

    scanf("%d\n", &numero_pessoas);

    numero_pessoas_clone = numero_pessoas;

    tPessoa pessoas[numero_pessoas];

    while (numero_pessoas)
    {

        pessoas[i]=CriaPessoa();
        LePessoa(&pessoas[i]);
        i++;
        numero_pessoas--;
    }

    AssociaFamiliasGruposPessoas(pessoas, numero_pessoas_clone);

    i = 0;

    while (numero_pessoas_clone)
    {
        numero_pessoas_clone--;
        ImprimePessoa(&pessoas[i]);
        i++;
    }
}