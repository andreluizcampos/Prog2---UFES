#ifndef _TMONITORADOR
#define _TMONITORADOR

#include "tAmbiente.h"

/*
Definição dos 3 tipos de callbacks necessários para o funcionamento do monitorador
*/
typedef void (*FptrProcessaEvento)(tAmbiente* amb, void* eve, char c);
typedef void (*FptrLiberaEvento)(void* e);
typedef int (*FptrIdentificaEvento)(void* ev, char);

typedef struct _tMonitorador tMonitorador;

/// @brief Função que cria uma variável do tipo monitorador de eventos
/// @return Um ponteiro para a variável do tipo monitorador de eventos
tMonitorador* criaMonitorador();

/// @brief Função que libera o monitorador e seus eventos cadastrados.
/// @param m - O monitorador a ser liberado
void liberaMonitorador(tMonitorador* m);

/// @brief Função que adiciona um evento a um monitorador de eventos
/// @param m - Ponteiro para o monitorador de eventos
/// @param e - Ponteiro para o evento a ser cadastrado no monitorados
/// @param funcPE Callback para a função a ser executada quando o evento for identificado ("evento será processado")
/// @param funcId Callback para a função responsável por indicar se a tecla apertada se refere a um dos eventos
///                 cadastrados no monitorador
/// @param funcLE Callback para a função a ser executada quando o evento cadastrado tiver que ser liberado
void adicionaElementoMonitorador(tMonitorador* m, void* e, FptrProcessaEvento funcPE, FptrIdentificaEvento funcId, FptrLiberaEvento funcLE);

/// @brief Função que inicia o "loop de escuta" do monitorador. Ver especificação do EA para mais detalhes
/// @param amb - Ponteiro para o ambiente
/// @param m - Ponteiro para o monitorador de eventos
void iniciaMonitoramentotMonitorador(tAmbiente* amb, tMonitorador* m);

#endif
