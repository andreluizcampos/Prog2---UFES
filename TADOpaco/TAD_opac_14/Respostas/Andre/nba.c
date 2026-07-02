#include "nba.h"
#include "partida.h"
#include "franquia.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct nba
{

    tFranquia *franquias;
    tPartida *partidas;
    int qtd_f;
    int qtd_p;
};

/**
 * @brief Cria uma nova instância da NBA.
 *
 * @return tNBA Retorna um ponteiro para a nova instância da NBA.
 */
tNBA CriaNBA()
{

    tNBA nba = (tNBA )(malloc(sizeof(struct nba )));
    nba->franquias = (tFranquia *)malloc(sizeof(tFranquia));
    nba->partidas = (tPartida *)malloc(sizeof(tPartida));
    nba->qtd_f = 0;
    nba->qtd_p = 0;

    return nba;
}

/**
 * @brief Roda a NBA, permitindo a interação com o usuário.
 *
 * @param nba Ponteiro para a instância da NBA a ser executada.
 * @return tNBA Retorna um ponteiro para a instância da NBA após a execução.
 */
tNBA RodaNBA(tNBA nba)
{

    char option;

    while (1)
    {

        scanf("%c\n", &option);

        if (option == 'E')
        {

            break;
        }

        switch (option)
        {

        case 'F':

            nba->franquias[nba->qtd_f] = LeFranquia();
            nba->qtd_f++;
            nba->franquias = realloc(nba->franquias, (nba->qtd_f + 1) * sizeof(tFranquia));

            break;

        case 'P':

            nba->partidas[nba->qtd_p] = LePartida();
            nba->qtd_p++;
            nba->partidas = realloc(nba->partidas, (nba->qtd_p + 1) * sizeof(tPartida));
            break;

        case 'E':
            break;
        }
    }

    return nba;
}

/**
 * @brief Imprime o relatório final da NBA.
 *
 * @param nba Ponteiro para a instância da NBA a ser impressa.
 */
void ImprimeRelatorioNBA(tNBA nba)
{

    for (int i = 0; i < nba->qtd_p; i++)
    {

        for (int j = 0; j < nba->qtd_f; j++)
        {

            if (strcmp(GetTime1Partida(nba->partidas[i]), GetNomeFranquia(nba->franquias[j])) == 0)
            {

                if (GetVencedorPartida(nba->partidas[i]) == 1)
                {

                    AdicionaVitoriaCasaFranquia(nba->franquias[j]);
                }

                else
                {

                    AdicionaDerrotaCasaFranquia(nba->franquias[j]);
                }
            }

            if (strcmp(GetTime2Partida(nba->partidas[i]), GetNomeFranquia(nba->franquias[j])) == 0)
            {

                if (GetVencedorPartida(nba->partidas[i]) == 2)
                {

                    AdicionaVitoriaForaFranquia(nba->franquias[j]);
                }
                else
                {

                    AdicionaDerrotaForaFranquia(nba->franquias[j]);
                }
            }
        }
    }

    int qtd_leste = 0, qtd_oeste = 0, v_oeste = 0, v_leste = 0, d_leste = 0, d_oeste = 0;

    float a_leste = 0, a_oeste = 0;

    for (int i = 0; i < nba->qtd_f; i++)
    {
        ImprimeFranquia(nba->franquias[i]);
    }

    for (int i = 0; i < nba->qtd_f; i++)
    {

        if (strcmp(GetConferenciaFranquia(nba->franquias[i]), "LESTE") == 0)
        {

            v_leste += GetVitoriaCasaFranquia(nba->franquias[i]) + GetVitoriaForaFranquia(nba->franquias[i]);
            d_leste += GetDerrotaCasaFranquia(nba->franquias[i]) + GetDerrotaForaFranquia(nba->franquias[i]);
        }

        else
        {

            v_oeste += GetVitoriaCasaFranquia(nba->franquias[i]) + GetVitoriaForaFranquia(nba->franquias[i]);
            d_oeste += GetDerrotaCasaFranquia(nba->franquias[i]) + GetDerrotaForaFranquia(nba->franquias[i]);
        }
    }
    qtd_leste = v_leste + d_leste;
    qtd_oeste = v_oeste + d_oeste;

    if (qtd_leste > 0)
    {
        a_leste = (float)v_leste / (float)qtd_leste;
    }

    if (qtd_oeste > 0)
    {
        a_oeste = (float)v_oeste / (float)qtd_oeste;
    }

    a_oeste = a_oeste * 100.0;
    a_leste = a_leste * 100.0;

    printf("LESTE %d %d %.2f\n", v_leste, d_leste, a_leste);
    printf("OESTE %d %d %.2f\n", v_oeste, d_oeste, a_oeste);
}
/**
 * @brief Libera a memória alocada para a instância da NBA.
 *
 * @param nba Ponteiro para a instância da NBA a ser liberada.
 */
void LiberaNBA(tNBA nba)
{

    for (int i = 0; i < nba->qtd_p; i++)
    {

        LiberaPartida(nba->partidas[i]);
    }
    for (int i = 0; i < nba->qtd_f; i++)
    {

        LiberaFranquia(nba->franquias[i]);
    }

    free(nba->franquias);
    free(nba->partidas);
    free(nba);
}
