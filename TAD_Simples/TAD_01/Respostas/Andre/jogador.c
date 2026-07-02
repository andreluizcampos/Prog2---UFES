#include <stdio.h>
#include <string.h>
#include "jogada.h"
#include "jogador.h"
#include "tabuleiro.h"
/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 *
 * @param idJogador o id do jogador (1 ou 2).
 *
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{

    tJogador jogador;

    jogador.id = idJogador;

    return jogador;
}

/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 *
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{

    int troca = 1, id = jogador.id;

    tJogada jogada;

    while (1)
    {

        printf("Jogador %d\n", id);

        jogada = LeJogada();

        if (!jogada.sucesso)
        {

            break;
        }
        int x = ObtemJogadaX(jogada), y = ObtemJogadaY(jogada);

        if (!EhPosicaoValidaTabuleiro(x, y))
        {

            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
            continue;
        }

        else if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
        {

            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        }
        else
        {
            printf("Jogada [%d,%d]!\n", x, y);
            tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, id, x, y);
            break;
        }
    }

    return tabuleiro;
}

/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 *
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    char peca;

    int contador = 0;

    switch (jogador.id)
    {

    case 1:

        peca = tabuleiro.peca1;
        break;

    case 2:

        peca = tabuleiro.peca2;

        break;

    default:

        break;
    }

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        contador = 0;

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            if (tabuleiro.posicoes[i][j] == peca)
            {

                contador++;
                if (contador == 3)
                {

                    return 1;
                }
            }
        }
    }

    contador = 0;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        contador = 0;

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            if (tabuleiro.posicoes[j][i] == peca)
            {

                contador++;
                if (contador == 3)
                {

                    return 1;
                }
            }
        }
    }

    contador = 0;

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        if (tabuleiro.posicoes[i][i] == peca)
        {

            contador++;
        }

        if (contador == 3)
        {

            return 1;
        }
    }

    int l = 0;
    contador = 0;

    for (int i = TAM_TABULEIRO - 1; i >= 0; i--)
    {

        if (tabuleiro.posicoes[l][i] == peca)
        {

            contador++;
        }
        l++;

        if (contador == 3)
        {

            return 1;
        }
    }

    return 0;
}