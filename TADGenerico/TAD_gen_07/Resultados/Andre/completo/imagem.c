#include <stdlib.h>
#include <string.h>
#include "imagem.h"
#include <stdio.h>

struct tImagem
{
    int alt, larg, tipo;
    void *dados;
    int size;
};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img)
{

    return img->alt;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img)
{

    return img->larg;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{

    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{

    return img->dados;
}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo)
{

    Imagem *i = (Imagem *)malloc(sizeof(Imagem));
    i->alt = altura;
    i->larg = largura;
    i->tipo = tipo;
    i->dados = calloc(altura * largura, sizeof(float));

    return i;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem()
{

    int alt, larg, tipo;

    scanf("%d %d %d\n", &alt, &larg, &tipo);

    Imagem *I = CriarImagem(alt, larg, tipo);

    if (I->tipo == INT)
    {
        int *e = ((int *)I->dados);

        for (int i = 0; i < alt; i++)
        {

            for (int j = 0; j < larg; j++)
            {

                scanf("%d", &e[i * larg + j]);
            }
        }
    }

    else
    {

        float *f = ((float *)I->dados);

        for (int i = 0; i < alt; i++)
        {

            for (int j = 0; j < larg; j++)
            {

                scanf("%f", &f[i * larg + j]);
            }
        }
    }
    return I;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img)
{

    for (int i = 0; i < img->alt; i++)
    {

        for (int j = 0; j < img->larg; j++)
        {

            if (img->tipo == INT)
            {

                int *e = ((int *)img->dados);

                printf("%d ", e[img->larg * i + j]);
            }

            if (img->tipo == INT)
            {

                float *f = ((float *)img->dados);

                printf("%.2f ", f[img->larg * i + j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img)
{

    free(img->dados);
    free(img);
}