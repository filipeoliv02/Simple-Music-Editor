#include "menu_pr.h"
#include <stdio.h>
#include "menu_search.h"
#include "menu_add.h"
#include "menu_edit.h"
#include "menu_remove.h"
#include "funcoes.h"


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
                printf("\n Todas as Informacoes \n");
                lista_todas_musicas();
                break;
            case '2':
                printf("\n Menu Procurar \n");
                menu_search();
                break;
            case '3':
                printf("\n Menu Adicionar \n");
                menu_add();
                break;
            case '4':
                printf("\n Menu Editar \n");
                menu_edit();
                break;
            case '5':
                printf("\n Menu Remover \n");
                menu_remove();
                break;
            case '6':

                carregar_musicas_do_ficheiro();
                printf("\n Ficheiro Carregado com Sucesso \n");
                break;
            case '7':

                gravar_musicas_para_ficheiro();
                printf("\n Ficheiro Gravado com Sucesso \n");

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
