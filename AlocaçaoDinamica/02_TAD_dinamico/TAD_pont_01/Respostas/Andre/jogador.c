#include <stdio.h>
#include "jogada.h"
#include "tabuleiro.h"
#include <stdlib.h>
#include "jogador.h"
#include <stdbool.h>

/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 *
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador *CriaJogador(int idJogador)
{

    tJogador *jogador;

    jogador = malloc(sizeof(*jogador));
    jogador->id = idJogador;

    return jogador;
}

/**
 * Libera a memória de uma estrutura do tipo tJogador.
 *
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador *jogador)
{

    free(jogador);
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    tJogada *jogada = CriaJogada();

    int flag = 1;

    while (flag)
    {

        printf("Jogador %d\n",jogador->id);
        LeJogada(jogada);

        if (!FoiJogadaBemSucedida(jogada))
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
                
            continue;
        }

    
    int  x = ObtemJogadaX(jogada);
     int  y = ObtemJogadaY(jogada);

        if (!EhPosicaoValidaTabuleiro(x, y))
        {

            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        }
        else if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
        {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        }

        else
        {
            MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);
            printf("Jogada [%d,%d]!\n", x, y);
            flag = 0;
        }
    }

    free(jogada);
}

/**
 * Verifica se o jogador venceu o jogo.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{

    char symbol;

    int count = 0;

    switch (jogador->id)
    {

    case 1:

        symbol = 'X';
        break;

    case 2:
        symbol = '0';
        break;
    }

    for (int i = 0; i < TAM_TABULEIRO; i++) // Check horizontal
    {

        count = 0;

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador->id))
            {

                count++;

                if (count == 3)
                {

                    return true;
                }
            }
        }
    }

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        count = 0;

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador->id))
            {

                count++;

                if (count == 3)
                {

                    return true;
                }
            }
        }
    } // Check Vertical

    count = 0;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, jogador->id))
        {
            count++;
            if (count == 3)
            {

                return true;
            }
        }
    }

    int l = 0;
    count = 0;

    for (int i = TAM_TABULEIRO - 1; i >= 0; i--)
    {

        if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, l, i, jogador->id))
        {
            count++;

            if (count == 3)
            {

                return true;
            }
        }
        l++;
    }

    return false;
}