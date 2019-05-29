#include <string.h>
#include "menu_artist.h"
#include <stdio.h>
#include "menu_pr.h"

#define TAM_NOME 50        // tamanho max de char na string - MACRO
#define TAM_VECTOR 50    // numero de musicas que podem ser armazenadas em memoria


// estruturas permitem definir novos tipos de dados - tipo de dados neste caso ira ter o nome musica - e composto por duas strings, titulo e artista
struct musica {
    char titulo[TAM_NOME];
    char artista[TAM_NOME];
};

struct musica vec_musicas[TAM_VECTOR];    // inicializa-se com a estrutura criada acima um vector de musicas
int artist_num = 0;            // numero de musicas no vector
char artist_file[] = "musicas.txt";// nome do ficheiro




int menu_artist() {
    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Listar Artistas \n");
        printf(" [2]Procurar Artista \n");
        printf(" [3]Adicionar Artista\n");
        printf(" [4]Editar Artista \n");
        printf(" [5]Remover artista \n");
        printf(" [6]Carregar o ficheiro\n");
        printf(" [7]Gravar no ficheiro\n");
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
                artist_search();
                break;
            case '3':
                printf("\n Insira Nome Artista \n");
                artist_add();
                break;
            case '4':
                printf("\n Insira Nome Artista \n");
                artist_edit();
                break;
            case '5':
                printf("\n Insira Nome Artista \n");
                artist_remove();
                break;
            case '6':
                artist_load();
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

    void artist_print(struct musica *m) {
        printf("%s\n", m->artista);
    }

    void artist_search() {

    }

    void artist_add(){

    }

    void artist_remove(){

    }

    void artist_edit(){

    }



void artist_list() {
    for (int i = 0; i < artist_num; i++) {
        artist_print(&vec_musicas[i]);
    }
}


void artist_load() {
    FILE *fp;
    int i = 0;
    char linha[TAM_NOME];
    artist_num = 0;
    fp = fopen(artist_file, "r");
    if (fp != NULL) {
        fscanf(fp, "%*s %d\n", &artist_num);            // ignore the string and store only the int
        for (i = 0; i < artist_num; i++) {
            fgets(linha, sizeof(linha), fp);            // titulo
            linha[strlen(linha) - 1] = 0;                // retira quebra de linha
            strcpy(vec_musicas[i].titulo, &linha[8]);        // titulo começa no 8º char
            fgets(linha, sizeof(linha), fp);            // titulo
            linha[strlen(linha) - 1] = 0;                // retira quebra de linha
            strcpy(vec_musicas[i].artista, &linha[8]);        // titulo começa no 8º char

        }
        fclose(fp);
    }
}