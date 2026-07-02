#include <stdio.h>
#include <stdlib.h>
#include "departamento.h"
#include <string.h>

int main()
{

    int qtd = 0;
    scanf("%d\n", &qtd);

    tDepartamento **departamentos = malloc(sizeof(tDepartamento*)*qtd);

    char c1[STRING_MAX];
    char c2[STRING_MAX];
    char c3[STRING_MAX];
    char nome[STRING_MAX];
    char diretor[STRING_MAX];

    int m1, m2, m3;

    for (int i = 0; i < qtd; i++)
    {
        departamentos[i] = CriaDepartamento();
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);
        scanf("%[^\n]\n", c1);
        scanf("%[^\n]\n", c2);
        scanf("%[^\n]\n", c3);
        scanf("%d %d %d\n", &m1, &m2, &m3);
        PreencheDadosDepartamento(departamentos[i], c1, c2, c3, nome, m1, m2, m3, diretor);
    }

    OrdenaPorMediaDepartamentos(departamentos, qtd);

    for (int i = 0; i < qtd; i++)
    {

        ImprimeAtributosDepartamento(departamentos[i]);
        LiberaMemoriaDepartamento(departamentos[i]);
    }

   free(departamentos);
}