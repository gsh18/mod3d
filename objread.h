//***************************************************//
//  GIANFRANCO DE SOUZA HARRES      - GRR: 20180103  //
//  VINICIUS AUGUSTO DILAY DE PAULA - GRR: 20182597  //
//***************************************************//
//                   OBJREAD.H                       //
//***************************************************//
//              Leitura do arquivo .obj              //
//***************************************************//

#ifndef __objread__
#define __objread__

#include "datatypes.h"

// extrai um float entre ' ' (espacos) de uma string
float ext_number (int i, char *line);

//Faz o Parsing para as faces
void write_face (char *line,struct face *fc);

//Faz o parsing para os vertices
void write_vert (char *line, struct vertice *vtc);

//Le arquivo recebido
void read_obj(int c, char **v,face_t *fc, vert_t *vtc);

#endif
