#include <stdio.h>
#include <string.h>
#include "partida.h"
#include "navio.h"
#include "posicao.h"

#define NAVIOS_POR_JOGADOR 5

int main()
{

    printf("resenha");

    char nome1[PARTIDA_MAX_NOME], nome2[PARTIDA_MAX_NOME];
    int tamanho;
    scanf("%s %s %d\n", nome1, nome2, &tamanho);

    Partida p = partida_criar(nome1, nome2, tamanho);

    for (int jogador = 0; jogador < 2; jogador++)
    {
        for (int i = 0; i < NAVIOS_POR_JOGADOR; i++)
        {
            int lin, col, horiz, tam;
            char nome_navio[NAVIO_MAX_NOME];
            scanf("%d %d %d %d %s\n", &lin, &col, &horiz, &tam, nome_navio);
            Navio n = navio_criar(nome_navio, tam);
            Posicao orig = posicao_criar(lin, col);
            grid_posicionar(&p.grids[jogador], &n, orig, horiz);
        }
    }

    printf("\n=== BATALHA NAVAL: %s vs %s ===\n\n", nome1, nome2);
    printf("Navios posicionados. Iniciando jogo...\n\n");

    int lin, col, ignorado, rodada = 1;

    while (!partida_encerrada(p) && scanf("%d %d %d", &lin, &col, &ignorado) == 3)
    {
        Posicao alvo = posicao_criar(lin, col);
        char *atual = partida_turno_atual(&p);
        ResultadoJogada res = partida_jogar(&p, alvo);

        printf("Rodada %d - %s atira em (%d, %d): ", rodada, atual, lin, col);

        switch (res)
        {
        case JOGADA_INVALIDA:
            printf("Invalido!\n");
            break;
        case JOGADA_AGUA:
            printf("Agua!\n");
            break;
        case JOGADA_ACERTO:
            printf("Atingiu!\n");
            break;
        case JOGADA_AFUNDOU:
            printf("Afundou um navio!\n");
            break;
        case JOGADA_VITORIA:
            printf("VITORIA!\n");
            break;
        }

        if (res != JOGADA_INVALIDA)
            rodada++;
    }

    printf("\n*** PARTIDA ENCERRADA ***\n");
    char *venc = partida_vencedor(&p);
    if (venc)
        printf("Vencedor: %s\n", venc);

    return 0;
}