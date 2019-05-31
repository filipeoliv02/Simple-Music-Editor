#include "project.h"




char ficheiro_musicas[] = "musicas.txt";// nome do ficheiro




    int menu_pr() {
    char opcao;
    do {
        printf("Escolha uma opcao entre as possiveis: \n");
        printf(" [1] Listar Informacao \n");                        //Lista as opçoes disponiveis no meunu principal assim como a opçao  para selecionar
        printf(" [2] Musicas \n");
        printf(" [3] Artistas \n");
        printf(" [4] Procurar \n");
        printf(" [s] Sair\n");
        fflush(stdin);
        scanf("%c", &opcao);
        switch (opcao) {
            case '1':
                printf("\n Todas as Informacoes \n");
                music_load();                 //carrega o ficheiro musicas.txt
                lista_todas_musicas();
                break;
            case '2':
                printf("\n Musicas \n");
                music_load();                 //carrega o ficheiro musicas.txt
                menu_music();                 //abre o menu de opcoes das musicas
                break;
            case '3':
                printf("\n Artistas\n");
                artist_load();                //carrega o ficheiro artistas.txt
                menu_artist();                //abre o menu de opcoes dos artistas
                break;
            case '4':
                menu_search();                //abre o menu de pesquisa
                break;
            case 's':
            case 'S':
                break;
            default:
                //system("cls"); // clear screen - cls windows or clear for linux/unix
                printf(" Opcao invalida!!! \n");
        }
        if (opcao != 's' && opcao != 'S') {
            printf("\n\n Prima qualquer tecla para voltar ao menu...\n");
            getchar();
        }
    } while (opcao != 's' && opcao != 'S');

    return 0;
}




void imprime_musica (struct musica *m) {                        //imprime a musica contida na estrutura - artista + titulo

        printf("%s - %s \n", m->artista, m->titulo);
}


void lista_todas_musicas() {                            //lista a informacao contida para todas as musicas no ficheiro musicas.txt
    for (int i = 0; i < music_num; i++) {
        printf("[%d] ",i+1);
        imprime_musica(&vec_musicas[i]);
    }
}

