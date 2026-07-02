#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

struct Game
{

    char *nome;
    char *desenvolvedora;
    char *genero;
    char *plataformas;
    int ano;
    int qtd_plataformas;
};

/**
 * @brief Lê os dados de um jogo da entrada padrão e constrói a estrutura correspondente.
 * A ordem de leitura esperada é: Título, Desenvolvedora, Gênero, Ano de lançamento, Quantidade de plataformas e a lista com o nome de cada plataforma.
 * @return Ponteiro para a estrutura Game recém-criada.
 */
Game *game_read_and_construct()
{

    Game *g = (Game *)malloc(sizeof(Game));

    g->desenvolvedora = (char *)malloc(sizeof(char) * MAX_TAM_STRING);
    g->genero = (char *)malloc(sizeof(char) * MAX_TAM_STRING);
    g->nome = (char *)malloc(sizeof(char) * MAX_TAM_STRING);
    g->plataformas = (char *)malloc(sizeof(char) * MAX_TAM_STRING);

    scanf("%s %s %s %d %d %[^\n]\n", g->nome, g->desenvolvedora, g->genero, &g->ano, &g->qtd_plataformas, g->plataformas);

    return g;
}

/**
 * @brief Imprime os dados formatados de um jogo.
 * A formatação exibirá, linha por linha: o Nome, a Desenvolvedora, o Ano, o Gênero e a lista de Plataformas disponíveis.
 * @param g Ponteiro genérico que aponta para a estrutura Game.
 */
void game_print(void *g)
{

    Game *ga = ((Game *)g);

    printf("JOGO\n");
    printf("Titulo: %s\n", ga->nome);
    printf("Desenvolvedora: %s\n", ga->desenvolvedora);
    printf("Genero: %s\n", ga->genero);
    printf("Ano de lancamento: %d\n", ga->ano);
    printf("Plataforma(s): ");
    for (int i = 0; i < strlen(ga->plataformas); i++)
    {

        if (ga->plataformas[i] == ' ')
        {

            ga->plataformas[i] = ',';
        }
        printf("%c", ga->plataformas[i]);

        if(ga->plataformas[i]==','){
            printf(" ");
        }
    }
    printf("\n");
}

/**
 * @brief Libera a memória alocada para a estrutura de um jogo.
 * @param g Ponteiro genérico que aponta para a estrutura Game.
 */
void game_free(void *g)
{

    Game *ga = ((Game *)g);

    free(ga->nome);
    free(ga->desenvolvedora);
    free(ga->plataformas);
    free(ga->genero);
    free(ga);
}