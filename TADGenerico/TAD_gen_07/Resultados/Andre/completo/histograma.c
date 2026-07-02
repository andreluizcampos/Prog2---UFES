#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"
#include "imagem.h"

struct tHistograma
{

    int bsize;
    int n;
    Imagem *i;
    int *intevalos;
};
/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos)
{

    Histograma *h = (Histograma *)malloc(sizeof(Histograma));
    h->n = nIntervalos;
    h->bsize = (256 / nIntervalos);

    h->intevalos = calloc(nIntervalos, sizeof(float));

    if (256 % nIntervalos != 0)
    {

        h->bsize++;
    }

    if (ObterTipoImagem(img) == INT)
    {

        int *e = (int *)ObterDadosImagem(img);

        for (int i = 0; i < ObterAltura(img) * ObterLargura(img); i++)
        {
            int k = e[i] / h->bsize;
            h->intevalos[k]++;
        }
    }

    if (ObterTipoImagem(img) == FLOAT)
    {

        float *f = (float *)ObterDadosImagem(img);

        for (int i = 0; i < ObterAltura(img) * ObterLargura(img); i++)
        {
            int k = (f[i] * 255) / h->bsize;
            h->intevalos[k]++;
        }
    }

    return h;
}

/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma)
{

    for (int i = 0; i < histograma->n; i++)
    {

        printf("[%d, %d): %d\n", (i * histograma->bsize), (histograma->bsize + i * histograma->bsize), histograma->intevalos[i]);
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma)
{

    free(histograma->intevalos);
    free(histograma);
}
