#include "partida.h"
#include <stdio.h>
#include <string.h>
#include "jogador.h"
#include "busca.h"
#include "inconsistencias.h"
#include "relatorio.h"
#include <stdbool.h>

int main()
{
    int gols = 0, id_equipe = 0, id_j = 0, qtd_partidas = 0;
    char option;
    tEquipe equipes[20];
    int qtd_equipes = 0, qtd_jogadores = 0;
    tJogador jogadores[MAX_GOLS_EQUIPE];
    tPartida partida;

    int eqp_1 = tPartida_getIdEquipe1(partida);
    int eqp_2 = tPartida_getIdEquipe2(partida);
    int pos_e1 = tEquipe_encontraIndiceVetorComIdUnico(equipes, qtd_equipes, eqp_1);
    int pos_e2 = tEquipe_encontraIndiceVetorComIdUnico(equipes, qtd_equipes, eqp_2);
    int qtd_gols_1 = tPartida_getNumGolsEquipe1(partida);
    int qtd_gols_2 = tPartida_getNumGolsEquipe1(partida);
    int gol = 0;
    int code_eqp = 0, code_j = 0;
    int j_1, j_2;

    bool t1 = true, t2 = true;

    while (1)
    {

        scanf("%c\n", &option);

        if (option == 'F')
        {

            break;
        }

        switch (option)
        {

        case 'E':
            equipes[qtd_equipes++] = leEquipe();
            break;

        case 'J':

            jogadores[qtd_jogadores] = lerJogador();
            id_equipe = tJogador_getIdUnico(jogadores[qtd_jogadores]);
            equipes[id_equipe] = tEquipe_incrementaNumeroJogadores(equipes[qtd_equipes]);
            qtd_jogadores++;

            break;

        case 'P':

            partida = tPartida_lerPartida();

            for (int i = 0; i < qtd_gols_1; i++)
            {

                scanf("%d\n", &gol);
                equipes[eqp_1] = tEquipe_adicionaGolPro(equipes[eqp_1], gol);
            }

            for (int j = 0; j < qtd_gols_2; j++)
            {

                scanf("%d\n", &gol);
                equipes[eqp_2] = tEquipe_adicionaGolPro(equipes[eqp_2], gol);
            }

            equipes[eqp_1] = tEquipe_adicionaGolsContra(equipes[eqp_1], qtd_gols_2);
            equipes[eqp_2] = tEquipe_adicionaGolsContra(equipes[eqp_2], qtd_gols_1);
            j_1 = tEquipe_getNumeroJogadores(equipes[eqp_1]);
            j_2 = tEquipe_getNumeroJogadores(equipes[eqp_2]);
            t2 = j_2 >= 5;
            t1 = j_1 >= 5;

            if (qtd_gols_1 == qtd_gols_2)
            {

                equipes[eqp_1] = tEquipe_incrementaEmpates(equipes[eqp_1]);
                equipes[eqp_2] = tEquipe_incrementaEmpates(equipes[eqp_2]);
            }
            else if (qtd_gols_1 > qtd_gols_2)
            {

                equipes[eqp_1] = tEquipe_incrementaVitorias(equipes[eqp_1]);
                equipes[eqp_2] = tEquipe_incrementaDerrotas(equipes[eqp_2]);
            }
            else
            {

                equipes[eqp_1] = tEquipe_incrementaDerrotas(equipes[eqp_1]);
                equipes[eqp_2] = tEquipe_incrementaVitorias(equipes[eqp_2]);
            }

            qtd_partidas++;

            break;
        }
    }

    if (!verificaInconsistencias(qtd_partidas, qtd_equipes, equipes))
    {

        geraRelatorio(equipes, qtd_equipes, jogadores, qtd_jogadores);
    }
}