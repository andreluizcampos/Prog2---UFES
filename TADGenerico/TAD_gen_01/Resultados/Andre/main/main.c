#include <stdio.h>
#include <string.h>
#include "tadgen.h"

int main()
{

    
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: \n");
    int n = 0, type = 0;

    scanf("%d %d\n", &type, &n);

    tGeneric *g = CriaGenerico(type, n);
    LeGenerico(g);
    ImprimeGenerico(g);

    DestroiGenerico(g);

}
