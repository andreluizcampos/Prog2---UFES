#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"
#include "histograma.h"

#define b_size 256

struct tHistograma
{
    int *buckets;
    int n_intervalos;
};

/**
 * @brief Função para calcular um histograma a partir de uma imagem.
 * @param image A imagem para calcular o histograma.
 * @param n_buckets O número de intervalos no histograma.
 * @return Um ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos)
{
    Histograma *h = (Histograma *)malloc(sizeof(Histograma));
    h->n_intervalos = nIntervalos;

    int t_intervalo = b_size / nIntervalos;

    if (b_size % nIntervalos != 0)
    {

        t_intervalo++;
    }

    h->buckets = calloc(nIntervalos, sizeof(int));

    int col_img = ObterLarguraImagem(img);
    int lin_img = ObterAlturaImagem(img);
    int tipo = ObterTipoImagem(img);
    int pos = 0;

    if (tipo == INT)
    {

        int *I = ((int *)ObterDadosImagem(img));

        for (int i = 0; i < col_img * lin_img; i++)
        {

            pos = I[i] / t_intervalo;
            h->buckets[pos]++;
        }
    }

    else
    {

        float *f = ((float *)ObterDadosImagem(img));

        for (int i = 0; i < col_img * lin_img; i++)
        {

            pos = f[i] * 255 / t_intervalo;
            h->buckets[pos]++;
        }
    }

    return h;
}

/**
 * @brief Função para exibir um histograma na tela.
 * @param histogram O histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma)
{

    int t_intervalo = b_size / histograma->n_intervalos;
    if (b_size % histograma->n_intervalos != 0)
    {

        t_intervalo++;
    }

    for (int i = 0; i < histograma->n_intervalos; i++)
    {

        printf("[%d, %d): %d\n", i * t_intervalo, (t_intervalo * (i + 1)), histograma->buckets[i]);
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histogram O histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma)
{

    free(histograma->buckets);
    free(histograma);
}
