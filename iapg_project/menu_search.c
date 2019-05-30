#include "project.h"




int menu_search() {

    char op, pesquisa[50];
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
                music_load();
                printf("\n Insira o Titulo da Musica \n");
                music_input(pesquisa);
                for(int i=0;i<music_num;i++){
                    if(strcmp(vec_musicas[i].titulo,pesquisa)==0)


                        menu_edit_remove_music(&vec_musicas[i]);
                }
                break;
            case '2':
                artist_load();
                printf("\n Insira o nome do Artista \n");

                artist_input(pesquisa);
                for(int i=0;i<artist_num;i++){


                    printf("\n TEST FOR \n");

                    if(strcmp(vec_artistas[i].nome,pesquisa)==0)
                        menu_edit_remove_artist(&vec_artistas[i]);
                }
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
                break;
        }
        if (op != 's' && op != 'S') {
            printf("\n\n Prima qualquer tecla para voltar ao menu...  \n");
            getchar();
        }
    } while (op != 's' && op != 'S');

    return 0;
}



