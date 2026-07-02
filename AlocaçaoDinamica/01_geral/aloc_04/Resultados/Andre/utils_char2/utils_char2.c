#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils_char2.h"

char *CriaVetorTamPadrao()
{

    char *vetor;
    vetor = malloc(sizeof(char) * (TAM_PADRAO +1));

    for (int i = 0; i < TAM_PADRAO; i++)
    {
        vetor[i] = '_';
    }

    vetor[TAM_PADRAO] = '\0';

    return vetor;
}

/**
 * Aumenta o tamanho de um vetor alocado dinamicamente
 * O vetor deve ser aumentado para conseguir alocar mais "TAM_PADRAO" caracteres (o vetor só pode ter tamanhos múltiplos de "TAM_PADRAO")
 * Preencha as novas posições com "_", e lembre-se que a última deve conter '\0'.
 *
 * @param tamanhoantigo Tamanho do vetor a ser modificado
 * @return Ponteiro para o novo vetor.
 */
char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo)
{

    int tam_atual = tamanhoantigo + TAM_PADRAO;

    char *novo = realloc(vetor, sizeof(char) * (tam_atual + 1));

    for (int i = tamanhoantigo; i < tam_atual; i++)
    {

        novo[i] = '_';
    }

    novo[tam_atual] = '\0';

    return novo;
}

/**
 * Lê uma string do tamanho especificado até um enter ser apertado.
 * Caso seja necessário alterar o tamanho do vetor, o tamanho deve ser atualizado para que o programa
 * saiba o novo tamanho do vetor.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho* Ponteiro para uma variável do tipo inteiro que armazena o tamanho atual do vetor.
 * @return Um ponteiro para o vetor lido.
 */

char *LeVetor(char *vetor, int *tamanho)
{

    int i = 0, tam_c = *tamanho;
    char copy;

    while (1)
    {
        scanf("%c", &copy);

        if (copy == '\n')
        {

            break;
        }

        if (i == *tamanho - 1)
        {

            if (vetor == NULL)
            {
                return NULL;
            }
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }

        vetor[i] = copy;
        i++;
    }

    return vetor;
}

/**
 * Imprime a string
 *
 * @param vetor Ponteiro para o vetor a ser imprimido.
 */
void ImprimeString(char *vetor)
{

    printf("%s", vetor);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 *
 * @param vetor Ponteiro para o vetor a ser liberado.
 */
void LiberaVetor(char *vetor)
{

    free(vetor);
}