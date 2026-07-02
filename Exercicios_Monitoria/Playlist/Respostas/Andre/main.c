/*
Uma playlist para uma festa.
16/05/2026
*/
#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include "musica.h"

int main()
{
    char nomePlaylist[MAX_TAM_STRING];
    int qtdAcoes;
    int cmd;
    char chave[MAX_TAM_STRING];

    scanf(" %29[^\n]%*c", nomePlaylist);
    scanf("%d%*c", &qtdAcoes);

    Playlist *pl = criaPlaylist(nomePlaylist);
    if (pl == NULL)
        return 1;

    for (int idx = 0; idx < qtdAcoes; idx++)
    {
        scanf(" %d", &cmd);
        switch (cmd)
        {
        case 1:
            adicionaMusica(pl);
            break;
        case 2:
            scanf(" %29[^\n]", chave);
            removeMusica(pl, chave, comparaNomeMus, imprimeMusica_Album);
            break;
        case 3:
            impressFunction(pl, NULL, NULL, imprimeMusica);
            break;
        case 4:
            scanf(" %29[^\n]", chave);
            impressFunction(pl, chave, comparaArtistaMus, imprimeMusica_Artista);
            break;
        case 5:
            scanf(" %29[^\n]", chave);
            impressFunction(pl, chave, comparaAlbumMus, imprimeMusica_Album);
            break;
        case 6:
            scanf(" %29[^\n]", chave);
            impressFunction(pl, chave, comparaGeneroMus, imprimeMusica_Genero);
            break;
        }
    }

    apagaPlaylist(pl);
    return 0;
}