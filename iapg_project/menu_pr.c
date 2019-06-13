#include "project.h"

/*!
 *
 * @brief
 * Menu principal
 * @details
 * Menu Principal com a possibilidade de escolha de um dos seus sub-menus
 */

    int menu_pr() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Listar Informacao \n");
        printf(" [2] Musicas \n");
        printf(" [3] Artistas \n");
        printf(" [4] Procurar \n");
        printf(" [s] Sair\n");
        fflush(stdin);
        scanf("%c", &opcao);
        switch (opcao) {
            case '1':
                printf("\n Todas as Informacoes \n");
                music_load();
                lista_todas_musicas();
                break;
            case '2':
                printf("\n Musicas \n");
                music_load();
                menu_music();
                break;
            case '3':
                printf("\n Artistas\n");
                artist_load();
                menu_artist();
                break;
            case '4':
                menu_search();
                break;
            case 's':
            case 'S':
                break;
            default:
                printf(" Opcao invalida!!! \n");
        }
        if (opcao != 's' && opcao != 'S') {
            printf("\n\n Prima qualquer tecla para voltar ao menu...\n");
            getchar();
        }
    } while (opcao != 's' && opcao != 'S');

    return 0;
}


/*!
 *
 * @brief
 * imprime a musica contida na estrutura - artista + titulo
 */

void imprime_musica (struct musica *m) {

        printf("%s - %s \n", m->artista, m->titulo);
}



/*!
 * @brief
 * lista a informacao contida para todas as musicas no ficheiro musicas.txt
 * @details
 * Lista as informacoes contidas em musicas.txt ordenando-as numericamente
 */


void lista_todas_musicas() {
    for (int i = 0; i < music_num; i++) {
        printf("[%d] ",i+1);
        imprime_musica(&vec_musicas[i]);
    }
}

