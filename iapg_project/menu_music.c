
#include "project.h"



int music_num = 0;            /// numero de musicas no vector musicas
char music_file[] = "musicas.txt";        /// nome do ficheiro


/*!
 *
 * @brief
 * Menu das Músicas
 * @details
 * Menu com opções dedicado às Músicas
 *
 */

int menu_music() {

    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Listar Musicas \n");
        printf(" [2]Adicionar Musica \n");
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
                music_num++;
                music_save();
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
/*!
 *
 * @brief
 * usado noutra funcao para imprimir varias musicas
 *
 *
 */


void music_print(struct musica *m) {
    printf("%s - %s (%s)", m->titulo, m->album,m->ano);
}

/*!
 *
 * @brief
 * esta funcao deve ler uma string escrita pelo utilizador no terminal, e guarda-la em temp
 *
 */


void music_input(char *temp) {
    char input[TAM_NOME];
    scanf(" %[^\n]s", input);
    strcpy(temp, input);

}


/*!
 *
 * @brief
 * funcao dedicada a alterar uma musica
 */

void music_edit(struct musica*m) {


    getchar();
    printf("Insira o novo Titulo para a Musica :\n");

    music_input(m->titulo);
}


/*!
 *
 * @brief
 * Adiciona uma Música
 * @details
 * Adiciona uma Música com as informações de Titulo, Artista, Album e Ano
 */

void music_add(struct musica *m) {

    getchar();
    printf("Insira o titulo da musica:\n");

    music_input(m->titulo);
    printf("Insira o artista da musica:\n");

    music_input(m->artista);
    printf("Insira o album da musica:\n");

    music_input(m->album);
    printf("Insira o ano da musica:\n");

    music_input(m->ano);
}

/*!
 *
 * @brief
 * Remove a Música Selecionada pelo Utilizador
 * @details
 *
 */

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


/*!
 * @brief
 * Lista as várias músicas
 * @details
 * Lista todas as Músicas e os seu respetico Ano e Album
 */


void music_list() {
    for (int i = 0; i < music_num; i++) {
        printf("\n [%d] ", i + 1);
        music_print(&vec_musicas[i]);
    }
}

/*!
 * @brief
 * carrega o ficheiro musicas.txt
 * @details
 * carrega o ficheiro musicas.txt e distingue as diferentes carateristicas de cada uma das músicas
 */


void music_load() {
    FILE *fp;
    int i = 0;
    char linha[TAM_NOME];
    music_num = 0;
    fp = fopen(music_file, "r");
    if (fp != NULL) {
        fscanf(fp, "%*s %d\n", &music_num);
        for (i = 0; i < music_num; i++) {
            fgets(linha, sizeof(linha), fp);
            linha[strlen(linha) - 1] = 0;
            strcpy(vec_musicas[i].titulo, &linha[8]);
            fgets(linha, sizeof(linha), fp);
            linha[strlen(linha) - 1] = 0;
            strcpy(vec_musicas[i].artista, &linha[9]);
            fgets(linha, sizeof(linha), fp);
            linha[strlen(linha) - 1] = 0;
            strcpy(vec_musicas[i].album, &linha[7]);
            fgets(linha, sizeof(linha), fp);
            linha[strlen(linha) - 1] = 0;
            strcpy(vec_musicas[i].ano, &linha[5]);

            lrc_load(&vec_musicas[i]);
        }
        fclose(fp);
    }
}

/*!
 * @brief
 * grava alterações feitas pelo utilizador
 * @details
 * Percorre as diferentes varaiáveis da estrutura das Músicas
 *
 */


void music_save() {
    FILE *fp;
    int i;
    fp = fopen(music_file, "w");
    if (fp != NULL) {
        fprintf(fp, "musicas: %d\n", music_num);
        for (i = 0; i < music_num; i++) {
            fprintf(fp, "titulo: %s\n", vec_musicas[i].titulo);
            fprintf(fp, "artista: %s\n", vec_musicas[i].artista);
            fprintf(fp, "album: %s\n", vec_musicas[i].album);
            fprintf(fp, "ano: %s\n", vec_musicas[i].ano);
        }
        fclose(fp);
    }
}

/*!
 * @brief
 * Remete para o Menu de Edição de Músicas
 * @details
 * Faz a seleção da Música pretendida e remete para o menu de edição
 */

void music_search() {
    char pesquisa[50];
    printf("\n Insira o Titulo da Musica \n");

    music_input(pesquisa);

    for (int i = 0; i < music_num; i++) {
        if (strcmp(vec_musicas[i].titulo, pesquisa) == 0)


            menu_edit_remove_music(&vec_musicas[i]);
    }
}