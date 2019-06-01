#ifndef IAPG_PROJECT_PROJECT_H
#define IAPG_PROJECT_PROJECT_H

#include <stdio.h>
#include <string.h>
#include <locale.h>





#define TAM_NOME 50        // tamanho max de char na string - MACRO
#define TAM_VECTOR 50    // numero de musicas que podem ser armazenadas em memoria

int music_num;
int artist_num; // numero de musicas no vector

 typedef struct artista {               // estruturas permitem definir novos tipos de dados - tipo de dados neste caso ira ter o nome artista - e composto por duas strings, nome e nacionalidade
    char nome[TAM_NOME];
    char nacionalidade[TAM_NOME];
}ARTISTA;


 struct lrc{
     int min;
     int seg;
     int cs;
     char texto[100];
 };


struct musica {             // estruturas permitem definir novos tipos de dados - tipo de dados neste caso ira ter o nome musica - e composto por duas strings e uma estrutura, titulo e artista
    char titulo[TAM_NOME];
    char artista[TAM_NOME];
    char album[TAM_NOME];
    char ano[TAM_NOME];
    struct lrc letras[100];
    int num_letras;

    ARTISTA cantor;
};

struct musica vec_musicas[TAM_VECTOR];    // inicializa-se com a estrutura criada acima um vector de musicas
struct artista vec_artistas[TAM_VECTOR];    // inicializa-se com a estrutura criada acima um vector de artistas


//MENU_PRINCIPAL
int menu_pr();
void lista_todas_musicas();
void imprime_musica(struct musica *m);
void gravar_ficheiro();
void carregar_ficheiro();

//MENU_MUSIC
int menu_music();
void music_list();
void music_add(struct musica *m);
void music_edit(struct musica *m);
void music_remove(struct musica *m);
void music_print(struct musica *m);
void music_load();
void music_save();
void music_input(char *temp);
void music_search();

//MENU_ARTIST
int menu_artist();
void artist_list();
void artist_search();
void artist_add(struct artista *a);
void artist_remove(struct artista *a);
void artist_edit(struct artista *a);
void artist_load();
void artist_print(struct artista *a);
void artist_save();
void artist_input(char *temp);
int menu_artist_edit(struct artista *a);

//MENU_SEARCH
int menu_search();



int menu_edit_remove_music(struct musica *m);
int menu_edit_remove_artist(struct artista *a);
int menu_edit(struct musica *m);



void lrc_load(struct musica*m);

#endif