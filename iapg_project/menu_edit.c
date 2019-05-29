
#include "menu_edit.h"
#include "funcoes.h"
#include <stdio.h>


int menu_edit() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Editar Musica \n");
        printf(" [2] Editar Artista \n");
        printf(" [3] Voltar o Menu Principal \n");

        fflush(stdin);
        scanf("%c", &opcao);
        switch (opcao) {
            case '1':
                printf("\n Escolher Musica \n");

                break;
            case '2':
                printf("\n Escolher Artista \n");

                break;
            case '3':

                break;
            default:
                //system("cls"); // clear screen - cls windows or clear for linux/unix
                printf(" Opcao invalida!!! \n");
        }
        if (opcao != '3') {

            getchar();
        }
    } while (opcao != '3');

    return 0;
}