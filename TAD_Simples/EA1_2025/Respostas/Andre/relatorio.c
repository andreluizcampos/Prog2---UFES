#include <stdio.h>
#include <string.h>
#include "relatorio.h"
#include <limits.h>

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
    int nJogadores)
{

    int campea = 0, artilheiro = 0, id_campea = 0, id_artilheiro = -1, flag = 1, id_time_artilheiro = 0;

    char Campea[TAM_MAX_NOME] = "", Equipe_Artilheiro[TAM_MAX_NOME] = "", Artilheiro[TAM_MAX_NOME] = "";

    while (flag)
    {
        flag = 0;
        for (int i = 0; i < nEquipes - 1; i++)
        {

            if (tEquipe_getNumPontos(equipes[i]) < tEquipe_getNumPontos(equipes[i + 1]))
            {
                tEquipe temp = equipes[i];
                equipes[i] = equipes[i + 1];
                equipes[i + 1] = temp;
                flag = 1;
            }
        }
    } // BubbleSort para o indice 0 ter a campeã;

    for (int i = 0; i < nEquipes; i++)
    {

        int id_equipe = tEquipe_getIdUnico(equipes[i]);

        for (int j = 0; j < tEquipe_getNumeroJogadores(equipes[i]); j++)
        {

            for (int k = 0; k < nJogadores; k++)
            {

                int equipe_jogador = tJogador_getIdEquipe(jogadores[k]);
                int id_jogador = tJogador_getIdUnico(jogadores[k]);

               
                    if (tEquipe_getQtdeGolsJogador(equipes[i], id_jogador) > artilheiro)
                    {

                        artilheiro = tEquipe_getQtdeGolsJogador(equipes[i], id_jogador);
                        tEquipe_copiaNome(equipes[i], Equipe_Artilheiro);
                        tJogador_copiaNome(jogadores[k], Artilheiro);
                    }
                
            }
        }
    }

    float aproveitamento = 0;

    if (tEquipe_getNumJogos(equipes[0]) > 0)
    {


        aproveitamento =  (float)tEquipe_getNumPontos(equipes[0]) / ((float)tEquipe_getNumJogos(equipes[0]) *3.0);

      aproveitamento = aproveitamento * 100.0;
    }   

    int P, J, V, E, D, GP, GC, SG;

    P = tEquipe_getNumPontos(equipes[0]);
    J = tEquipe_getNumJogos(equipes[0]);
    E = tEquipe_getNumeroEmpates(equipes[0]);
    V = tEquipe_getNumeroVitorias(equipes[0]);
    GP = tEquipe_getNumeroGolsPro(equipes[0]);
    GC = tEquipe_getNumeroGolsContra(equipes[0]);
    SG = tEquipe_getSaldogols(equipes[0]);
    D = tEquipe_getNumeroDerrotas(equipes[0]);

    id_campea = tEquipe_getIdUnico(equipes[0]);
    tEquipe_copiaNome(equipes[0], Campea);

    printf("EQUIPE CAMPEA: %s (%d) P:%d J:%d V:%d E:%d D:%d GP:%d GC:%d SG:%d AP:%.2f%\n", Campea, id_campea, P, J, V, E, D, GP, GC, SG, aproveitamento);
    printf("ARTILHEIRO: %s (%s) - %d GOLS\n", Artilheiro, Equipe_Artilheiro, artilheiro);
}