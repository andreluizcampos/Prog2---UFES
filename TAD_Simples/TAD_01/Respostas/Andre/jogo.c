#include <stdio.h>
#include <string.h>
#include "jogada.h"
#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

tJogo CriaJogo()
{

    tJogo jogo;

    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    jogo.tabuleiro = CriaTabuleiro();

    return jogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo)
{
    int flag = 1;
    while (1)
    {

        if (AcabouJogo(jogo))
        {

            break;
        }

        if (flag)
        {
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        }
        else
        {

            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        }

        ImprimeTabuleiro(jogo.tabuleiro);
        flag = !flag;
    }
}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo)
{


    if (VenceuJogador(jogo.jogador1, jogo.tabuleiro))
    {

        printf("JOGADOR 1 Venceu!\n");

        return 1;
    }

    if (VenceuJogador(jogo.jogador2, jogo.tabuleiro))
    {
        printf("JOGADOR 2 Venceu!\n");

        return 1 ;
    }


    if (!TemPosicaoLivreTabuleiro(jogo.tabuleiro))
    {

        printf("Sem vencedor!\n");
        return 1;
    }


    return 0;
}

/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{

    char c;
    printf("Jogar novamente? (s,n)\n");

    scanf("%*[^sn]");
    scanf(" %c\n", &c);

    return c == 's';
}
