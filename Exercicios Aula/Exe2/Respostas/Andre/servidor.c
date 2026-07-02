#include "servidor.h"
#include "bracket.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Servidor
{

    int qtd;
    tBracket **b;
};
/*
Função que lê todos os registros de brackets de um servidor a partir da entrada padrão e retorna um servidor
com todos os registros de brackets lidos. Conforme a especificação da atividade, a leitura é encerrada quando
um ID de bracket igual a -1 é lido.

@return *tServidor: Ponteiro de servidor com todos os registros de brackets lidos
*/
tServidor *leBracketsServidor()
{

    tServidor *s = (tServidor *)malloc(sizeof(tServidor));
    s->b = (tBracket **)malloc(sizeof(tBracket *));
    s->qtd = 0;

    int b_id = 0;

    while (1)
    {

        scanf("%d\n", &b_id);

        if (b_id == -1)
        {

            break;
        }

        s->b[s->qtd] = leBracket(b_id);
        s->qtd++;
        s->b = realloc(s->b, (s->qtd + 1) * sizeof(tBracket *));
    }

    return s;
}

/*
Função que recebe um servidor já preenchido com os dados de todas as brackets e um ID de jogador.
A partir dessas informações, ela busca as estatísticas do jogador em todas as brackets que ele participou.
Se o jogar não for encontrado, um jogador com ID -1 é criado e retornado.
Se o jogador for encontrado em uma ou mais brackets, suas estatísticas são agregadas e o jogador é retornado.

@param *s: tServidor
@param idJog: ID do jogador
*/
tJogador *buscaDadosJogadorServidor(tServidor *s, int idJog)
{

    int w = 0, d = 0, dr = 0;

    tJogador *j = inicializaJogador(-1), *l;

    int flag = 0;

    for (int i = 0; i < s->qtd; i++)
    {

        l = buscaJogadorBracket(s->b[i], idJog);

        if (getIdJogador(l) != -1)
        {
            flag++;

            if (flag == 1)
            {
                liberaJogador(j);
                j = l;
            }

            if (flag > 1)
            {
                w = getWinsJogador(l);
                d = getDefeatsJogador(l);
                dr = getDrawsJogador(l);
                atualizaJogador(j, idJog, w, d, dr);
            }
        }

        else
        {
            liberaJogador(l);
        }
    }

    return j;
}

/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com as estatísticas de um conjunto de jogadores
solicitados a partir da entrada padrão. O relatório é impresso conforme o formato especificado na descrição da atividade.

@param *s: tServidor
*/
void criaRelatorioServidor(tServidor *s)
{

    int qtd = 0;
    tJogador *jog;

    scanf("%d\n", &qtd);

    int v[qtd];

    for (int i = 0; i < qtd; i++)
    {

        scanf("%d", &v[i]);
    }

    for (int j = 0; j < qtd; j++)
    {

        jog = buscaDadosJogadorServidor(s, v[j]);

        if (getIdJogador(jog) == -1)
        {

            printf("Jogador %d: -\n", v[j]);
            liberaJogador(jog);
        }
        else
        {

            printaJogador(jog);
        }
    }
}

/*
Funçao que libera um ponteiro de servidor caso este seja diferente de NULL.

@param *s: tServidor
*/
void liberaServidor(tServidor *s)
{

    for (int i = 0; i < s->qtd; i++)
    {

        liberaBracket(s->b[i]);
    }

    free(s->b);
    free(s);
}