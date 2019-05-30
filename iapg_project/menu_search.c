#include "menu_search.h"
#include <stdio.h>
#include <string.h>



int menu_search() {
    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Pesquisar Titulo \n");
        printf(" [2]Pesquisar Artista \n");
        printf(" [3]Pesquisar Ano\n");
        printf(" [4]Pesquisar Album \n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':
                printf("\n Insira o Titulo da Musica \n");

                break;
            case '2':
                printf("\n Insira o nome do Artista \n");

                break;
            case '3':
                printf("\n Insira o Ano da Musica \n");

                break;
            case '4':
                printf("\n Insira o nome do Album \n");
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
    } while (op != 's' && op != 'S');

    return 0;
}