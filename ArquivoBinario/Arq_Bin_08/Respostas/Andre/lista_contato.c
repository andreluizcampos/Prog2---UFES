#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "vector.h"
#include "lista_contato.h"

struct ListaContato
{
    Vector *v;
    int n;
};

/**
 * @brief Cria uma lista de contatos.
 *
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
 */
tListaContato *CriarListaContato()
{

    tListaContato *l = (tListaContato *)malloc(sizeof(tListaContato));

    l->v = VectorConstruct();
    l->n = 0;

    return l;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 *
 * @param l Ponteiro para a lista de contatos a ser liberada.
 */
void DestruirListaContato(tListaContato *l)
{

    VectorDestroy(l->v, DestruirContato);

    free(l);
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 *
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
 */
void AdicionarContatoListaContato(tListaContato *l, tContato *contato)
{

    int cond1 = 0;
    int cond2 = 0;
    int catch = 0;
    for (int i = 0; i < l->n; i++)
    {

        tContato *c = (tContato *)VectorGet(l->v, i);

        cond1 = ComparaTelefoneContato(c, contato);
        cond2 = ComparaNomeContato(c, contato);

        if (cond1 || cond2)
        {

            catch = 1;
        }
    }

    if (catch)
    {

        DestruirContato(contato);
        printf("\nJa existe um contato com esse nome e/ou numero de telefone\n");
    }
    else
    {

        VectorPushBack(l->v, contato);
        l->n++;
    }
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 *
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 *
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
 */
void CarregarListaContato(tListaContato *l, char *nomeArquivo)
{

    FILE *f = fopen(nomeArquivo, "rb");

    if (f != NULL)
    {
        fread(&l->n, 4, 1, f);

        for (int i = 0; i < l->n; i++)
        {
            tContato *c = CarregarContato(f);
            VectorPushBack(l->v, c);
        }

        fclose(f);
    }
}
/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 *
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 *
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
 */
void SalvarListaContato(tListaContato *l, char *nomeArquivo)
{

    FILE *f = fopen(nomeArquivo, "wb");

    fwrite(&l->n, 4, 1, f);

    for (int i = 0; i < l->n; i++)
    {
        tContato *c = (tContato *)VectorGet(l->v, i);

        SalvarContato(c, f);
    }

    fclose(f);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 *
 * @param l Ponteiro para a lista de contatos.
 */
void BuscarPorNumeroTelefoneListaContato(tListaContato *l)
{

    unsigned long int d;
    scanf(" %ld", &d);

    int flag = 0;

    for (int i = 0; i < l->n; i++)
    {

        tContato *c = (tContato *)VectorGet(l->v, i);

        unsigned long int n = GetTelefoneContato(c);

        if (d == n)
        {

            flag = 1;

            ImprimirContato(c);
            break;
        }
    }

    if (!flag)
    {

        printf("\nContato nao encontrado\n");

        return;
    }
}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 *
 * @param l Ponteiro para a lista de contatos.
 */
void BuscarPorNomeListaContato(tListaContato *l)
{

    char Nome[50];
    unsigned long int d;
    scanf(" %[^\n]", Nome);

    int flag = 0;

    for (int i = 0; i < l->n; i++)
    {

        tContato *c = (tContato *)VectorGet(l->v, i);

        char *N = GetNomeContato(c);

        if (strcmp(Nome, N) == 0)
        {

            flag = 1;
            ImprimirContato(c);
            break;
        }
    }

    if (!flag)
    {

        printf("Contato nao encontrado\n");

        return;
    }
}

/**
 * @brief Imprime a lista de contatos na tela.
 *
 * @param l Ponteiro para a lista de contatos.
 */
void ImprimirListaContato(tListaContato *l)
{

    printf("\nLista de contatos cadastrados\n");

    for (int i = 0; i < l->n; i++)
    {

        tContato *c = (tContato *)VectorGet(l->v, i);

        ImprimirContato(c);
    }
}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 *
 * @param l Ponteiro para a lista de contatos.
 */
void RemoverContatoListaContato(tListaContato *l)
{

    unsigned long int n;
    int flag = 0;
    scanf(" %lu", &n);

    for (int i = 0; i < l->n; i++)
    {

        tContato *c = (tContato *)VectorGet(l->v, i);

        unsigned long int N = GetTelefoneContato(c);

        if (n == N)
        {
            DestruirContato(c);
            VectorRemove(l->v, i);
            flag = 1;
            printf("\nContato removido com sucesso\n");
            l->n--;
            return;
        }
    }

    if (!flag)
    {

        printf("\nNao existe um contato cadastrado com esse numero de telefone\n");

        return;
    }
}
