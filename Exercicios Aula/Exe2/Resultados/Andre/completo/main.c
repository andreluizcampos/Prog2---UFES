#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "servidor.h"
#include "bracket.h"
#include "jogador.h"

int main()
{

    tServidor *s = leBracketsServidor();
    criaRelatorioServidor(s);
    liberaServidor(s);

}