

#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

#include "bracket.h"

#define MAX_BRACKETS 1000

typedef struct Servidor tServidor;

/*
Função que lê todos os registros de brackets de um servidor a partir da entrada padrão e retorna um servidor
com todos os registros de brackets lidos. Conforme a especificação da atividade, a leitura é encerrada quando
um ID de bracket igual a -1 é lido.

@return *tServidor: Ponteiro de servidor com todos os registros de brackets lidos
*/
tServidor *leBracketsServidor();

/*
Função que recebe um servidor já preenchido com os dados de todas as brackets e um ID de jogador.
A partir dessas informações, ela busca as estatísticas do jogador em todas as brackets que ele participou.
Se o jogar não for encontrado, um jogador com ID -1 é criado e retornado.
Se o jogador for encontrado em uma ou mais brackets, suas estatísticas são agregadas e o jogador é retornado.

@param *s: tServidor
@param idJog: ID do jogador
*/
tJogador *buscaDadosJogadorServidor(tServidor *s, int idJog);

/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com as estatísticas de um conjunto de jogadores
solicitados a partir da entrada padrão. O relatório é impresso conforme o formato especificado na descrição da atividade.

@param *s: tServidor
*/
void criaRelatorioServidor(tServidor *s);

/*
Funçao que libera um ponteiro de servidor caso este seja diferente de NULL.

@param *s: tServidor
*/
void liberaServidor(tServidor *s);

#endif