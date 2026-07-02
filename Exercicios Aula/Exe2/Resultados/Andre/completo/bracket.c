#include "bracket.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bracket
{
    int idBracket;
    tJogador **jogadores;
};

/*
Função que lê apenas uma bracket a partir da entrada padrão. O registro de uma bracket
é composto das informações de 5 jogadores. Verifique a especificação da atividade para mais detalhes.

@param idbracket: ID da bracket
@return *tBracket: Uma bracket lida
*/
tBracket *leBracket(int idBracket)
{

    tBracket *b = (tBracket *)malloc(sizeof(tBracket));
    b->jogadores = (tJogador **)malloc(sizeof(tJogador *) * 5);

    int id = 0;

    int w, d, dr;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d:", &id);
        b->jogadores[i] = leJogador(id);
    }

    return b;
}

/*
Função que busca um jogador em um registro de bracket a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param *b: Uma bracket cadastrada
@param idJog: ID do jogador a ser buscado

@return *tJogador: Jogador encontrado (ou não)
*/
tJogador *buscaJogadorBracket(tBracket *b, int idJog)
{

    tJogador *ret = inicializaJogador(-1);

    int id_comp = 0;
    int w, d, dr;

    for (int i = 0; i < 5; i++)
    {

        id_comp = getIdJogador(b->jogadores[i]);

        if (id_comp == idJog)
        {
            liberaJogador(ret);
            return b->jogadores[i];
        }
    }

    return ret;
}

/*
Funçao que libera um ponteiro de uma bracket caso este seja diferente de NULL.

@param *b: Bracket
*/
void liberaBracket(tBracket *b)
{

    for (int i = 0; i < 5; i++)
    {

        liberaJogador(b->jogadores[i]);
    }

    free(b->jogadores);

    free(b);
}
