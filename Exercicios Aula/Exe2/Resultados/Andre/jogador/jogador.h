#ifndef _JOGADOR_H
#define _JOGADOR_H

#include <string.h>

#define MAX_LEAGUE 15

/*
struct Jogador
{
    int id;
    int wins;
    int defeats;
    int draws;
    char *league;
};
*/

typedef struct Jogador tJogador;


/*
Função que inicializa um jogador com ID passado por parâmetro
Todas as estatísticas do jogador são inicializadas com 0
e o valor da league é inicializado com ROOKIE

@param id: ID do jogador
@return *tJogador: Ponteiro de tJogador inicializado
*/
tJogador *inicializaJogador(int id);

/*
Função que lê as estatísticas de um jogador a partir da entrada padrão e retorna um jogador inicializado
com essas estatísticas. O ID do jogador é passado por parâmetro. Uma vez lidas as estatísticas, a liga
é calculada e armazenada no jogador.

@param id: ID do jogador
@return *tJogador: Jogador inicializado com as estatísticas lidas e o valor da liga calculada
*/
tJogador *leJogador(int id);

/*
Função que calcula a liga (league) de um jogador e a retorna para ser armazenada no campo
league do próprio jogador

@param *j: Ponteiro de jogador
*/
void calculaLeague(tJogador *j);

/*
Função que recebe um jogador cadastrado e atualiza suas estatísticas de acordo com os valores passados por parâmetro.
O ID do jogador é sempre igualado ao ID passado por parâmetro e as estatísticas de wins, deafeats e draws são incrementadas
pelos valores passados por parâmetro. A liga do jogador é recalculada e armazenada no campo league do jogador.

@param *j: Jogador
@param id: ID do jogador
@param k: Wins a serem incrementadas
@param d: Defeats a serem incrementadas
@param a: Draws a serem incrementadas

@return *tJogador: Ponteiro do jogador atualizado
*/
tJogador *atualizaJogador(tJogador *j, int id, int k, int d, int a);

/*
Funçao que recebe um jogador e retorna o numero de wins do jogador

@param *j: Ponteiro de tJogador
@return int: Wins do jogador
*/
int getWinsJogador(tJogador *j);

/*
Funçao que recebe um jogador e retorna o valor de deaths do jogador

@param *j: Ponteiro de tJogador
@return int: Defeats do jogador
*/
int getDefeatsJogador(tJogador *j);

/*
Funçao que recebe um jogador e retorna o valor de assists do jogador

@param *j: Ponteiro de tJogador
@return int: Draws do jogador
*/
int getDrawsJogador(tJogador *j);

/*
Funçao que recebe um jogador e retorna o valor de ID do jogador

@param *j: Ponteiro de tJogador
@return int: ID do jogador
*/
int getIdJogador(tJogador *j);

/*
Funçao que recebe um ponteiro de jogador e imprime suas informações conforme o formato especificado

@param *j: Jogador
*/
void printaJogador(tJogador *j);

/*
Funçao que libera um ponteiro de jogador caso este seja diferente de NULL.

@param *j: Jogador
*/
void liberaJogador(tJogador *j);

#endif