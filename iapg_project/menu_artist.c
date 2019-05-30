#include <string.h>
#include "project.h"
#include <stdio.h>


int artist_num = 0;                         // numero de artistas no vector
char artist_file[] = "artistas.txt";        // nome do ficheiro de artistas

int menu_artist() {
    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Listar Artistas \n");
        printf(" [2]Adicionar Artista\n");
        printf(" [5]Carregar o ficheiro\n");
        printf(" [6]Gravar no ficheiro\n");
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
                artist_add(&vec_artistas[artist_num]);
                artist_num++;
                break;
            case '5':
                artist_load();
                printf("\n Ficheiro Carregado com Sucesso \n");
                break;
            case '6':
                artist_save();
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

void artist_print(struct artista *a) {
    printf("%s - %s\n", a->nome, a->nacionalidade);

}


void artist_input(char *temp) {
    char input[TAM_NOME];
    /*
    * POR FAZER - esta funcao deve ler uma string escrita pelo utilizador no terminal, e guarda-la em temp
    */
    scanf("%s", input);
    strcpy(temp, input);
}

void artist_search() {

}

void artist_add(struct artista *a) {

    getchar();
    printf("Insira o nome do artista:\n");
    artist_input(a->nome);

    printf("Insira a nacionalidade:\n");
    artist_input(a->nacionalidade);

}

void artist_remove() {

}

void artist_edit(struct artista *a) {
    getchar();
    printf("Insira o nome do artista:\n");
    artist_input(a->nome);

    printf("Insira a nacionalidade:\n");
    artist_input(a->nacionalidade);
}


void artist_list() {
    for (int i = 0; i < artist_num; i++) {
        printf("[%d] ",i+1);
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
        fscanf(fp, "%*s %d\n", &artist_num);            // ignore the string and store only the int
        for (i = 0; i < artist_num; i++) {
            fgets(linha, sizeof(linha), fp);            // titulo
            linha[strlen(linha) - 1] = 0;                // retira quebra de linha
            strcpy(vec_artistas[i].nome, &linha[6]);        // titulo começa no 6º char
            fgets(linha, sizeof(linha), fp);            // titulo
            linha[strlen(linha) - 1] = 0;                // retira quebra de linha
            strcpy(vec_artistas[i].nacionalidade, &linha[15]);        // titulo começa no 15º char

        }
        fclose(fp);
    }
}

void artist_save() {
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