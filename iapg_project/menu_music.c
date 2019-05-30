#include <string.h>
#include "project.h"
#include <stdio.h>


int music_num = 0;            // numero de musicas no vector
char music_file[] = "musicas.txt";// nome do ficheiro




int menu_music() {

    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Listar Musicas \n");
        printf(" [2]Adicionar Musica \n");
        printf(" [3]Editar Musica \n");
        printf(" [4]Remover Musica \n");
        printf(" [5]Carregar o ficheiro\n");
        printf(" [6]Gravar no ficheiro\n");
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
                music_add(&vec_musicas[music_num]);
                music_num++; // aumenta o numero de musicas no vector
                break;
            case '3':
                printf("\n Insira o nome da Musica \n");
                music_edit();
                break;
            case '4':
                printf("\n Insira o nome da Musica \n");
                //music_remove(m);
                break;
            case '5':
                music_load();
                printf("\n Ficheiro Carregado com Sucesso \n");
                break;
            case '6':
                music_save();
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

void music_print(struct musica *m) {
    printf("%s\n", m->titulo);
}


void music_input(char *temp) {
    char input[TAM_NOME];
    /*
    * POR FAZER - esta funcao deve ler uma string escrita pelo utilizador no terminal, e guarda-la em temp
    */
    scanf(" %[^\n]s", input);
    strcpy(temp, input);

}

void music_search() {

}

void music_add(struct musica *m) {

    getchar();
    printf("Insira o titulo da musica:\n");

    music_input(m->titulo);
}

void music_edit() {

}

void music_remove(struct musica *m) {

    int existe = 0;
    for (int i = 0; i < music_num; i++) {

        if (strcmp(vec_musicas[i].titulo, m->titulo) == 0 || existe == 1) {
            existe = 1;
            vec_musicas[i] = vec_musicas[i + 1];


        }
    }
    music_num--;
}
    void music_list() {
        for (int i = 0; i < music_num; i++) {
            printf("[%d] ", i + 1);
            music_print(&vec_musicas[i]);
        }
    }

    void music_load() {
        FILE *fp;
        int i = 0;
        char linha[TAM_NOME];
        music_num = 0;
        fp = fopen(music_file, "r");
        if (fp != NULL) {
            fscanf(fp, "%*s %d\n", &music_num);            // ignore the string and store only the int
            for (i = 0; i < music_num; i++) {
                fgets(linha, sizeof(linha), fp);            // titulo
                linha[strlen(linha) - 1] = 0;                // retira quebra de linha
                strcpy(vec_musicas[i].titulo, &linha[8]);        // titulo começa no 8º char
                fgets(linha, sizeof(linha), fp);            // artista
                linha[strlen(linha) - 1] = 0;                // retira quebra de linha
                strcpy(vec_musicas[i].artista, &linha[9]);        // artista começa no 9º char
            }
            fclose(fp);
        }
    }

    void music_save() {
        FILE *fp;
        int i;
        fp = fopen(music_file, "w");
        if (fp != NULL) {
            fprintf(fp, "musicas: %d\n", music_num);
            for (i = 0; i < music_num; i++) {
                fprintf(fp, "titulo: %s\n", vec_musicas[i].titulo);
                fprintf(fp, "artista: %s\n", vec_musicas[i].artista);
            }
            fclose(fp);
        }
    }


    int menu_temp(struct musica *m) {

        char op;
        do {
            music_print(m);
            printf("Escolha uma opcao entre as possiveis: \n");
            printf(" [1]Editar \n");
            printf(" [2]Remover \n");
            printf(" [S]Sair \n");
            fflush(stdin);
            scanf("%c", &op);
            switch (op) {
                case '1':

                    break;
                case '2':
                    music_remove(m);
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
        } while (op != 's' && op != 'S' && op != '2');

        return 0;
    }