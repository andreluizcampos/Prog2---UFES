#include <stdio.h>
#include "franquia.h"
#include "partida.h"
#include "constantes.h"

int main()
{

    char option = 'a';
    char franquia_1[MAX_TIME_NOME], franquia_2[MAX_TIME_NOME];
    char conferencia[MAX_CONF_NOME];
    int placar_casa = 0, placar_fora = 0, i = 0, j = 0;
    tFranquia franquias[MAX_FRANQUIAS];
    tPartida partidas[MAX_PARTIDAS];

    while (1)
    {

        scanf("%c ", &option);

        if (option == 'E')
        {

            break;
        }

        switch (option)
        {

        case 'F':
            scanf("%[^ ] ", franquia_1);
            scanf("%[^\n]\n", conferencia);
            franquias[i++] = lerFranquia(franquia_1, conferencia);
            break;

        case 'P':

            scanf("%[^ ] @ ", franquia_1);
            scanf("%[^ ] ", franquia_2);
            scanf("%d %d\n", &placar_fora, &placar_casa);
            partidas[j++] = lerPartida(franquia_1, franquia_2, placar_fora, placar_casa);
            break;

        default:

            break;
        }
    }

    for (int k = 0; k < j; k++)
    {
        insereDadosPartida(franquias, i, partidas[k]);
    }

    ImprimeDadosFranquia(franquias, i);
    ImprimeDadosConferencia(franquias, i);
}