#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tMonitorador.h"
#include "tAmbiente.h"
#include "tEventoClique.h"
#include "tEventoMovimento.h"

typedef struct Evento
{

    FptrIdentificaEvento ident;
    FptrLiberaEvento libera;
    FptrProcessaEvento processa;
    void *evento;
} tEvento;

struct _tMonitorador
{

    tEvento **eventos;
    int qtd;
};

/// @brief Função que cria uma variável do tipo monitorador de eventos
/// @return Um ponteiro para a variável do tipo monitorador de eventos
tMonitorador *criaMonitorador()
{

    tMonitorador *m = (tMonitorador *)malloc(sizeof(tMonitorador));
    m->qtd = 0;
    m->eventos = (tEvento **)malloc(sizeof(tEvento *));
    return m;
}

/// @brief Função que libera o monitorador e seus eventos cadastrados.
/// @param m - O monitorador a ser liberado
void liberaMonitorador(tMonitorador *m)
{

    for (int i = 0; i < m->qtd; i++)
    {

        m->eventos[i]->libera(m->eventos[i]->evento);
        free(m->eventos[i]);
    }

    free(m->eventos);

    free(m);
}

/// @brief Função que adiciona um evento a um monitorador de eventos
/// @param m - Ponteiro para o monitorador de eventos
/// @param e - Ponteiro para o evento a ser cadastrado no monitorados
/// @param funcPE Callback para a função a ser executada quando o evento for identificado ("evento será processado")
/// @param funcId Callback para a função responsável por indicar se a tecla apertada se refere a um dos eventos
///                 cadastrados no monitorador
/// @param funcLE Callback para a função a ser executada quando o evento cadastrado tiver que ser liberado
void adicionaElementoMonitorador(tMonitorador *m, void *e, FptrProcessaEvento funcPE, FptrIdentificaEvento funcId, FptrLiberaEvento funcLE)
{
    tEvento *E = (tEvento *)malloc(sizeof(tEvento));
    E->evento = e;
    E->ident = funcId;
    E->libera = funcLE;
    E->processa = funcPE;
    m->eventos[m->qtd] = E;
    m->qtd++;
    m->eventos = (tEvento**)realloc(m->eventos,sizeof(tEvento*)*(m->qtd+1));
}

/// @brief Função que inicia o "loop de escuta" do monitorador. Ver especificação do EA para mais detalhes
/// @param amb - Ponteiro para o ambiente
/// @param m - Ponteiro para o monitorador de eventos
void iniciaMonitoramentotMonitorador(tAmbiente *amb, tMonitorador *m)
{

    int flag = 1;

    int ev_on = 0;
    char c;
    while (flag)
    {

        flag = 0;

        scanf("%c\n", &c);

        for (int i = 0; i < m->qtd; i++)
        {

            if (m->eventos[i]->ident(m->eventos[i]->evento, c))
            {

                m->eventos[i]->processa(amb, m->eventos[i]->evento, c);
                flag = 1;
            }
        }
        if (!flag)
        {

            return;
        }
    }
}