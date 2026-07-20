#include "navio.h"
#include <string.h>

/*
 * navio_criar
 * Preenche a estrutura com o nome e tamanho fornecidos.
 * Todas as partes comecam intactas (0).
 * Pre-condicao :  tamanho entre 1 e NAVIO_MAX_TAMANHO
 *                nome != NULL e cabe em NAVIO_MAX_NOME (com '\0')
 * Pos-condicao : todas as partes estao em 0 apos a criacao
 */
Navio navio_criar(const char *nome, int tamanho)
{
    Navio navio;
    if (nome == NULL)
    {
        navio.nome[0] = '\0';
    }
    else
    {
        strncpy(navio.nome, nome, NAVIO_MAX_NOME - 1);
        navio.nome[NAVIO_MAX_NOME - 1] = '\0';
    }
    navio.tamanho = tamanho;
    for (int i = 0; i < tamanho; i++)
        navio.partes_atingidas[i] = 0;
    return navio;
}

/*
 * navio_atingir
 * Marca a parte indicada pelo indice como atingida (1).
 * Pre-condicao : n != NULL, 0 <= parte < n->tamanho
 *                a parte ainda nao foi atingida
 */
void navio_atingir(Navio *n, int parte)
{
    n->partes_atingidas[parte] = 1;
}

/*
 * navio_afundado
 * Retorna 1 se todas as partes foram atingidas, 0 caso contrario.
 */
int navio_afundado(const Navio n)
{
    for (int i = 0; i < n.tamanho; i++)
        if (n.partes_atingidas[i] == 0)
            return 0;
    return 1;
}

/*
 * navio_nome
 * Retorna um ponteiro para o nome do navio.
 * Pre-condicao : n != NULL
 */
const char *navio_nome(const Navio *n)
{
    return n->nome;
}

/*
 * navio_tamanho
 * Retorna o tamanho (numero de partes) do navio.
 */
int navio_tamanho(const Navio n)
{
    return n.tamanho;
}