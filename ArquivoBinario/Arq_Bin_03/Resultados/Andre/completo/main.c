#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"

int main()
{

    char str[40];
    scanf("%s\n", str);

    Imagem *i = LerImagem(str);
    printf("Numero de bytes lidos: %d\n", ObterNumeroBytesLidos(i));
    ImprimirImagem(i);
    DestruirImagem(i);

    return 0;
}