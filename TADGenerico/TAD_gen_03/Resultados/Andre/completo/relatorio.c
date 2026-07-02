#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "relatorio.h"
#include "aluno.h"

void ImprimeRelatorio(Vector *alunos)
{

    float media = 0, aprovados = 0, m = 0, f = 0, o = 0;

    for (int i = 0; i < VectorSize(alunos); i++)
    {
        if (GetGeneroAluno(VectorGet(alunos, i)) == 'M')
        {

            m++;
        }

        if (GetGeneroAluno(VectorGet(alunos, i)) == 'O')
        {

            o++;
        }

        if (GetGeneroAluno(VectorGet(alunos, i)) == 'F')
        {

            f++;
        }

        media += GetNotaAluno(VectorGet(alunos, i));

        if (GetNotaAluno(VectorGet(alunos, i)) >= 6.0)
        {

            aprovados++;
        }
    }

    printf("Media das notas: %.2f\n", media / VectorSize(alunos));
    printf("Porcentagem de alunos aprovados: %.2f%\n", (float)aprovados / (float)VectorSize(alunos)*100);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%\n", (m / ((float) VectorSize(alunos)) * 100));
    printf("Feminino: %.2f%\n", (f / (float)VectorSize(alunos)) * 100);
    printf("Outro: %.2f%\n", (o / (float)VectorSize(alunos)) * 100);
}
