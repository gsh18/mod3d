//***************************************************//
//  GIANFRANCO DE SOUZA HARRES      - GRR: 20180103  //
//  VINICIUS AUGUSTO DILAY DE PAULA - GRR: 20182597  //
//***************************************************//
//                   PERSPECT.H                      //
//***************************************************//
//          Calculos para impressao na tela          //
//***************************************************//

#ifndef __perspect__
#define __perspect__

#include "datatypes.h"

//Calculo da perspectiva
void perspectiva(cam_t *cam, vert_t *v, persp_t *p );

//calcula angulo atual para a func. perspectiva
float rotacao(float a, float b);

#endif
