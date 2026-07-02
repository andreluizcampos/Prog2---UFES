#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "histograma.h"

int main()
{

    int n = 0;

    scanf("%d\n", &n);

    int a, l, t;

   Imagem *i = LerImagem();
    Histograma *h = CalcularHistograma(i, n);
    MostrarHistograma(h);
    DestruirHistograma(h);
    DestruirImagem(i);

    return 0;
    
}