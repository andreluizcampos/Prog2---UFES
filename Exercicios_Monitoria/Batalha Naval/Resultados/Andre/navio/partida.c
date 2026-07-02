#include "grid.h"

/*
 * grid_criar
 * Inicializa o grid com todas as celulas vazias e sem navios.
 * Pre-condicao : 2 <= tamanho <= GRID_MAX_TAMANHO
 */
Grid grid_criar(int tamanho)
{
    Grid g;

    if (tamanho < 2 || tamanho > GRID_MAX_TAMANHO)
        tamanho = GRID_MAX_TAMANHO;

    g.tamanho = tamanho;
    g.total_navios = 0;

    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
        {
            g.celulas[i][j] = CELULA_VAZIA;
            g.navio_idx[i][j] = -1;
            g.parte_idx[i][j] = -1;
        }

    return g;
}

/*
 * grid_posicionar
 * Posiciona o navio apontado por n a partir de `inicio`.
 * Se horizontal == 1, ocupa colunas consecutivas; caso contrario, linhas.
 * Retorna 1 se posicionado com sucesso, 0 se posicao invalida ou sobreposicao.
 * Pre-condicao : g != NULL, n != NULL
 *                total_navios < GRID_MAX_NAVIOS antes da chamada
 * Pos-condicao : celulas ocupadas ficam com estado CELULA_NAVIO
 */
int grid_posicionar(Grid *g, const Navio *n, Posicao inicio, int horizontal)
{
    int lin = posicao_linha(inicio);
    int col = posicao_coluna(inicio);
    int tam = navio_tamanho(*n);

    for (int k = 0; k < tam; k++)
    {
        int l = lin + (horizontal ? 0 : k);
        int c = col + (horizontal ? k : 0);

        if (!posicao_valida(posicao_criar(l, c), g->tamanho))
            return 0;
        if (g->celulas[l][c] != CELULA_VAZIA)
            return 0;
    }

    int idx = g->total_navios;
    g->navios[idx] = *n;
    g->total_navios++;

    for (int k = 0; k < tam; k++)
    {
        int l = lin + (horizontal ? 0 : k);
        int c = col + (horizontal ? k : 0);

        g->celulas[l][c] = CELULA_NAVIO;
        g->navio_idx[l][c] = idx;
        g->parte_idx[l][c] = k;
    }

    return 1;
}

/*
 * grid_atirar
 * Atira na posicao p.
 * Retorna 1 se acertou um navio, 0 se agua.
 * Pre-condicao : g != NULL
 *                posicao_valida(p, g->tamanho) == 1
 *                celula em p nao esta em CELULA_ATINGIDA nem CELULA_AGUA
 * Pos-condicao : celula em p muda para CELULA_ATINGIDA ou CELULA_AGUA
 *                se acertou, a parte correspondente do navio e marcada
 */
int grid_atirar(Grid *g, Posicao p)
{
    int l = posicao_linha(p);
    int c = posicao_coluna(p);

    if (g->celulas[l][c] == CELULA_NAVIO)
    {
        int ni = g->navio_idx[l][c];
        int pi = g->parte_idx[l][c];
        navio_atingir(&g->navios[ni], pi);
        g->celulas[l][c] = CELULA_ATINGIDA;
        return 1;
    }

    g->celulas[l][c] = CELULA_AGUA;
    return 0;
}

/*
 * grid_celula
 * Retorna o estado da celula na posicao p.
 * Pre-condicao : g != NULL, posicao_valida(p, g->tamanho) == 1
 */
CelulaEstado grid_celula(const Grid g, Posicao p)
{
    return g.celulas[posicao_linha(p)][posicao_coluna(p)];
}

/*
 * grid_todos_afundados
 * Retorna 1 se nao ha mais nenhuma celula com estado CELULA_NAVIO.
 * Pre-condicao : g != NULL
 */
int grid_todos_afundados(const Grid g)
{
    for (int i = 0; i < g.tamanho; i++)
        for (int j = 0; j < g.tamanho; j++)
            if (g.celulas[i][j] == CELULA_NAVIO)
                return 0;
    return 1;
}