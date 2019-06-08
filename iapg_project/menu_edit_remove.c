#include "project.h"


int menu_edit_remove_music(struct musica *m) {              ///Menu de Edicao de musicas

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

                music_print(m);                 ///lista o nome da musica

                lrc_print();                    ///lista as letras da musica
                break;
            case '2':
                music_edit(m);                  ///edita a musica
                music_save();
                break;
            case '3':
                music_remove(m);                ///remove a musica
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

int menu_edit_remove_artist(struct artista *a) {            ///Menu de Edicao de artistas
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
                artist_edit(a);         ///edita o nome do artista
                artist_save();
                break;
            case '2':
                artist_remove(a);           ///remove o artista
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


void lrc_print(struct musica *m) {                  ///imprime as letras
    printf("\n \n");
    for(int i=0;i < m->num_letras; i++){
        printf("%s \n", m->letras[i].texto);
    }

}
