
#include "menu_add.h"
#include "funcoes.h"
#include <stdio.h>


int menu_add() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Adicionar Musica \n");
        printf(" [2] Adicionar Artista \n");
        printf(" [3] Voltar o Menu Principal \n");
        printf(" [s] Sair\n");
        fflush(stdin);
        scanf("%c", &opcao);
        switch (opcao) {
            case '1':
                printf("\n Insira o titulo \n");

                break;
            case '2':
                printf("\n Insira o nome do Artista \n");

                break;
            case '3':


                break;


            case 's':
            case 'S':
                break;
            default:
                //system("cls"); // clear screen - cls windows or clear for linux/unix
                printf(" Opcao invalida!!! \n");
        }
        if (opcao != 's' && opcao != 'S') {
            printf("\n\nprima qualquer tecla para voltar ao menu...");
            getchar();
        }
    } while (opcao != 's' && opcao != 'S');

    return 0;
}