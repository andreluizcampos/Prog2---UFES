#include <stdlib.h>
#include <stdio.h>
#include "eleitor.h"
#include <string.h>
#include "candidato.h"
#include "eleicao.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10
#define VOTO_BRANCO 0
/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao *InicializaEleicao()
{

    int total_candidatos = 0, total_governadores = 0, total_presidentes = 0, total_eleitores = 0;

    tEleicao *eleicao = malloc(sizeof(*eleicao));
    tCandidato *candidato = NULL;

    eleicao->votosNulosPresidente = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosGovernador = 0;
    eleicao->votosBrancosGovernador = 0;
    eleicao->governadores = malloc(sizeof(*eleicao->governadores) * MAX_CANDIDATOS_POR_CARGO);
    eleicao->presidentes = malloc(sizeof(*eleicao->presidentes) * MAX_CANDIDATOS_POR_CARGO);

    for (int i = 0; i < MAX_CANDIDATOS_POR_CARGO; i++)
    {

        eleicao->governadores[i] =NULL;
    }
    for (int i = 0; i < MAX_CANDIDATOS_POR_CARGO; i++)
    {

        eleicao->presidentes[i] = NULL;
    }

    scanf("%d\n", &total_candidatos);

    for (int i = 0; i < total_candidatos; i++)
    {

        candidato = CriaCandidato();
        LeCandidato(candidato);
        char cargo = ObtemCargo(candidato);

        switch (cargo)
        {

        case 'G':

            eleicao->governadores[total_governadores++] = candidato;
            break;

        case 'P':
            eleicao->presidentes[total_presidentes++] = candidato;
            break;

        default:

            break;
        }
    }

    scanf("%d\n", &total_eleitores);
    eleicao->eleitores = malloc(sizeof(*eleicao->eleitores) * total_eleitores);

    for (int i = 0; i < total_eleitores; i++)
    {

        eleicao->eleitores[i] = malloc(sizeof(*eleicao->eleitores[i]));
    }

    for (int i = 0; i < total_eleitores; i++)
    {

        LeEleitor(eleicao->eleitores[i]);
    }

    eleicao->totalEleitores = total_eleitores;
    eleicao->totalGovernadores = total_governadores;
    eleicao->totalPresidentes = total_presidentes;


    return eleicao;
}

void ApagaEleicao(tEleicao *eleicao)
{

    for (int i = 0; i < eleicao->totalGovernadores; i++)
        ApagaCandidato(eleicao->governadores[i]);
    for (int i = 0; i < eleicao->totalPresidentes; i++)
        ApagaCandidato(eleicao->presidentes[i]);
    for (int i = 0; i < eleicao->totalEleitores; i++)
        ApagaEleitor(eleicao->eleitores[i]);

    free(eleicao->governadores);
    free(eleicao->presidentes);
    free(eleicao->eleitores);
    free(eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 */
void RealizaEleicao(tEleicao *eleicao)
{
    int flag = 0;
    int voto_gov = 0, voto_pres = 0;

    for (int i = 0; i < eleicao->totalEleitores; i++)
    {

        voto_gov = ObtemVotoGovernador(eleicao->eleitores[i]);
        voto_pres = ObtemVotoPresidente(eleicao->eleitores[i]);

        for (int j = 0; j < eleicao->totalGovernadores; j++)
        {

            if (VerificaIdCandidato(eleicao->governadores[j], voto_gov))
            {

                eleicao->governadores[j]->votos++;
                flag = 1;
            }
        }

        if (voto_gov == VOTO_BRANCO)
        {

            eleicao->votosBrancosGovernador++;
            flag = 1;
        }
        else if (!flag)
        {

            eleicao->votosNulosGovernador++;
        }

        flag = 0;

        for (int l = 0; l < eleicao->totalPresidentes; l++)
        {

            if (VerificaIdCandidato(eleicao->presidentes[l], voto_pres))
            {

                eleicao->presidentes[l]->votos++;
                flag = 1;
            }
        }
        if (voto_pres == VOTO_BRANCO)
        {

            eleicao->votosBrancosPresidente++;
            flag = 1;
        }

        else if (!flag)
        {

            eleicao->votosNulosPresidente++;
        }

        flag = 0;
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao *eleicao)
{
    for (int i = 0; i < eleicao->totalEleitores; i++)
    {

        for (int j = i + 1; j < eleicao->totalEleitores; j++)
        {

            if (EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j]))
            {

                printf("ELEICAO ANULADA\n");
                ApagaEleicao(eleicao);
                exit(0);
            }
        }
    }

    int flag = 1;

    tCandidato *candidato;

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < eleicao->totalGovernadores - 1; i++)
        {

            if (eleicao->governadores[i]->votos < eleicao->governadores[i + 1]->votos)
            {

                candidato = eleicao->governadores[i];
                eleicao->governadores[i] = eleicao->governadores[i + 1];
                eleicao->governadores[i + 1] = candidato;
                flag = 1;
            }
        }
    }

    flag = 1;

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < eleicao->totalPresidentes - 1; i++)
        {

            if (eleicao->presidentes[i]->votos < eleicao->presidentes[i + 1]->votos)
            {

                candidato = eleicao->presidentes[i];
                eleicao->presidentes[i] = eleicao->presidentes[i + 1];
                eleicao->presidentes[i + 1] = candidato;
                flag = 1;
            }
        }
    }

    int nulos = eleicao->votosNulosGovernador + eleicao->votosNulosPresidente;
    int brancos = eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente;
    int val_gov = eleicao->totalEleitores - eleicao->votosBrancosGovernador - eleicao->votosNulosGovernador;
    int in_gov = eleicao->totalEleitores - val_gov;
    int val_pres = eleicao->totalEleitores - eleicao->votosBrancosPresidente - eleicao->votosNulosPresidente;
    int in_pres = eleicao->totalEleitores - val_pres;
    flag = 1;
    printf("- PRESIDENTE ELEITO: ");

    if (val_pres <= in_pres)
    {

        printf("SEM DECISAO\n");
        flag = 0;
    }

    if (flag)
    {
        if (eleicao->presidentes[0]->votos > eleicao->presidentes[1]->votos)
        {
            ImprimeCandidato(eleicao->presidentes[0], CalculaPercentualVotos(eleicao->presidentes[0], eleicao->totalEleitores));
        }

        else if (eleicao->presidentes[0]->votos == eleicao->presidentes[1]->votos)
        {

            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
    }

    flag = 1;

    printf("- GOVERNADOR ELEITO: ");
    if (val_gov <= in_gov)
    {

        printf("SEM DECISAO\n");
        flag = 0;
    }

    if (flag)
    {
        if (eleicao->governadores[0]->votos > eleicao->governadores[1]->votos)
        {
            ImprimeCandidato(eleicao->governadores[0], CalculaPercentualVotos(eleicao->governadores[0], eleicao->totalEleitores));
        }

        else if (eleicao->governadores[0]->votos == eleicao->governadores[1]->votos)
        {

            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }
    }

    printf("- NULOS E BRANCOS: %d, %d", nulos, brancos);
}
