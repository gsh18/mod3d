//***************************************************//
//  GIANFRANCO DE SOUZA HARRES      - GRR: 20180103  //
//  VINICIUS AUGUSTO DILAY DE PAULA - GRR: 20182597  //
//***************************************************//
//                   OBJREAD.C                       //
//***************************************************//
//              Leitura do arquivo .obj              //
//***************************************************//

#include "objread.h"

// extrai um float entre ' ' (espacos) de uma string
float ext_number (int i, char *line) {
    int j = 0;
    char semiline[100];
    int check = 0;
    i++;

    // limpa semiline pra evitar lixos de memoria
    strcpy(semiline,"");

    while ((line[i] != ' ') && (line[i] != '\n') && (line[i] != '/')) {
        semiline[j] = line[i];
        j++;
        i++;
        check++;
    }
    semiline[j] = '\0';
    if (check == 0) return -1;
    else return(atof(semiline));
    }


    //Faz o Parsing para as faces
void write_face (char *line,struct face *fc) {
    int i = 1;

    while (line[i] != '\n') {
        if ((line[i] == ' ')) {
            fc->faces[fc->tam] = ext_number(i,line);
            fc->tam++;
        }
        i++;
    }
}


//Faz o parsing para os vertices
void write_vert (char *line, struct vertice *vtc) {
    float num;
    int i = 0;

    while (line[i] != '\n') {
        if ((line[i] == ' ')) {

            num = ext_number(i,line);

            while (num == -1) num = ext_number(i,line);

            switch (vtc->v) {
                case 0:
	               vtc->x = num;
	               vtc->v++;
	            break;

                case 1:
	               vtc->y = num;
	               vtc->v++;
                break;

                case 2:
	               vtc->z = num;
	               vtc->v++;
	            break;
            }
        }
        i++;
    }
}


//Le arquivo recebido
void read_obj(int c, char **v,face_t *fac, vert_t *vtc) {
    FILE *fp;
    size_t len = 0;
    ssize_t nread;
    char *line = NULL;

    // inicializa struct faces e verts
    fac->tam = 0;
    vtc->tam = 0;

    // abre o arquivo a se inserido nas structs
    fp = fopen(v[1],"r");

    // abre o arquivo a se inserido nas structs
    if (fp == NULL) {
        fp = stdin;
    }

    while ((nread = getline(&line,&len,fp)) != -1) {
        if ((line[0] == 'v') && (line[1] == ' ')) {
            if( line[2] == ' ' )
                vtc->tam++;

            vtc->vt[vtc->tam].v = 0;              // zera 'v' do struct necessario para leitura
            write_vert(line,&vtc->vt[vtc->tam]);  // passa para a funcao o vertice da vez
            vtc->tam++;                           // indica quantos vertices foram lidos
        }
        if ((line[0] == 'f') && (line[1] == ' ')) {
            if( line[2] == ' ' )
                fac->tam++;

            write_face(line,&fac->fc[fac->tam]);
            fac->tam++;
        }
    }
}
