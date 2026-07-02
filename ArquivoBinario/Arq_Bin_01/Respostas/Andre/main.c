#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main()
{

    int n = 0;
    scanf("%d", &n);

    Aluno **alunos = CriaVetorAlunos(n);
    LeAlunos(alunos, n);
    printf("Digite o numero de alunos: ");
    SalvaAlunosBinario(alunos, "alunos.bin", n);
    LiberaAlunos(alunos, n);
    alunos = CriaVetorAlunos(n);
    CarregaAlunosBinario(alunos, "alunos.bin");
    ImprimeAlunos(alunos, n);
    LiberaAlunos(alunos, n);

    return 0;
}