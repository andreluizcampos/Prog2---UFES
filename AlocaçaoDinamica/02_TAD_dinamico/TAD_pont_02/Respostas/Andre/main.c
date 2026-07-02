#include <stdlib.h>
#include <stdio.h>
#include "eleitor.h"
#include <string.h>
#include "candidato.h"
#include "eleicao.h"

int main()
{

    tEleicao *eleicao;
    eleicao = InicializaEleicao();
    RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    ApagaEleicao(eleicao);
    return 0;
}