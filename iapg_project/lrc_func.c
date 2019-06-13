#include "project.h"


char lrc_file[] = "musicas/Bon Jovi - Always.lrc";      /// nome do ficheiro

/*!
 *
 * @brief
 * carrega o ficheiro com as letras
 *
 */

void lrc_load(struct musica *m) {
    FILE *fp;
    int i = 0;
    char linha[100], file_path[100];
    m->num_letras = 0;

    sprintf(file_path, "musicas/%s - %s.lrc", m->artista, m->titulo);
    fp = fopen(file_path, "r");
    if (fp != NULL) {
        while (fgets(linha, sizeof(linha), fp)) {
            if (linha[strlen(linha) - 2] != ']') {
                i = m->num_letras;


                sscanf(linha, "[%d:%d.%d]%[^\n]s", &m->letras[i].min, &m->letras[i].seg, &m->letras[i].cs,
                       m->letras[i].texto);


                m->num_letras++;
            }

        }
        fclose(fp);
    }
}

