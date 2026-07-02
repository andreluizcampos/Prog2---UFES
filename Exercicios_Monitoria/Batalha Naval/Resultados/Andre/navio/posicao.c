#include "posicao.h"

/*
 * posicao_criar
 * Cria e retorna uma Posicao com os valores fornecidos.
 * Pre-condicao : linha >= 0 e coluna >= 0
 * Pos-condicao : posicao retornada contem os valores fornecidos
 */
Posicao posicao_criar(int linha, int coluna)
{
    Posicao p;
    p.linha = linha;
    p.coluna = coluna;
    return p;
}

/*
 * posicao_linha
 * Retorna a linha da posicao.
 */
int posicao_linha(Posicao p)
{
    return p.linha;
}

/*
 * posicao_coluna
 * Retorna a coluna da posicao.
 */
int posicao_coluna(Posicao p)
{
    return p.coluna;
}

/*
 * posicao_igual
 * Retorna 1 se as duas posicoes sao iguais, 0 caso contrario.
 */
int posicao_igual(Posicao a, Posicao b)
{
    return a.linha == b.linha && a.coluna == b.coluna;
}

/*
 * posicao_valida
 * Retorna 1 se linha e coluna estao dentro de [0, tamanho-1].
 * Pre-condicao : tamanho > 0
 */
int posicao_valida(Posicao p, int tamanho)
{
    return p.linha >= 0 && p.linha < tamanho &&
           p.coluna >= 0 && p.coluna < tamanho;
}