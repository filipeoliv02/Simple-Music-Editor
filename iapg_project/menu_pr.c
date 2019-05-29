#include "menu_pr.h"
#include <stdio.h>
#include "funcoes.h"
#include "menu_music.h"
#include "menu_artist.h"





int menu_pr() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Listar Informacao \n");
        printf(" [2] Musicas \n");
        printf(" [3] Artistas \n");
        printf(" [4] Carregar informacao do ficheiro\n");
        printf(" [s] Sair\n");
        fflush(stdin);
        scanf("%c", &opcao);
        switch (opcao) {
            case '1':
                printf("\n Todas as Informacoes \n");
                lista_todas_musicas();
                break;
            case '2':
                printf("\n Musicas \n");
                menu_music();
                break;
            case '3':
                printf("\n Artistas\n");
                menu_artist();

                break;
            case '4':
                printf("\n Ficheiro carregado com sucesso \n");
                carregar_musicas_do_ficheiro();

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
