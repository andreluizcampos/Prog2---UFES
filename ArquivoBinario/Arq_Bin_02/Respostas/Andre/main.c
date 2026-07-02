#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base_alunos.h"
#include "aluno.h"

int main()
{

    tBaseAlunos *b = CriarBaseAlunos();

    char *path;

    scanf("%ms", &path);
    LerBaseAlunos(b, path);

    printf("Coeficiente de Rendimento Medio da base de alunos: ");
    printf("%.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(b));

    free(path);
    DestruirBaseAlunos(b);

    return 0;
}