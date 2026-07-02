#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"

int main()
{

    int n = 0;
    char tipo;
    int p;
    float n1, n2;
    char S[70];
    char lixo[80];

    printf("Digite o numero de tarefas: \n");

    scanf("%d\n", &n);

    tAgendaTarefas *a = CriaAgendaDeTarefas(n);

    for (int i = 0; i < n; i++)
    {

        scanf(" %d", &p);
        scanf(" %c", &tipo);

        while (1)
        {

            if (tipo == 'M' || tipo == 'S' || tipo == 'I')
            {

                break;
            }
            printf("Digite um tipo de tarefa suportado (I/S/M))\n");
            scanf("%[^\n]\n", lixo);
            scanf(" %d", &p);
            scanf(" %c", &tipo);
        }

        switch (tipo)
        {

        case 'I':

            scanf("%[^\n]\n", S);
            tImpr *i = CriaTarefaImprimir(S);
            CadastraTarefaNaAgenda(a, p, i, ExecutaTarefaImprimir, DestroiTarefaImprimir);
            break;

        case 'M':

            scanf("%f %f\n", &n1, &n2);
            tMult *m = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(a, p, m, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
            break;

        case 'S':

            scanf("%f %f\n", &n1, &n2);

            tSoma *s = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(a, p, s, ExecutaTarefaSoma, DestroiTarefaSoma);

            break;

        default:
            break;
        }
    }

    ExecutarTarefasDaAgenda(a);
    DestroiAgendaDeTarefas(a);

    return 0;
}