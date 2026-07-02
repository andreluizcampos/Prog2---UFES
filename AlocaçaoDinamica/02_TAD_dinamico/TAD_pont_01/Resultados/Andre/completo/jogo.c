#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"
#include "stdlib.h"

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo *CriaJogo()
{

    tJogo *jogo;

    jogo = malloc(sizeof(*jogo));
    return jogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo *jogo)
{
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(PECA_1);
    jogo->jogador2 = CriaJogador(PECA_2);

    int flag = 1;

    while (1)
    {

        if (flag)
        {
            JogaJogador(jogo->jogador1, jogo->tabuleiro);
            ImprimeTabuleiro(jogo->tabuleiro);
        }

        else
        {

            JogaJogador(jogo->jogador2, jogo->tabuleiro);
            ImprimeTabuleiro(jogo->tabuleiro);
        }

        if (AcabouJogo(jogo))
        {

            break;
        }

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
int AcabouJogo(tJogo *jogo)
{

    if (VenceuJogador(jogo->jogador1, jogo->tabuleiro))
    {

        printf("JOGADOR 1 Venceu!\n");
        return 1;
    }
    if (VenceuJogador(jogo->jogador2, jogo->tabuleiro))
    {

        printf("JOGADOR 2 Venceu!\n");
        return 1;
    }

    else if (!TemPosicaoLivreTabuleiro(jogo->tabuleiro))
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

int ContinuaJogo(void)
{
    printf("Jogar novamente? (s,n)\n");

    char resposta;
    scanf("%*[^ns]"); // Lê tudo que não for n nem s;
    scanf("%c\n", &resposta);

    return resposta == 's';
}

/**
 * Libera a memória de uma estrutura do tipo tJogo.
 *
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo *jogo)
{
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    DestroiTabuleiro(jogo->tabuleiro);
    free(jogo);
}