#include <stdio.h>
#include <stdlib.h>
#include "media.h"
#include "list.h"

struct List
{

    Media **medias;
    int qtd_medias;
    int medias_inseridas;
};

/**
 * @brief Constrói e inicializa uma nova lista vazia.
 * @return Ponteiro para a estrutura List instanciada.
 */
List *list_construct()
{
    List *l = (List *)malloc(sizeof(List));
    l->medias = (Media **)malloc(sizeof(Media *) * 5);
    l->qtd_medias = 5;
    l->medias_inseridas = 0;
    return l;
}

/**
 * @brief Insere um novo item genérico na lista.
 * Se o limite máximo da lista for atingido, a função gerenciará a inserção adequadamente baseada na implementação interna.
 * @param r Ponteiro para a lista onde o dado será inserido.
 * @param data Ponteiro genérico contendo a mídia específica.
 * @param print_fn Função utilizada para imprimir o dado inserido.
 * @param free_fn Função utilizada para desalocar o dado inserido.
 */
void list_media_insert(List *r, void *data, PrintFunction print_fn, FreeFunction free_fn)
{

    if (r->medias_inseridas < 5)
    {

        r->medias[r->medias_inseridas] = media_construct(data, print_fn, free_fn);
        r->medias_inseridas++;
    }

    else
    {

        r->medias = (Media **)realloc(r->medias, (r->medias_inseridas + 1) * sizeof(Media *));
        r->medias[r->medias_inseridas] = media_construct(data, print_fn, free_fn);
        r->medias_inseridas++;
    }
}

/**
 * @brief Percorre a lista iterativamente e chama a impressão de todos os seus elementos formatados.
 * @param r Ponteiro para a estrutura List a ser impressa.
 */
void list_print(List *r)
{

    if (r->medias_inseridas == 0)
    {

        printf("SEM MIDIAS PARA IMPRIMIR\n");
    }

    if (r->medias_inseridas > 0)
    {
        printf("IMPRIMINDO MIDIAS FAVORITAS\n\n");
    }

    int i = 0;

    for (i = 0; i < r->medias_inseridas; i++)
    {
        printf("MIDIA %d: ", i + 1);
        media_print(r->medias[i]);
    }
}

/**
 * @brief Libera a memória de toda a lista e aciona o destrutor de todos os elementos armazenados nela.
 * @param r Ponteiro para a estrutura List a ser destruída.
 */
void list_free(List *r)
{

    for (int i = 0; i < r->medias_inseridas; i++)
    {

        media_free(r->medias[i]);
    }
    free(r->medias);
    free(r);
}