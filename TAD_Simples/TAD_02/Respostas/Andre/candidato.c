#include "candidato.h"
#include <stdio.h>
#include <string.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id) {
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;

    return candidato;
}

tCandidato LeCandidato() {
    char nome[50];
    char partido[50];
    char cargo;
    int id;

    scanf(" %[^,], %[^,], %c, %d", nome, partido, &cargo, &id);
    tCandidato c = CriaCandidato(nome, partido, cargo, id);

    return c;
}

int VerificaIdCandidato(tCandidato candidato, int id)
{

    if (id == candidato.id)
    {

        return 1;
    }

    return 0;
}
int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{

    if (VerificaIdCandidato(candidato1,candidato2.id))
    {

        return 1;
    }

    return 0;
}
char ObtemCargo(tCandidato candidato)
{

    return candidato.cargo;
}

int ObtemVotos(tCandidato candidato)
{

    return candidato.votos;
}
float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{

    float percentual = 0;

    percentual = ((float)candidato.votos / (float)totalVotos) * 100;

    return percentual;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{

    candidato.votos+=1;

    return candidato;
}


void ImprimeCandidato(tCandidato candidato, float percentualVotos)
{

    printf("%s (%s), %d voto(s), %.2f% \n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}

