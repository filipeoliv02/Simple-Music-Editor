//
// Created by Barbosa on 29/05/2019.
//

#include "menu_remove.h"
#include "funcoes.h"
#include <stdio.h>


int menu_remove() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Remover Musica \n");
        printf(" [2] Remover Artista \n");
        printf(" [3] Voltar o Menu Principal \n");
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