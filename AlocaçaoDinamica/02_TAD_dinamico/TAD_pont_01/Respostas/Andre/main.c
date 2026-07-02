#include <stdio.h>
#include "jogada.h"
#include "tabuleiro.h"
#include <stdlib.h>
#include "jogador.h"
#include <stdbool.h>
#include "jogo.h"

int main()
{

    tJogo *jogo = CriaJogo();

    while (1)
    {

        ComecaJogo(jogo);
        if (!ContinuaJogo())
        {

            break;
        }
        
        DestroiJogo(jogo);
        jogo = CriaJogo();
    }

    DestroiJogo(jogo);
}