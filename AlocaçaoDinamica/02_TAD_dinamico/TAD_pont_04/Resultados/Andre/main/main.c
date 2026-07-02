#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main()
{

    tAluno **aluno;

    int qtd = 0;

    int flag = 1;

    scanf("%d\n", &qtd);

    aluno = malloc(qtd * sizeof(*aluno));

    for (int i = 0; i < qtd; i++)
    {

        aluno[i] = CriaAluno();
        LeAluno(aluno[i]);
    }

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < qtd - 1; i++)
        {

            if (ComparaMatricula(aluno[i], aluno[i + 1]) == 1)
            {

                tAluno *temp;
                temp = aluno[i];
                aluno[i] = aluno[i + 1];
                aluno[i + 1] = temp;
                flag = 1;
            }
        }
    }


    for (int i = 0; i < qtd; i++)
    {

        if (VerificaAprovacao(aluno[i]))
        {

            ImprimeAluno(aluno[i]);
        }
        ApagaAluno(aluno[i]);
    }

    free(aluno);
   
    return 0;
}