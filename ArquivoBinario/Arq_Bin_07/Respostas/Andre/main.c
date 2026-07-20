#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "aluno.h"
#include "professor.h"
#include "database.h"



int main()
{
    int b_lidos = 0;
    int b_carregados = 0;
    tDatabase *d = CriaDatabase();
    LeDatabase(d);
    char name[50];
    scanf(" %[^\n]", name);
    FILE *f = fopen(name, "wb");
    b_lidos = SalvarDatabase(d, f);
    fclose(f);
    DestroiDatabase(d);
    d = CriaDatabase();
    f =fopen(name, "rb");
    b_carregados = CarregaDatabase(d, f);
    fclose(f);
    printf("Numero de bytes salvos: %d\n", b_carregados);
    printf("Numero de bytes lidos: %d\n\n", b_lidos);
    OrdenaDatabase(d);
    ImprimeDatabase(d);
    DestroiDatabase(d);
    return 0;
}