#include "project.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>





int num_musicas = 0;            // numero de musicas no vector
char ficheiro_musicas[] = "musicas.txt";// nome do ficheiro




int menu_pr() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Listar Informacao \n");
        printf(" [2] Musicas \n");
        printf(" [3] Artistas \n");
        printf(" [4] Procurar \n");
        printf(" [5] Carregar informacao do ficheiro\n");
        printf(" [6] Guardar informacao no ficheiro\n");
        printf(" [s] Sair\n");
        fflush(stdin);
        scanf("%c", &opcao);
        switch (opcao) {
            case '1':
                printf("\n Todas as Informacoes \n");
                lista_todas_musicas();
                break;
            case '2':
                printf("\n Musicas \n");
                menu_music();
                break;
            case '3':
                printf("\n Artistas\n");
                menu_artist();
                break;
            case '4':
                menu_search();
                break;
            case '5':
                printf("\n Ficheiro carregado com sucesso \n");
                carregar_ficheiro();
                break;
            case '6':
                printf("\n Ficheiro guardado com sucesso \n");
                gravar_ficheiro();
                break;
            case 's':
            case 'S':
                break;
            default:
                //system("cls"); // clear screen - cls windows or clear for linux/unix
                printf(" Opcao invalida!!! \n");
        }
        if (opcao != 's' && opcao != 'S') {
            printf("\n\n Prima qualquer tecla para voltar ao menu...");
            getchar();
        }
    } while (opcao != 's' && opcao != 'S');

    return 0;
}




void imprime_musica (struct musica *m) {
    /*
    * POR FAZER - esta funcao deve imprimir a musica contida na estrutura - titulo + artista
    */
    printf("%s - %s \n", m->artista, m->titulo);
}


void lista_todas_musicas() {
    for (int i = 0; i < num_musicas; i++) {
        printf("[%d] ",i+1);
        imprime_musica(&vec_musicas[i]);
    }
}




void gravar_ficheiro() {
    FILE *fp;
    int i;
    fp = fopen(ficheiro_musicas, "w");
    if (fp != NULL) {
        fprintf(fp, "musicas: %d\n", num_musicas);
        for (i = 0; i < num_musicas; i++) {
            fprintf(fp, "titulo: %s\n", vec_musicas[i].titulo);
            fprintf(fp, "artista: %s\n", vec_musicas[i].artista);
        }
        fclose(fp);
    }
}

void carregar_ficheiro() {
    FILE *fp;
    int i = 0;
    char linha[TAM_NOME];
    num_musicas = 0;
    fp = fopen(ficheiro_musicas, "r");
    if (fp != NULL) {
        fscanf(fp, "%*s %d\n", &num_musicas);            // ignore the string and store only the int
        for (i = 0; i < num_musicas; i++) {
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
