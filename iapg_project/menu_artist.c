
#include "menu_artist.h"
#include "funcoes.h"
#include <stdio.h>

int menu_artist() {
    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Listar Artistas \n");
        printf(" [2]Procurar Artista \n");
        printf(" [3]Editar Artista \n");
        printf(" [4]Remover artista \n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':
                printf("\n Artistas \n");
                lista_todas_musicas();
                break;
            case '2':
                printf("\n Insira Nova Musica \n");
                ler_nova_musica(&vec_musicas[num_musicas]);
                num_musicas++; // aumenta o numero de musicas no vector
                break;
            case '3':
                printf("\n Gravar musicas para ficheiro \n");
                gravar_musicas_para_ficheiro();
                break;
            case '4':
                printf("\n Carregar musicas do ficheiro para a memoria \n");
                carregar_musicas_do_ficheiro();
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