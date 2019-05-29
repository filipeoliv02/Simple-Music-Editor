#include "menu_pr.h"
#include <stdio.h>

int menu_pr() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Listar Informacao \n");
        printf(" [2] Procurar \n");
        printf(" [3] Adicionar \n");
        printf(" [4] Editar \n");
        printf(" [5] Remover \n");
        printf(" [6] Carregar Informacao do ficheiro\n");
        printf(" [7] Gravar no ficheiro\n");
        printf(" [s] Sair\n");
        fflush(stdin);
        scanf("%c", &opcao);
        switch (opcao) {
            case '1':
                printf("\n Musicas \n");

                break;
            case '2':
                printf("\n Insira Nova Musica \n");

                break;
            case '3':
                printf("\n Gravar musicas para ficheiro \n");

                break;
            case '4':
                printf("\n Carregar musicas do ficheiro para a memoria \n");

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
