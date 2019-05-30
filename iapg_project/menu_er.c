#include "project.h"


int menu_temp(struct musica *m) {

    char op;
    do {
        music_print(m);
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Editar \n");
        printf(" [2]Remover \n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':

                break;
            case '2':
                music_remove(m);
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