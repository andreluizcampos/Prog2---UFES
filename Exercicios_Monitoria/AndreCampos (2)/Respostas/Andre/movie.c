#include "movie.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Movie
{

    char *nome;
    char *diretor;
    char *genero;
    int duracao;
    int ano;
};

/**
 * @brief Lê os dados de um filme da entrada padrão e constrói a estrutura correspondente.
 * A ordem de leitura esperada é: Título, Diretor(a), Gênero, Ano de lançamento e Duração (em minutos).
 * @return Ponteiro para a estrutura Movie recém-criada.
 */
Movie *movie_read_and_construct()
{

    Movie *m = (Movie *)malloc(sizeof(Movie));
    m->diretor = (char *)malloc(sizeof(char) * 100);
    m->nome = (char *)malloc(sizeof(char) * 100);
    m->genero = (char *)malloc(sizeof(char) * 100);
    scanf("%s %s %s %d %d\n", m->nome, m->diretor, m->genero, &m->ano, &m->duracao);

    return m;
}

/**
 * @brief Imprime os dados formatados de um filme.
 * A formatação exibirá, linha por linha: o Nome, o Diretor, o Ano, o Gênero e a Duração.
 * @param m Ponteiro genérico que aponta para a estrutura Movie.
 */
void movie_print(void *m)
{

    Movie *ma = ((Movie *)m);
    printf("FILME\n");
    printf("\nTitulo: %s\n", ma->nome);
    printf("Diretor(a): %s\n", ma->diretor);
    printf("Genero: %s\n", ma->genero);
    printf("Ano de lancamento: %d\n", ma->ano);
    printf("Duracao: %d min\n", ma->duracao);
}

/**
 * @brief Libera a memória alocada para a estrutura de um filme.
 * @param m Ponteiro genérico que aponta para a estrutura Movie.
 */
void movie_free(void *m)
{

    Movie *ma = ((Movie *)m);

    free(ma->diretor);
    free(ma->genero);
    free(ma->nome);
    free(m);
}
