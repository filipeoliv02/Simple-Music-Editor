#ifndef IAPG_PROJECT_PROJECT_H
#define IAPG_PROJECT_PROJECT_H
#define TAM_NOME 50        // tamanho max de char na string - MACRO
#define TAM_VECTOR 50    // numero de musicas que podem ser armazenadas em memoria

// estruturas permitem definir novos tipos de dados - tipo de dados neste caso ira ter o nome musica - e composto por duas strings, titulo e artista
 struct artista {
    char nome[TAM_NOME];
    char nacionalidade[TAM_NOME];

} ;


struct musica {
    char titulo[TAM_NOME];
    char artista[TAM_NOME];
    //struct artista art;
    //ARTISTA artista;

};


//MENU_PR
int menu_pr();
void lista_todas_musicas();
void imprime_musica();
void ler_nova_musica();
void gravar_ficheiro();
void carregar_ficheiro();
//MENU_MUSIC
int menu_music();
void music_list();
void music_search();
void music_add();
void music_edit();
void music_remove();
void music_print();
void music_load();
void ler_nova_musica();
void music_save();
void music_input();
//MENU_ARTIST
int menu_artist();
void artist_list();
void artist_search();
void artist_add();
void artist_remove();
void artist_edit();
void artist_load();
void artist_print();
void artist_save();
void artist_input();
//MENU_SEARCH
int menu_search();
#endif