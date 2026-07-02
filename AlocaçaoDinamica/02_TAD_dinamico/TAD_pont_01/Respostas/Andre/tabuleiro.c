#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

#define PECA_1 'X'
#define PECA_2 '0'
#define PECA_VAZIA '-'

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro *CriaTabuleiro()
{

    tTabuleiro *tabuleiro;

    tabuleiro = malloc(sizeof(*tabuleiro));                                     // Aloca memória struct
    tabuleiro->posicoes = malloc(sizeof(*tabuleiro->posicoes) * TAM_TABULEIRO); // Aloca memória pro ¨ matriz

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        tabuleiro->posicoes[i] = malloc(sizeof(tabuleiro->posicoes[i]) * TAM_TABULEIRO); // Mem para cada ponteiro do ponteiro matriz;
    }

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            tabuleiro->posicoes[i][j] = PECA_VAZIA;
        }
    }

    tabuleiro->peca1 = PECA_1;
    tabuleiro->peca2 = PECA_2;
    tabuleiro->pecaVazio = PECA_VAZIA;

    return tabuleiro;
}

/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 *
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro)
{

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        free(tabuleiro->posicoes[i]);
    }

    free(tabuleiro->posicoes);
    free(tabuleiro);
}

/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y)
{

    switch (peca)
    {
    case 1:

        tabuleiro->posicoes[x][y] = PECA_1;
        break;

    case 2:

        tabuleiro->posicoes[x][y] = PECA_2;
        break;

    default:

        break;
    }
}

/**
 * Verifica se há alguma posição livre no tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro)
{

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            if (tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio)
            {

                return 1;
            }
        }
    }
    return 0;
}

/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 *
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 *
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca)
{

    char pessa ='0';

    switch (peca)
    {
    case 1:

        pessa = PECA_1;
        break;

    case 2:

        pessa = PECA_2;
        break;

    default:

        break;
    }

    return (tabuleiro->posicoes[x][y] == pessa);
}

/**
 * Verifica se a posição do tabuleiro está livre.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y)
{

    return (tabuleiro->posicoes[x][y] == PECA_VAZIA);
}

/**
 * Verifica se a posição do tabuleiro é válida.
 *
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y)
{

    return (x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO);
}

/**
 * Imprime o tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro *tabuleiro)
{

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        printf("\t");

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            printf("%c", tabuleiro->posicoes[j][i]);
        }

        printf("\n");
    }
}
