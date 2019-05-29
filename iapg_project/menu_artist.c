
#include "menu_artist.h"
#include "funcoes.h"
#include <stdio.h>

struct artista vec_artistas[50];    // inicializa-se com a estrutura criada acima um vector de musicas
int num_artistas = 0;            // numero de musicas no vector
char ficheiro_artistas[] = "musicas.txt";






int menu_artist() {
    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Listar Artistas \n");
        printf(" [2]Procurar Artista \n");
        printf(" [3]Adicionar Artista\n");
        printf(" [4]Editar Artista \n");
        printf(" [5]Remover artista \n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':
                printf("\n Artistas \n");
                artist_list();
                break;
            case '2':
                printf("\n Insira Nome Artista \n");
                procurar_artista(&vec_musicas[num_musicas]);
                num_musicas++; // aumenta o numero de musicas no vector
                break;
            case '3':
                printf("\n Adicionar Artista \n");
                gravar_musicas_para_ficheiro();
                break;
            case '4':
                printf("\n Editar Artista \n");
                carregar_musicas_do_ficheiro();
                break;
            case '5':
                printf("\n Remover Artista \n");
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


    void artist_list() {
        for (int i = 0; i < num_musicas; i++) {
            imprime_musica(&vec_musicas[i]);

        }
    }

        void