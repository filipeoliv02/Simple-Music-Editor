
#include "menu_artist.h"
#include "funcoes.h"
#include <stdio.h>

#define TAM_NOME 50        // tamanho max de char na string - MACRO
#define TAM_VECTOR 50

struct artista {
    char artista[50];
};





struct artista vec_artistas[50];    // inicializa-se com a estrutura criada acima um vector de musicas
int num_artistas = 0;            // numero de musicas no vector
char ficheiro_musicas[] = "musicas.txt";






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
                artist_search(&vec_artistas[num_artistas]);
                num_artistas++; // aumenta o numero de artistas no vector
                break;
            case '3':
                printf("\n Insira Nome Artista \n");

                break;
            case '4':
                printf("\n Insira Nome Artista \n");

                break;
            case '5':
                printf("\n Insira Nome Artista \n");

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
        for (int i = 0; i < num_artistas; i++) {
            imprime_musica(&vec_musicas[i]);

        }
    }

        void artist_search(){

    }

    void artist_add(){

    }

    void artist_remove(){

    }

    void artist_edit(){

    }


























}