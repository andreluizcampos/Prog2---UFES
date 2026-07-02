#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

int main()
{

    int quantidade = 0;

    scanf("%d", &quantidade);

    tAluno alunos[quantidade];

    for (int i = 0; i < quantidade; i++)
    {

        alunos[i] = LeAluno();
    }

    int flag = 1;

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < quantidade - 1; i++)
        {

            if (alunos[i].matricula > alunos[i + 1].matricula)
            {

                tAluno temp = alunos[i];
                alunos[i] = alunos[i + 1];
                alunos[i + 1] = temp;
                flag = 1;
            }
        }
    }

    for (int i = 0; i < quantidade; i++)
    {

        if (VerificaAprovacao(alunos[i]))
        {

            ImprimeAluno(alunos[i]);
        }
    }
}