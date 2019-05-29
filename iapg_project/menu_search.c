#include "menu_search.h"
#include "funcoes.h"
#include <stdio.h>

int menu_search() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Procurar Musica \n");
        printf(" [2] Procurar Artista \n");
        printf(" [3] Procurar Ano \n");
        printf(" [4] Voltar ao menu Principal \n");
        fflush(stdin);
        scanf("%c", &opcao);
        switch (opcao) {
            case '1':
                printf("\n Insira o nome da Musica \n");

                break;
            case '2':
                printf("\n Insira o nome do Artista \n");

                break;

            case '3':
                printf("\n Insira o Ano \n");

                break;
            case '4':
                break;
            default:
                //system("cls"); // clear screen - cls windows or clear for linux/unix
                printf(" Opcao invalida!!! \n");
        }
        if (opcao != '4') {
            getchar();
        }
    } while (opcao != '4');

    return 0;
}
