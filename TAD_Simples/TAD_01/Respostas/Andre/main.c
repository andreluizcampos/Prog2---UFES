#include <stdio.h>
#include <string.h>
#include "jogada.h"
#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

int main()
{

    tJogo jogo;

    while (1)
    {
        jogo = CriaJogo();
        ComecaJogo(jogo);

        if (!ContinuaJogo())
        {

            break;
        }
    }
    return 0;
}
