#include "funcoes.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM_NOME 50	    // tamanho max de char na string - MACRO
#define TAM_VECTOR 50	// numero de musicas que podem ser armazenadas em memoria


// estruturas permitem definir novos tipos de dados - tipo de dados neste caso ira ter o nome musica - e composto por duas strings, titulo e artista
struct musica {
    char titulo[TAM_NOME];
    char artista[TAM_NOME];
};

void lista_todas_musicas();
void imprime_musica(struct musica * m);
void ler_nova_musica(struct musica * m);
void gravar_musicas_para_ficheiro();
void carregar_musicas_do_ficheiro();
void le_input(char * temp);

// variaveis globais

struct musica vec_musicas[TAM_VECTOR]; 	// inicializa-se com a estrutura criada acima um vector de musicas
int num_musicas=0; 			// numero de musicas no vector
char ficheiro_musicas[] = "musicas.txt";// nome do ficheiro

int menu() {
    char op;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1]Listar musicas \n");
        printf(" [2]Inserir nova musica \n");
        printf(" [3]Gravar musicas para ficheiro \n");
        printf(" [4]Carregar musicas do ficheiro para a memoria \n");
        printf(" [S]Sair \n");
        fflush(stdin);
        scanf("%c", &op);
        switch (op) {
            case '1':
                printf("\nmenu 1\n");
                printf("ffsddf444s");
                lista_todas_musicas();
                break;
            case '2':
                printf("\nmenu 2\n");
                ler_nova_musica(&vec_musicas[num_musicas]);
                num_musicas++; // aumenta o numero de musicas no vector
                break;
            case '3':
                printf("\nmenu 3\n");
                gravar_musicas_para_ficheiro();
                break;
            case '4':
                printf("\nmenu 4\n");
                carregar_musicas_do_ficheiro();
                break;
            case 's':
            case 'S':
                break;
            default:
                //system("cls"); // clear screen - cls windows or clear for linux/unix
                printf("Opcao invalida!!!\n");
        }
        if (op!='s' && op!='S') {
            printf("\n\nprima qualquer tecla para voltar ao menu...");
            getchar();
        }
    }  while (op!='s' && op!='S');

    return 0;
}

void imprime_musica(struct musica * m) {
    /*
    * POR FAZER - esta funcao deve imprimir a musica contida na estrutura - titulo + artista
    */
}

void le_input(char * temp){
    char input[TAM_NOME];
    /*
    * POR FAZER - esta funcao deve ler uma string escrita pelo utilizador no terminal, e guarda-la em temp
    */
}

void lista_todas_musicas() {
    /*
    * POR FAZER - esta funcao deve percorrer o vector de musicas e imprimir a respectiva informacao de cada musica
    */
}

void ler_nova_musica(struct musica * m) {

    getchar();
    printf("Insira o titulo da musica:");

    le_input(m->titulo);
    printf("Insira o artista:");

    le_input(m->artista);


}


void gravar_musicas_para_ficheiro() {
    FILE * fp;
    int i;
    fp = fopen(ficheiro_musicas, "w");
    if (fp != NULL) {
        fprintf(fp,"musicas: %d\n",num_musicas);
        for (i=0; i<num_musicas; i++) {
            fprintf(fp,"titulo: %s\n", vec_musicas[i].titulo);
            fprintf(fp,"artista: %s\n", vec_musicas[i].artista);
        }
        fclose(fp);
    }
}

void carregar_musicas_do_ficheiro() {
    FILE * fp;
    int i=0;
    char linha[TAM_NOME];
    num_musicas = 0;
    fp = fopen(ficheiro_musicas, "r");
    if (fp != NULL) {
        fscanf(fp,"%*s %d\n", &num_musicas); 			// ignore the string and store only the int
        for (i=0; i<num_musicas; i++) {
            fgets(linha,sizeof(linha),fp); 			// titulo
            linha[strlen(linha)-1]=0; 				// retira quebra de linha
            strcpy(vec_musicas[i].titulo, &linha[8]); 		// titulo começa no 8º char
            fgets(linha,sizeof(linha),fp); 			// artista
            linha[strlen(linha)-1]=0; 				// retira quebra de linha
            strcpy(vec_musicas[i].artista, &linha[9]); 		// artista começa no 9º char
        }
        fclose(fp);
    }
}
