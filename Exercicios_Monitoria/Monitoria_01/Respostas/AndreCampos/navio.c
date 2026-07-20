#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "navio.h"

/* ------------------------------------------------------------------ */
/* Definicao do tipo                                                   */
/* ------------------------------------------------------------------ */

/*typedef struct {
    char nome[NAVIO_MAX_NOME];
    int  tamanho;
    int  partes_atingidas[NAVIO_MAX_TAMANHO];
} Navio;*/

/* ------------------------------------------------------------------ */
/* Operacoes                                                           */
/* ------------------------------------------------------------------ */

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
    Navio n;
    strcpy(n.nome, nome);
    n.tamanho = tamanho;
    for (int i = 0; i < n.tamanho; i++)
    {
        n.partes_atingidas[i] = 0;
    }
    return n;
}

/*
 * navio_atingir
 * Marca a parte indicada pelo indice como atingida (1).
 * Pre-condicao : n != NULL, 0 <= parte < n->tamanho
 *                a parte ainda nao foi atingida
 */
void navio_atingir(Navio *n, int parte)
{
    if (n != NULL && 0 <= parte && parte < n->tamanho)
    {
        n->partes_atingidas[parte] = 1;
    }
}

/*
 * navio_afundado
 * Retorna 1 se todas as partes foram atingidas, 0 caso contrario.

 */
int navio_afundado(const Navio n)
{
    for (int i = 0; i < n.tamanho; i++)
    {
        if (n.partes_atingidas[i] == 0)
        {
            return 0;
        }
    }
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
