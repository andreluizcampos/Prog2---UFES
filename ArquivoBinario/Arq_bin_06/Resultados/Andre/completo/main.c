#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "estabelecimento.h"
#include "produto.h"

int main()
{

    tEstabelecimento *e = CriaEstabelecimento();
    LeEstabelecimento(e);
    ImprimeRelatorioEstabelecimento(e);
    DestroiEstabelecimento(e);
}