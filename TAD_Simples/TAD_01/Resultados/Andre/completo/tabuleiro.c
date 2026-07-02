
#include <stdio.h>
#include "tabuleiro.h"
#include <string.h>
#include <stdbool.h>

/**
 * Cria um tabuleiro e retorna o tabuleiro criado.
 *
 * @return o tabuleiro criado.
 */
tTabuleiro CriaTabuleiro()
{

    tTabuleiro tabuleiro;

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}

/**
 * Marca uma posição do tabuleiro com a peça do jogador e retorna o tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada x da posição a ser marcada.
 * @param y a coordenada y da posição a ser marcada.
 *
 * @return o tabuleiro atualizado.
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{

    if (peca == PECA_1)
    {

        tabuleiro.posicoes[x][y] = tabuleiro.peca1;
    }
    else
    {

        tabuleiro.posicoes[x][y] = tabuleiro.peca2;
    }

    return tabuleiro;
}

/**
 * Verifica se há alguma posição livre no tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se há posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

            if (tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio)
                return 1;
        }
    }

    return 0;
}

/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 *
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @param peca a peça do jogador (1 ou 2).
 *
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{

    char Peça = 'c';

    if (peca == PECA_1)
    {

        Peça = tabuleiro.peca1;
    }
    else
    {

        Peça = tabuleiro.peca2;
    }

    if (tabuleiro.posicoes[x][y] == Peça)
    {

        return 1;
    }

    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){

        return tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @return 1 se a posição é válida, 0 caso contrário.
*/
int EhPosicaoValidaTabuleiro(int x, int y){

        return(( x >=0 && x<=2) && ( y >=0 && y<=2));

}


/**
 * Verifica se o tabuleiro está cheio.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro){


     for (int i = 0; i < TAM_TABULEIRO; i++)
    {

        printf("\t");
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {

                printf("%c",tabuleiro.posicoes[j][i]);
        }

            printf("\n");
    }
}

