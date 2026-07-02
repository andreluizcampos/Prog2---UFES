#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"
#include "tabuleiro.h"

tJogada *CriaJogada()
{

    tJogada *jogada;

    jogada = malloc(sizeof(*jogada));
    jogada->x = 0;
    jogada->y = 0;
    jogada->sucesso = 0;

    return jogada;
}

void DestroiJogada(tJogada *jogada)
{

    free(jogada);
}

void LeJogada(tJogada *jogada)
{

    printf("Digite uma posicao (x e y):\n");

    if (scanf("%d %d", &jogada->x, &jogada->y) == 2)
    {
        jogada->sucesso = 1;
    }
        int c;
      while ((c = getchar()) != '\n' && c != EOF);
}

int ObtemJogadaX(tJogada *jogada)
{

    return jogada->x;
}

int ObtemJogadaY(tJogada *jogada)
{

    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada *jogada)
{

    return jogada->sucesso;
}
