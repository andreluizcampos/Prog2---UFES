#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"

int main()
{

    int n = 0, m1, m2, m3;
    scanf("%d\n", &n);
    tDepartamento departamentos[n];
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
    char Departamento[STRING_MAX], Diretor[STRING_MAX];

    for (int i = 0; i < n; i++)
    {

        scanf(" %[^\n]\n", Departamento);
        scanf(" %[^\n]\n", Diretor);
        scanf(" %[^\n]\n", c1);
        scanf(" %[^\n]\n", c2);
        scanf(" %[^\n]\n", c3);
        scanf("%d %d %d\n", &m1, &m2, &m3);

        if (m3 < 0 || m1 < 0 || m2 < 0)
        {
            scanf(" %[^\n]\n", Departamento);
            scanf(" %[^\n]\n", Diretor);
            scanf(" %[^\n]\n", c1);
            scanf(" %[^\n]\n", c2);
            scanf(" %[^\n]\n", c3);
            scanf("%d %d %d\n", &m1, &m2, &m3);
        }

        departamentos[i] = CriaDepartamento(c1, c2, c3, Departamento, m1, m2, m3, Diretor);
    }
    OrdenaDepartamentosPorMedia(departamentos, n);

    for (int i = 0; i < n; i++)
    {
        ImprimeAtributosDepartamento(departamentos[i]);
    }
}