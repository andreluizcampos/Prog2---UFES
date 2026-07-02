#include <stdio.h>
#include <stdlib.h>
#include "tAmbiente.h"

struct ambiente
{

    int col, lin;
    char matriz[10][10];
};

tAmbiente *criaAmbiente()
{

    tAmbiente *a = (tAmbiente *)malloc(sizeof(tAmbiente));

    a->col = 0;
    a->lin = 0;

    char matriz[10][10] = {
        {'\0', 'o', 't', '\0', '\0', 'g', '\0', '\0', '\0', 'o'},
        {'o', '\0', 'o', 'g', '\0', '\0', '\0', 't', 't', '\0'},
        {'-', '|', 'g', 'g', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'t', '\0', '\0', 'g', '\0', '\0', '\0', '\0', '\0', 'g'},
        {'g', 'o', '\0', '-', 'o', '\0', '\0', '\0', '-', 't'},
        {'o', '|', 'g', '\0', '\0', '\0', '\0', '\0', '|', 'o'},
        {'|', 'g', 'g', '|', 't', 't', 'o', 'g', '\0', 'g'},
        {'t', '\0', 'o', 'g', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'t', 'g', '\0', 'g', '\0', '\0', '\0', '|', '-', 'o'},
        {'-', '\0', '\0', '\0', '\0', '-', '-', 't', '\0', '\0'},
    };

    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {

            a->matriz[i][j] = matriz[i][j];
        }
    }

    return a;
}

/// @brief Libera a memória alocada para esse ambiente
/// @param amb
void liberaAmbiente(tAmbiente *amb)
{

    free(amb);
}

/// @brief Funcao que consulta o que tem em determinada posicao do mapa
/// @param linha da matriz que voce quer consultar
/// @param coluna da matriz que voce quer consultar
/// @return Retorna o "estado" da posição (linha,coluna) do mapa, conforme especificação:
///         '-' ou '|', representando paredes
///         0 (ou '\0'), representando um local sem obstáculos/estrada
///         um caractere diferente dos listados acima, representando um inimigo.
char retornaSituacaoPosicao(tAmbiente *amb, int linha, int coluna)
{

    return amb->matriz[linha][coluna];
}

/// @brief Funcao que copia a posicao atual para os endereços passados como parametros
/// @param amb - variável que controle o ambiente
/// @param *linha - Ponteiro para uma variável que irá receber a linha que o jogador está posicionado
/// @param *coluna - Ponteiro para uma variável que irá receber a coluna que o jogador está posicionado
void retornaPosicaoAtual(tAmbiente *amb, int *linha, int *coluna)
{

    *linha = amb->lin;
    *coluna = amb->col;
}

/// @brief Funcao que altera o conteúdo do mapa.
/// @param amb - variável que controle o ambiente
/// @param linha da matriz que representa o mapa
/// @param coluna da matriz que representa o mapa
/// @param novoConteudo - conteúdo que substituirá o conteúdo atual daquela posicao
void alteraConteudo(tAmbiente *amb, int linha, int coluna, char novoConteudo)
{

    amb->matriz[linha][coluna] = novoConteudo;
}

/// @brief Funcao que altera a posicao do jogador no mapa. O jogador passará a estar na posição (linha,coluna)
/// após essa funcao ser chamada.
/// @param amb - variável que controle o ambiente
/// @param linha - Nova posição do jogador no mapa
/// @param coluna  - Nova posição do jogador no mapa
void alteraPosicaoJogador(tAmbiente *amb, int linha, int coluna)
{
    amb->lin = linha;
    amb->col = coluna;
}
