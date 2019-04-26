//***************************************************//
//  GIANFRANCO DE SOUZA HARRES      - GRR: 20180103  //
//  VINICIUS AUGUSTO DILAY DE PAULA - GRR: 20182597  //
//***************************************************//
//                   GRAPHICS.H                      //
//***************************************************//
//                 Funcoes graficas                  //
//***************************************************//

#ifndef __graphics__
#define __graphics__

#include "datatypes.h"

//realiza a conversao para os pontos caberem na tela
void converte( persp_t *p, vert_t *v);

// imprime a figura na tela
void imp_fig(persp_t *p, face_t *f, SDL_Renderer *renderer);


#endif
