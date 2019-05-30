#include "project.h"


int menu_edit() {                   //struct musica *m ?

    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Editar Titulo \n");
        printf(" [2]Editar Artista \n");
        printf(" [3]Editar Album \n");
        printf(" [4]Editar Naturalidade \n");
        printf(" [5]Editar Ano \n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':
                music_edit();
                break;
            case '2':
                artist_edit();
                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case 's':
            case 'S':
                break;
            default:
                //system("cls"); // clear screen - cls windows or clear for linux/unix
                printf(" Opcao invalida!!! \n");
        }
        if (op != 's' && op != 'S') {
            printf("\n\n Prima qualquer tecla para voltar ao menu...");
            getchar();
        }
    } while (op != 's' && op != 'S' && op != '2');

    return 0;
}