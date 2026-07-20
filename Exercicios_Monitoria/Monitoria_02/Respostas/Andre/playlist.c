#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief cria um dado do tipo playlist, ponteiros devem receber NULL e atributos numericos 0
 * @param name nome da playlist
 * @return retorna a playlist criada
 */
Playlist *criaPlaylist(char *name)
{
    if (name == NULL)
        return NULL;

    Playlist *pl = malloc(sizeof(Playlist));
    if (pl == NULL)
        return NULL;

    pl->qtdMusicas = 0;

    pl->nome = malloc((strlen(name) + 1) * sizeof(char));
    if (pl->nome == NULL)
    {
        free(pl);
        return NULL;
    }

    strcpy(pl->nome, name);

    pl->musicas = malloc(TAM_MAX_MUSICAS * sizeof(Musica *));
    if (pl->musicas == NULL)
    {
        free(pl->nome);
        free(pl);
        return NULL;
    }

    for (int idx = 0; idx < TAM_MAX_MUSICAS; idx++)
        pl->musicas[idx] = NULL;

    return pl;
}

/**
 * @brief le e adiciona uma musica na playlist
 * @param playlist ponteiro para a playlist
 */
void adicionaMusica(Playlist *playlist)
{
    if (playlist == NULL)
        return;

    if (playlist->qtdMusicas >= TAM_MAX_MUSICAS)
    {
        char descarte[MAX_TAM_STRING];
        scanf(" %29[^\n]", descarte);
        scanf(" %29[^\n]", descarte);
        scanf(" %29[^\n]", descarte);
        scanf(" %29[^\n]", descarte);
        printf("PLAYLIST CHEIA!\n");
        return;
    }

    Musica *nova = criaMusica();
    if (nova == NULL)
        return;

    leMusica(nova);

    for (int idx = 0; idx < playlist->qtdMusicas; idx++)
    {
        if (playlist->musicas[idx] != NULL &&
            comparaMusicas(playlist->musicas[idx], nova) == 1)
        {
            printf("A MUSICA JA ESTA NA PLAYLIST!\n");
            apagaMusica(nova);
            return;
        }
    }

    playlist->musicas[playlist->qtdMusicas++] = nova;
}

/**
 * @brief remove uma musica da playlist
 * @param playlist ponteiro para a playlist
 * @param music chave de busca para remocao
 * @param comparador funcao de comparacao
 * @param impMus funcao de impressao da musica
 * @return 1 se removida com sucesso, 0 caso contrario
 */
int removeMusica(Playlist *playlist, char *music, compara comparador, tipoImpressaoMusica impMus)
{
    if (playlist == NULL || music == NULL || comparador == NULL || impMus == NULL)
        return 0;

    for (int idx = 0; idx < playlist->qtdMusicas; idx++)
    {
        if (playlist->musicas[idx] == NULL || comparador(playlist->musicas[idx], music) != 1)
            continue;

        printf("MUSICA REMOVIDA: ");
        impMus(playlist->musicas[idx]);
        apagaMusica(playlist->musicas[idx]);

        int fim = playlist->qtdMusicas - 1;
        for (int j = idx; j < fim; j++)
            playlist->musicas[j] = playlist->musicas[j + 1];

        playlist->musicas[fim] = NULL;
        playlist->qtdMusicas--;
        return 1;
    }

    printf("A MUSICA NAO ESTA NA PLAYLIST\n");
    return 0;
}

/**
 * @brief imprime as musicas da playlist, podendo filtrar por chave
 * @param playlist ponteiro para a playlist
 * @param key chave de busca (ex: nome do artista); NULL imprime todas
 * @param comparador funcao de comparacao; NULL imprime todas as musicas
 * @param impMus funcao de impressao da musica
 */
void impressFunction(Playlist *playlist, char *key, compara comparador, tipoImpressaoMusica impMus)
{
    if (playlist == NULL || impMus == NULL)
        return;

    printf("---------------------------------------\n");
    printf("%s\n\n", comparador == NULL ? playlist->nome : key);

    for (int idx = 0; idx < playlist->qtdMusicas; idx++)
    {
        Musica *atual = playlist->musicas[idx];
        if (atual == NULL)
            continue;

        if (comparador == NULL)
            impMus(atual);
        else if (key != NULL && comparador(atual, key) == 1)
            impMus(atual);
    }

    printf("---------------------------------------\n");
}

/**
 * @brief desaloca uma playlist da memoria
 * @param playlist playlist a ser desalocada
 */
void apagaPlaylist(Playlist *playlist)
{
    if (playlist == NULL)
        return;

    if (playlist->musicas != NULL)
    {
        for (int idx = 0; idx < playlist->qtdMusicas; idx++)
        {
            if (playlist->musicas[idx] != NULL)
                apagaMusica(playlist->musicas[idx]);
        }
        free(playlist->musicas);
    }

    free(playlist->nome);
    free(playlist);
}