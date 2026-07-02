#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "media.h"
#include "game.h"
#include "movie.h"
#include "music.h"
#include "list.h"

int main()
{

    List *r = list_construct();
    void **dado = malloc(sizeof(Media *));

    char *IMPRIMIR, *FILME, *JOGO, *MUSICA, *OPTION;
    Media *m;
    MUSICA = (char *)malloc(sizeof(char) * 50);
    FILME = (char *)malloc(sizeof(char) * 50);
    JOGO = (char *)malloc(sizeof(char) * 50);
    IMPRIMIR = (char *)malloc(sizeof(char) * 50);
    OPTION = (char *)malloc(sizeof(char) * 50);

    strcpy(IMPRIMIR, "IMPRIMIR\0");
    strcpy(MUSICA, "MUSICA\0");
    strcpy(FILME, "FILME\0");
    strcpy(JOGO, "JOGO\0");

    int i = 0;

    while (1)
    {

        scanf("%s\n", OPTION);

        if (strcmp(OPTION, IMPRIMIR) == 0)
        {

            list_print(r);
            break;
        }

        if (strcmp(OPTION, JOGO) == 0)
        {

            dado[i] = game_read_and_construct();
            dado = realloc(dado, (i + 2) * (sizeof(Media *)));
            m = media_construct(dado[i], game_print, game_free);
            list_media_insert(r, m, media_print, media_free);
            i++;
        }

        if (strcmp(OPTION, FILME) == 0)
        {
            dado[i] = movie_read_and_construct();
            dado = realloc(dado, (i + 2) * (sizeof(Media *)));
            m = media_construct(dado[i], movie_print, movie_free);
            list_media_insert(r, m, media_print, media_free);
            i++;
        }

        if (strcmp(OPTION, MUSICA) == 0)
        {

            dado[i] = music_read_and_construct();
            dado = realloc(dado, (i + 2) * (sizeof(Media *)));
            m = media_construct(dado[i], music_print, music_free);
            list_media_insert(r, m, media_print, media_free);
            i++;
        }
    }

    list_free(r);
    free(IMPRIMIR);
    free(MUSICA);
    free(JOGO);
    free(FILME);
    free(OPTION);
    free(dado);
}