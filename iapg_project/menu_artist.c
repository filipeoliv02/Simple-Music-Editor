#include <string.h>
#include "project.h"
#include <stdio.h>


int artist_num = 0;                         /// numero de artistas no vector
char artist_file[] = "artistas.txt";        /// nome do ficheiro de artistas

int menu_artist() {
    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Listar Artistas \n");
        printf(" [2]Adicionar Artista\n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':
                printf("\n Artistas \n");
                artist_list();              ///lista todos os artistas assim como a sua nacionalidade
                break;
            case '2':
                printf("\n Insira Nome Artista \n");
                artist_add(&vec_artistas[artist_num]);      ///adiciona artistas
                artist_num++;
                artist_save();
                break;
            case 's':
            case 'S':
                break;
            default:
                printf(" Opcao invalida!!! \n");
        }
        if (op != 's' && op != 'S') {
            printf("\n\n Prima qualquer tecla para voltar ao menu...\n");
            getchar();
        }
    } while (op != 's' && op != 'S');

    return 0;

}

void
artist_print(struct artista *a) {                  ///funciona em conjunto com outra funcao para imprimir os artistas
    printf("%s - %s\n", a->nome, a->nacionalidade);

}


void artist_input(char *temp) {
    char input[TAM_NOME];           ///esta funcao deve ler uma string escrita pelo utilizador no terminal, e guarda-la em temp
    scanf(" %[^\n]s", input);
    strcpy(temp, input);
}


void artist_add(struct artista *a) {            ///adiciona artistas

    getchar();
    printf("Insira o nome do artista:\n");
    artist_input(a->nome);

    printf("Insira a nacionalidade:\n");
    artist_input(a->nacionalidade);

}

void artist_remove(struct artista *a) {             ///remove o artista selecionado

    int existe = 0;
    for (int i = 0; i < artist_num; i++) {

        if (strcmp(vec_artistas[i].nome, a->nome) == 0 || existe == 1) {
            existe = 1;
            vec_artistas[i] = vec_artistas[i + 1];


        }
    }
    artist_num--;
}

void artist_edit(struct artista *a) {
    getchar();

    printf("Insira o novo Nome para o Artista :\n");
    artist_input(a->nome);

    printf("Insira a nacionalidade:\n");
    artist_input(a->nacionalidade);
}

void artist_list() {                            ///lista todos os artistas
    for (int i = 0; i < artist_num; i++) {
        printf("[%d] ", i + 1);
        artist_print(&vec_artistas[i]);
    }
}

void artist_load() {
    FILE *fp;
    int i = 0;
    char linha[TAM_NOME];
    artist_num = 0;
    fp = fopen(artist_file, "r");
    if (fp != NULL) {
        fscanf(fp, "%*s %d\n", &artist_num);            /// ignore the string and store only the int
        for (i = 0; i < artist_num; i++) {
            fgets(linha, sizeof(linha), fp);            /// titulo
            linha[strlen(linha) - 1] = 0;                /// retira quebra de linha
            strcpy(vec_artistas[i].nome, &linha[6]);        /// titulo começa no 6º char
            fgets(linha, sizeof(linha), fp);            /// titulo
            linha[strlen(linha) - 1] = 0;                /// retira quebra de linha
            strcpy(vec_artistas[i].nacionalidade, &linha[15]);        /// titulo começa no 15º char

        }
        fclose(fp);
    }
}

void artist_save() {                ///grava alteracoes feitas pelo utilizador no ficheiro artistas
    FILE *fp;
    int i;
    fp = fopen(artist_file, "w");
    if (fp != NULL) {
        fprintf(fp, "artistas: %d\n", artist_num);
        for (i = 0; i < artist_num; i++) {
            fprintf(fp, "nome: %s\n", vec_artistas[i].nome);
            fprintf(fp, "nacionalidade: %s\n", vec_artistas[i].nacionalidade);
        }
        fclose(fp);
    }
}


void artist_search() {              ///encontra e remete para o menu de edicao de artistas
    char pesquisa[50];
    printf("\n Insira o nome do Artista \n");

    artist_input(pesquisa);
    for (int i = 0; i < artist_num; i++) {


        if (strcmp(vec_artistas[i].nome, pesquisa) == 0)
            menu_edit_remove_artist(&vec_artistas[i]);
    }
}