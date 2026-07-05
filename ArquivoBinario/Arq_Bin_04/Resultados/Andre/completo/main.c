#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "histograma.h"
#include "imagem.h"

int main()
{

    char *nome;
    scanf("%ms", &nome);

    Imagem *i = LerImagem(nome);
    free(nome);
    int n;
    scanf(" %d", &n);

    Histograma *h = CalcularHistograma(i, n);
    MostrarHistograma(h);
    DestruirImagem(i);
    DestruirHistograma(h);

    return 0;
}