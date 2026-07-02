#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "vector.h"
#include "relatorio.h"

int main()
{

    Vector *v = VectorConstruct();

    int qtd;

    scanf("%d\n", &qtd);

    for (int i = 0; i < qtd; i++)
    {

        tAluno *a = CriaAluno();
        LeAluno(a);
        VectorPushBack(v, a);
    }

    ImprimeRelatorio(v);

    VectorDestroy(v, DestroiAluno);

    return 0;
}