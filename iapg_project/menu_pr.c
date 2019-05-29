#include "menu_pr.h"
#include <stdio.h>
#include "funcoes.h"


int menu_pr() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Listar Informacao \n");
        printf(" [2] Musicas \n");
        printf(" [3] Artistas \n");
        printf(" [s] Sair\n");
        fflush(stdin);
        scanf("%c", &opcao);
        switch (opcao) {
            case '1':
                printf("\n Todas as Informacoes \n");
                lista_todas_musicas();
                break;
            case '2':
                printf("\n Menu Procurar \n");

                break;
            case '3':
                printf("\n Menu Adicionar \n");

                break;
            case '4':
                printf("\n Menu Editar \n");

                break;
            case '5':
                printf("\n Menu Remover \n");

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
