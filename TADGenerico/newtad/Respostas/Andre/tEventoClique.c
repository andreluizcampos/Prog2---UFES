#include <stdio.h>
#include "tEventoClique.h"
#include <stdlib.h>
#include <string.h>

struct EventoClique
{

    char c[3];
};

tEventoCLique *CriaCique(char *caracateres)
{

    tEventoCLique *c = (tEventoCLique *)malloc(sizeof(tEventoCLique));

    for (int i = 0; i < 3; i++)
    {

        c->c[i] = caracateres[i];
    }

    return c;
}
void LiberaEventoClique(void *eve)
{

    tEventoCLique *e = (tEventoCLique *)eve;

    free(e);
}

void ProcessaEventoCique(tAmbiente *a, char c, void *eve)
{

    int linha, coluna;

    retornaPosicaoAtual(a, &linha, &coluna);

    char mov = retornaSituacaoPosicao(a, linha, coluna);

    if (mov != 0 && mov != '\0')
    {

        printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");

        return;
    }

    if (linha >= 10 || linha < 0 || coluna >= 10 || coluna < 10)
    {

        printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");

        return;
    }

    alteraPosicaoJogador(a, linha, coluna);

    printf("MOVIMENTO PARA POSICAO (%d,%d)\n", linha, coluna);
}


int IdentificaEventoClique(char c, void *eve)
{

    tEventoCLique *e = (tEventoCLique *)eve;

    for (int i = 0; i < 3; i++)
    {

        if (c == e->c[i])
        {

            return 1;
        }
    }

    return 0;
}