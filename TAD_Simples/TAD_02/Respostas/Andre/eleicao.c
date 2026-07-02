#include "eleicao.h"
#include "eleitor.h"
#include <stdio.h>
#include "candidato.h"
#include <stdlib.h>

tEleicao InicializaEleicao()
{

    tEleicao eleicao;
    tCandidato candidato = {0};
    int quantidade = 0, i = 0, j = 0, k = 0;

    eleicao.totalEleitores = 0;
    eleicao.totalGovernadores = 0;
    eleicao.totalPresidentes = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;

    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++)
    {

        candidato = LeCandidato();

        if (ObtemCargo(candidato) == 'P')
        {

            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        }

        else if (ObtemCargo(candidato) == 'G')
        {

            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
    }

    return eleicao;
}

tEleicao ProcessaVotos(tEleicao eleicao)
{

    int votoG = 0, votoP = 0, flagP = 1, flagG = 1;

    for (int j = 0; j < eleicao.totalEleitores; j++)
    {

        votoG = ObtemVotoGovernador(eleicao.eleitores[j]);
        votoP = ObtemVotoPresidente(eleicao.eleitores[j]);
        flagG = 0;
        flagP = 0;

        if (votoG == 0)
        {

            eleicao.votosBrancosGovernador++;
            flagG = 1;
        }

        if (votoP == 0)
        {

            eleicao.votosBrancosPresidente++;
            flagP = 1;
        }

        for (int k = 0; k < eleicao.totalGovernadores; k++)
        {

            if (VerificaIdCandidato(eleicao.governadores[k], votoG))
            {

                IncrementaVotoCandidato(eleicao.governadores[k]);
                flagG = 1;
            }
        }

        for (int l = 0; l < eleicao.totalPresidentes; l++)
        {

            if (VerificaIdCandidato(eleicao.presidentes[l], votoP))
            {

                IncrementaVotoCandidato(eleicao.presidentes[l]);
                flagP = 1;
            }
        }

        if (!flagG)
        {

            eleicao.votosNulosGovernador++;
        }

        if (!flagP)
        {

            eleicao.votosNulosPresidente++;
        }
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao)
{

    scanf("%d", &eleicao.totalEleitores);

    for (int i = 0; i < eleicao.totalEleitores; i++)
    {

        eleicao.eleitores[i] = LeEleitor();
    }

    eleicao = ProcessaVotos(eleicao);

    return eleicao;
}

int CalculaVotosInvalidosG(tEleicao eleicao)
{

    return eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador;
}
int CalculaVotosInvalidosP(tEleicao eleicao)
{

    return eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente;
}

tEleicao Ordena(tEleicao eleicao)
{

    int Flag = 1;
    tCandidato temp = {0};

    while (Flag)
    {

        Flag = 0;

        for (int i = 0; i < eleicao.totalGovernadores - 1; i++)
        {

            if (eleicao.governadores[i].votos < eleicao.governadores[i + 1].votos)
            {
                Flag = 1;
                temp = eleicao.governadores[i + 1];
                eleicao.governadores[i + 1] = eleicao.governadores[i];
                eleicao.governadores[i] = temp;
            }
        }
    }

    Flag = 1;

    while (Flag)
    {

        Flag = 0;

        for (int i = 0; i < eleicao.totalPresidentes - 1; i++)
        {

            if (eleicao.presidentes[i].votos < eleicao.presidentes[i + 1].votos)
            {

                Flag = 1;
                temp = eleicao.presidentes[i];
                eleicao.presidentes[i] = eleicao.presidentes[i + 1];
                eleicao.presidentes[i + 1] = temp;
            }
        }
    }

    return eleicao;
}

int CatchDrawG(tEleicao eleicao)
{

    for (int i = 1; i < eleicao.totalGovernadores; i++)
    {

        if (eleicao.governadores[0].votos == eleicao.governadores[i].votos)
        {

            return 1;
        }
    }

    return 0;
}

int CatchDrawP(tEleicao eleicao)
{

    for (int i = 1; i < eleicao.totalPresidentes; i++)
    {

        if (eleicao.presidentes[0].votos == eleicao.presidentes[i].votos)
        {

            return 1;
        }
    }

    return 0;
}

void ImprimeResultadoEleicao(tEleicao eleicao)
{

    float percentualG=0, percentualP=0;

    int FlagP = 1, FlagG = 1, nulos =0, brancos = 0;

    brancos = eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente;
    nulos = eleicao.votosNulosGovernador + eleicao.votosNulosPresidente;

    if (eleicao.totalEleitores > MAX_ELEITORES)
    {

        printf("ELEICAO ANULADA\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < eleicao.totalEleitores; i++)
    {

        for (int j = i + 1; j < eleicao.totalEleitores; j++)
        {

            if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j]))
            {

                printf("ELEICAO ANULADA\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    int InvalidosP = CalculaVotosInvalidosP(eleicao);
    int InvalidosG = CalculaVotosInvalidoG(eleicao);

    if (InvalidosP > eleicao.totalEleitores - InvalidosP)
    {

        printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
        FlagP = 0;
    }

    if (InvalidosG > eleicao.totalEleitores - InvalidosG)
    {

        printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
        FlagG = 0;
    }

    eleicao = Ordena(eleicao);

    if (CatchDrawP(eleicao))
    {

        printf(" - PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else
    {

         tCandidato vencedor = eleicao.presidentes[0];
                percentualP = CalculaPercentualVotos(vencedor,eleicao.eleitores);
                ImprimeCandidato(vencedor,percentualP);
                printf("- NULOS E BRANCOS: %d, %d\n",nulos, brancos);
    }

    if (CatchDrawG(eleicao))
    {

        printf(" - GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }

    else{

             tCandidato vencedor = eleicao.governadores[0];
                percentualG = CalculaPercentualVotos(vencedor,eleicao.eleitores);
                ImprimeCandidato(vencedor,percentualG);

                printf("- NULOS E BRANCOS: %d, %d\n",nulos, brancos);

        }

    }
