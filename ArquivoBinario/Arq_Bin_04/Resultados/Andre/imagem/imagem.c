#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"

struct tImagem
{
    int col, lin;
    int tipo;
    void *matriz;
    int b_lidos;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho)
{

    Imagem *i = (Imagem *)malloc(sizeof(Imagem));
    i->b_lidos = 0;
    FILE *f = fopen(caminho, "rb");

    i->b_lidos += fread(&i->lin, sizeof(int), 1, f);
    i->b_lidos += fread(&i->col, sizeof(int), 1, f);
    i->b_lidos += fread(&i->tipo, sizeof(int), 1, f);
    if (i->tipo == INT)
    {
        i->matriz = (int *)malloc(sizeof(int) * i->lin * i->col);
        i->b_lidos += fread(i->matriz, sizeof(int), i->col * i->lin, f);
    }
    else
    {

        i->matriz = (float *)malloc(sizeof(float) * i->lin * i->col);
        i->b_lidos += fread(i->matriz, sizeof(float), i->col * i->lin, f);
    }

    fclose(f);
    return i;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img)
{

    free(img->matriz);
    free(img);
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */

int ObterAlturaImagem(Imagem *img)
{

    return img->lin;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img)
{

    return img->col;
}

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{

    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{

    return img->matriz;
}
