#include "evento.h"
#include <stdio.h>
#include <string.h>

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */

void cadastrarEvento(Evento *eventos, int *numEventos)
{

    int dia, mes, ano;
    char nome[50];

    if (*numEventos < 10)
    {
        scanf(" %[^\n]\n", nome);
        scanf("%d %d %d\n", &dia, &mes, &ano);
        Evento evento;

        evento.ano = ano;
        evento.dia = dia;
        evento.mes = mes;
        strcpy(evento.nome, nome);

        eventos[*numEventos] = evento;
        *numEventos += 1;
    }

    else
    {

        printf("Limite de eventos atingido!\n");
    }
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento *eventos, int *numEventos)
{

    if (numEventos == 0)
    {

        printf("Nenhum evento cadastrado.\n");
    }

    for (int i = 0; i < *numEventos; i++)
    {

        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento *eventos, int *numEventos)
{

    int dia, mes, ano;

    int indice = 0;
    scanf("%d\n", &indice);

    if (indice >= *numEventos || indice < 0)
    {

        printf("Indice invalido!\n");
    }

    if (indice < *numEventos)
    {
        scanf("%d %d %d\n", &dia, &mes, &ano);

        eventos[indice].dia = dia;
        eventos[indice].mes = mes;
        eventos[indice].ano = ano;
    }
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento *eventos, int *indiceA, int *indiceB, int *numEventos)
{

    int swap = 0;
    Evento Evento_swap;
    Evento_swap = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = Evento_swap;
}