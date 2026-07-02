#include <stdio.h>
#include "equipe.h"
#include <stdlib.h>
#include <string.h>
#include "jogador.h"

/// @brief Função que copia o conteúdo de um nome de uma equipe para uma nova variável
/// @param e - a equipe que terá seu nome copiado
/// @param dst - o vetor "externo" que receberá o valor copiado
void tEquipe_copiaNome(tEquipe e, char dst[])
{

    strcpy(dst, e.nome);
}

/// @brief Funções getter - retorna um campo da estrutura
/// @param e - uma variável que armazena uma equipe
/// @return O id da equipe do jogador
int tEquipe_getNumeroJogadores(tEquipe e)
{

    return e.nJogadores;
}
int tEquipe_getNumeroVitorias(tEquipe e)
{

    return e.nVitorias;
}
int tEquipe_getNumeroDerrotas(tEquipe e)
{

    return e.nDerrotas;
}
int tEquipe_getNumeroEmpates(tEquipe e)
{

    return e.nEmpates;
}
int tEquipe_getIdUnico(tEquipe e)
{

    return e.idUnico;
}
int tEquipe_getNumeroGolsPro(tEquipe e)
{

    return e.nGolsPro;
}
int tEquipe_getNumeroGolsContra(tEquipe e)
{

    return e.nGolsContra;
}

/// @brief Funções getter - retorna um cálculo com base nos valores dos campos da estrutura
/// @param e - uma variável que armazena uma equipe
/// @return O id da equipe do jogador
int tEquipe_getNumPontos(tEquipe e)
{

    return tEquipe_getNumeroEmpates(e) + tEquipe_getNumeroVitorias(e) * 3;
}

int tEquipe_getNumJogos(tEquipe e)
{

    return tEquipe_getNumeroEmpates(e) + tEquipe_getNumeroDerrotas(e) + tEquipe_getNumeroVitorias(e);
}
int tEquipe_getSaldogols(tEquipe e)
{

    return tEquipe_getNumeroGolsPro(e) - tEquipe_getNumeroGolsContra(e);
}

/// @brief  Função que retorna a quantidade de gols feitos
///         Repare que os gols são "armazenados" nas variáveis idGols e nGolsPro.
///         "idGols" armazena os ids dos jogadores que fizeram os gols daquele time;
/// @param e - uma equipe
/// @param idJogador - um id de jogador
/// @return o número de gols que aquele jogador fez
int tEquipe_getQtdeGolsJogador(tEquipe e, int idJogador)
{

    for (int i = 0; i < MAX_GOLS_EQUIPE; i++)
    {

        if (idJogador - 1 == i)
        {

            return e.idGols[i];
        }
    }
}

/// @brief Funções de incrementar (somar 1) uma variável específica (olhar título da função)
/// @param e - uma variável que armazena uma equipe
/// @return A variável com os campos atualizados
tEquipe tEquipe_incrementaVitorias(tEquipe e)
{

    e.nVitorias++;

    return e;
}
tEquipe tEquipe_incrementaDerrotas(tEquipe e)
{

    e.nDerrotas++;
    return e;
}
tEquipe tEquipe_incrementaEmpates(tEquipe e)
{

    e.nEmpates++;

    return e;
}
tEquipe tEquipe_incrementaNumeroJogadores(tEquipe e)
{

    e.nJogadores++;
    return e;
}

/// @brief  Adiciona "um gol" aos gols de uma equipe. Na verdade, armazena o id do jogador que fez um gol
///         pelo time (gol pró) no vetor correspondente.
///         Não esqueça de somar a variável que controla a quantidade de gols
/// @param e - uma variável que armazena uma equipe
/// @param idJogador - id do jogador que fez o gol pelo time
/// @return A variável com os campos atualizados
tEquipe tEquipe_adicionaGolPro(tEquipe e, int idJogador)
{

    e.nGolsPro++;

    e.idGols[idJogador - 1]++;

    return e;
}

/// @brief Adiciona um número de gols contra em uma equipe
///         Ao contrário dos gols pro, não é necessário armazenar quem fez os gols;
///         Apenas a quantidade
/// @param e - uma variável que armazena uma equipe
/// @param nGols - número de gols contra que o time sofreu
/// @return A variável com os campos atualizados
tEquipe tEquipe_adicionaGolsContra(tEquipe e, int nGols)
{

    e.nGolsContra += nGols;

    return e;
}

/// @brief Função que lê os dados de um jogador (scanf)
///         E retorna a variável inicializada e preenchida.
/// @return
tEquipe leEquipe()
{

    tEquipe e;

    for (int i = 0; i < MAX_GOLS_EQUIPE; i++)
    {

        e.idGols[i] = 0;
    }

    e.nDerrotas = e.nGolsContra = e.nVitorias = e.nEmpates = e.nGolsPro = e.nJogadores = 0;

    scanf("%d %[^\n]\n", &e.idUnico, e.nome);

    return e;
}
