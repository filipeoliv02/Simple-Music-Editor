#include "project.h"

/*!
 *
 * @brief
 * Menu de Edicao de musicas
 *
 */

int menu_edit_remove_music(struct musica *m) {

    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Ver Letra \n");
        printf(" [2]Editar \n");
        printf(" [3]Remover \n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':

                music_print(m);

                lrc_print();
                break;
            case '2':
                music_edit(m);
                music_save();
                break;
            case '3':
                music_remove(m);
                music_save();
                break;
            case 's':
            case 'S':
                break;
            default:
                printf(" Opcao invalida!!! \n");
        }
        if (op != 's' && op != 'S') {
            printf("\n\n Prima qualquer tecla para voltar ao menu... \n");
            getchar();
        }
    } while (op != 's' && op != 'S' && op != '2');

    return 0;
}


/*!
 *
 * @brief
 * Menu de Edição de Artistas
 *
 */


int menu_edit_remove_artist(struct artista *a) {
    char op;
    do {
        artist_print(a);
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Editar \n");
        printf(" [2]Remover \n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':
                artist_edit(a);
                artist_save();
                break;
            case '2':
                artist_remove(a);
                artist_save();
                break;
            case 's':
            case 'S':
                break;
            default:
                printf(" Opcao invalida!!! \n");
        }
        if (op != 's' && op != 'S') {
            printf("\n\n Prima qualquer tecla para voltar ao menu... \n");
            getchar();
        }
    } while (op != 's' && op != 'S' && op != '2');

    return 0;
}

/*!
 *
 * @brief
 * lista as letras da musica
 */
void lrc_print(struct musica *m) {
    printf("\n \n");
    for(int i=0;i < m->num_letras; i++){
        printf("%s \n", m->letras[i].texto);
    }

}
