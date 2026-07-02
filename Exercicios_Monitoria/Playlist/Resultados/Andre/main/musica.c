#include <stdio.h>
#include <stdlib.h>
#include "musica.h"
#include <string.h>

/**
 * @brief cria um dado do tipo musica, ponteiros devem receber NULL e atributos numericos 0
 * @return retorna a musica criada
 */
Musica *criaMusica()
{
    Musica *musica = malloc(sizeof(Musica));
    if (musica == NULL)
        return NULL;

    musica->album = NULL;
    musica->artista = NULL;
    musica->genero = NULL;
    musica->nome = NULL;
    return musica;
}

/**
 * @brief le os atributos de uma musica
 * @param music ponteiro para a musica
 */
void leMusica(Musica *music)
{
    music->nome = malloc(MAX_TAM_STRING * sizeof(char));
    music->artista = malloc(MAX_TAM_STRING * sizeof(char));
    music->album = malloc(MAX_TAM_STRING * sizeof(char));
    music->genero = malloc(MAX_TAM_STRING * sizeof(char));

    if (music->nome == NULL || music->artista == NULL ||
        music->album == NULL || music->genero == NULL)
        return;

    scanf(" %29[^\n]", music->nome);
    scanf(" %29[^\n]", music->artista);
    scanf(" %29[^\n]", music->album);
    scanf(" %29[^\n]", music->genero);
}
/**
 * @brief compara duas musicas
 * @param music_1 primeira musica
 * @param music_2 segunda musica
 * @return 1 se forem iguais e qualquer outro valor caso contrario
 */
int comparaMusicas(Musica *music_1, Musica *music_2)
{
    if (strcmp(music_1->nome, music_2->nome) == 0 &&
        strcmp(music_1->artista, music_2->artista) == 0 &&
        strcmp(music_1->album, music_2->album) == 0 &&
        strcmp(music_1->genero, music_2->genero) == 0)
        return 1;

    return 0;
}

/**
 * @brief compara o nome de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaNomeMus(Musica *music, char *name)
{
    return strcmp(music->nome, name) == 0;
}

/**
 * @brief compara o artista de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaArtistaMus(Musica *music, char *artist)
{
    return strcmp(music->artista, artist) == 0;
}

/**
 * @brief compara o album de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaAlbumMus(Musica *music, char *album)
{
    return strcmp(music->album, album) == 0;
}

/**
 * @brief compara o genero de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaGeneroMus(Musica *music, char *genre)
{
    return strcmp(music->genero, genre) == 0;
}

/**
 * @brief imprime uma musica no formato [nome] - [artista] ............ [album]
 * @param music musica a ser impressa
 */
void imprimeMusica(Musica *music)
{
    printf("%s - %s ............ %s\n", music->nome, music->artista, music->album);
}

/**
 * @brief imprime uma musica no formato [nome]
 * @param music musica a ser impressa
 */
void imprimeMusica_Album(Musica *music)
{
    printf("%s\n", music->nome);
}

/**
 * @brief imprime uma musica no formato [nome] - [album]
 * @param music musica a ser impressa
 */
void imprimeMusica_Artista(Musica *music)
{
    printf("%s - %s\n", music->nome, music->album);
}

/**
 * @brief imprime uma musica no formato [nome] - [artista]
 * @param music musica a ser impressa
 */
void imprimeMusica_Genero(Musica *music)
{
    printf("%s - %s\n", music->nome, music->artista);
}

/**
 * @brief desaloca uma musica da memoria
 * @param music musica a ser desalocada
 */
void apagaMusica(Musica *music)
{
    free(music->album);
    free(music->artista);
    free(music->genero);
    free(music->nome);
    free(music);
}