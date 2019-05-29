
#include "menu_music.h"
#include "funcoes.h"
#include <stdio.h>

#define TAM_NOME 50        // tamanho max de char na string - MACRO
#define TAM_VECTOR 50

struct musica {
    char musica[50];
};





struct musica vec_musicas[50];    // inicializa-se com a estrutura criada acima um vector de musicas
int num_musicas = 0;            // numero de musicas no vector
char ficheiro_musicas[] = "musicas.txt";

int menu_music() {
    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Listar Musicas \n");
        printf(" [2]Procurar Musica \n");
        printf(" [3]Adicionar Musica \n");
        printf(" [4]Editar Musica \n");
        printf(" [5]Remover Musica \n");
        printf(" [6] Carregar Informacao do ficheiro\n");
        printf(" [7] Gravar no ficheiro\n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':
                printf("\n Musicas \n");
                music_list();
                break;
            case '2':
                printf("\n Insira o nome da Musica \n");
                music_search();

                break;
            case '3':
                printf("\n Insira o nome da Musica \n");
                music_add();
                break;
            case '4':
                printf("\n Insira o nome da Musica \n");
                music_edit();
                break;
            case '5':
                printf("\n Insira o nome da Musica \n");
                music_remove();
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
        if (op != 's' && op != 'S') {
            printf("\n\n Prima qualquer tecla para voltar ao menu...");
            getchar();
        }
    } while (op != 's' && op != 'S');

    return 0;
}

void music_list(){

}

void music_search(){

}

void music_add(){

}

void music_edit(){

}

void music_remove(){

}

