#include "project.h"

void year_search() {
    music_load();
    char pesquisa[50];

    music_input(pesquisa);

    for (int i = 0; i < music_num; i++) {
        if (strcmp(vec_musicas[i].ano, pesquisa) == 0) {
            printf("%s - %s (%s)", vec_musicas[i].artista,vec_musicas[i].album, vec_musicas[i].ano);
        }
    }
}