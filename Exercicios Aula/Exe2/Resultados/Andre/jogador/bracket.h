
#ifndef _BRACKET_H_
#define _BRACKET_H_

#include "jogador.h"

#define MAX_JOGADOR_BRACKET 5

/*
struct Bracket
{
    int idBracket;
    tJogador **jogadores;
};
*/

typedef struct Bracket tBracket;

/*
Função que lê apenas uma bracket a partir da entrada padrão. O registro de uma bracket
é composto das informações de 5 jogadores. Verifique a especificação da atividade para mais detalhes.

@param idbracket: ID da bracket
@return *tBracket: Uma bracket lida
*/
tBracket *leBracket(int idBracket);

/*
Função que busca um jogador em um registro de bracket a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param *b: Uma bracket cadastrada
@param idJog: ID do jogador a ser buscado

@return *tJogador: Jogador encontrado (ou não)
*/
tJogador *buscaJogadorBracket(tBracket *b, int idJog);

/*
Funçao que libera um ponteiro de uma bracket caso este seja diferente de NULL.

@param *b: Bracket
*/
void liberaBracket(tBracket *b);

#endif