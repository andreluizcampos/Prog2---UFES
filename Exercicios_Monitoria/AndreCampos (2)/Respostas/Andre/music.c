#include <stdio.h>
#include <string.h>
#include "music.h"

struct Music
{
    char *nome;
    char *artista;
    char *genero;
    char *album;
    char **participantes;
    int feats;
};

/**
 * @brief Lê os dados de uma música da entrada padrão e constrói a estrutura correspondente.
 * A ordem de leitura esperada é: Título, Artista, Quantidade de Feats, Lista com os nomes dos Feats, Álbum e Gênero.
 * @return Ponteiro para a estrutura Music recém-criada.
 */
Music *music_read_and_construct()
{

    Music *m = (Music *)malloc(sizeof(Music));
    m->album = (char *)malloc(sizeof(char) * 100);
    m->genero = (char *)malloc(sizeof(char) * 100);
    m->participantes = (char *)malloc(sizeof(char *) * 50);
    m->artista = (char *)malloc(sizeof(char) * 100);
    m->feats = 0;
    m->nome = (char *)malloc(sizeof(char) * 100);

    scanf("%s %s %d", m->nome, m->artista, &m->feats);

    if (m->feats > 0)
    {

        m->participantes = (char **)realloc(m->participantes, sizeof(char *) * (m->feats));

        int i = 0;

        for (int i = 0; i < m->feats; i++)
        {

            m->participantes[i] = (char *)malloc(sizeof(char) * 100);
            scanf("%s", m->participantes[i]);
        }

        scanf("%s %s\n", m->album, m->genero);
    }

    else
    {

        scanf("%s %s\n", m->album, m->genero);
    }

    return m;
}

/**
 * @brief Imprime os dados formatados de uma música.
 * A formatação exibirá, linha por linha: o Nome, o Artista, os Feats (se a quantidade for maior que zero), o Álbum e o Gênero.
 * @param m Ponteiro genérico que aponta para a estrutura Music.
 */
void music_print(void *m)
{
    Music *mu = ((Music *)m);

    printf("MUSICA\n");
    printf("Titulo: %s\n", mu->nome);
    printf("Artista: %s", mu->artista);
    if (mu->feats > 0)
    {

        printf(" feat.");

        for (int i = 0; i < mu->feats; i++)
        {

            printf(" %s", mu->participantes[i]);

            if (mu->feats > 1 && i != mu->feats - 1)
            {

                printf(",");
            }
        }
        printf("\n");
    }

    printf("\n");

    printf("Album: %s\n", mu->album);
    printf("Genero: %s\n", mu->genero);
}

/**
 * @brief Libera a memória alocada para a estrutura de uma música.
 * @param m Ponteiro genérico que aponta para a estrutura Music.
 */
void music_free(void *m)
{

    Music *mu = ((Music *)m);

    free(mu->album);
    free(mu->artista);
    free(mu->genero);

    for (int i = 0; i < mu->feats; i++)
    {
        free(mu->participantes[i]);
    }
    free(mu->participantes);
    free(mu->nome);
    free(mu);
}
