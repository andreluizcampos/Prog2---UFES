#include <stdio.h>
#include <stdlib.h>
#include "partida.h"
#include "franquia.h"

/**
 * @brief Lê uma partida do teclado.
 *
 * @return tPartida Retorna um ponteiro para a partida lida.
 */

struct partida
{

    char *timecasa;
    char *timefora;

    int pt_c;
    int pt_f;
};

tPartida LePartida()
{

    tPartida p = malloc(sizeof(struct partida));

    p->timecasa = malloc((MAX_NOME + 1) * sizeof(*p->timecasa));

    p->timefora = malloc((MAX_NOME + 1) * sizeof(*p->timefora));

    p->pt_c = 0;
    p->pt_f = 0;

    scanf("%s @ %s", p->timecasa, p->timefora);
    scanf("%d %d ",&p->pt_c, &p->pt_f);

    return p;
}

/**
 * @brief Libera a memória alocada para uma partida.
 *
 * @param p Ponteiro para a partida a ser liberada.
 */
void LiberaPartida(tPartida p)
{

    free(p->timecasa);
    free(p->timefora);

    free(p);
}

/**
 * @brief Imprime as informações de uma partida.
 *
 * @param p Ponteiro para a partida a ser impressa.
 */
void ImprimePartida(tPartida p)
{

    // NULL
}

/**
 * @brief Retorna o nome do time da casa.
 *
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time da casa.
 */
char *GetTime1Partida(tPartida p){

    return p->timecasa;
}

/**
 * @brief Retorna o nome do time visitante.
 *
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time visitante.
 */
char *GetTime2Partida(tPartida p){

    return p->timefora;
}

/**
 * @brief Retorna o vencedor da partida.
 *
 * @param p Ponteiro para a partida.
 * @return int Retorna a constante que representa o vencedor da partida (TIME_CASA ou TIME_FORA).
 */
int GetVencedorPartida(tPartida p){

        return p->pt_c > p->pt_f;

}
