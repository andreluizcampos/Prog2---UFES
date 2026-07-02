#ifndef RELATORIO_H
#define RELATORIO_H

#include "equipe.h"
#include "jogador.h"

/**
 * @brief Função que gera o relatório de saída, com as informações de
 *        "EQUIPE CAMPEA" (basta buscar equipe com mais pontos e imprimir suas
 *        informações) e "ARTILHEIRO" (buscar jogador com mais gols e imprimir
 *        informações) conforme especificado no pdf.
 * @param equipes - Vetor de equipes cadastradas
 * @param nEquipes - número de equipes cadastradas
 * @param jogadores  - Vetor de jogadores cadastradas
 * @param nJogadores - número de equipes cadastradas
 */
void geraRelatorio(
    tEquipe equipes[],
    int nEquipes,
    tJogador jogadores[],
    int nJogadores
);

#endif
