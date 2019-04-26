//***************************************************//
//  GIANFRANCO DE SOUZA HARRES      - GRR: 20180103  //
//  VINICIUS AUGUSTO DILAY DE PAULA - GRR: 20182597  //
//***************************************************//
//                   PERSPECT.H                      //
//***************************************************//
//          Calculos para impressao na tela          //
//***************************************************//

#include "perspect.h"

//calcula a rotaçao atual da camera em relacao ao plano da tela
float rotacao(float i, float j) {
	float ang;

	if ( !i ){
		if(j > 0.0)
			ang = PI/2;
		else
			ang =  PI/2;
    }
    else {
		ang = atan(j/i);
		if(i < 0)
			ang += PI;
    }

	return ang;
}

//cria as projeçoes dos vertices no plano da tela
void perspectiva(cam_t *cam, vert_t *v, persp_t *p ) {

    for (int i = 0; i < v->tam ; i++) {

        //cacula rotaçao em relaçao a x
    	float angulo = rotacao(v->vt[i].x, v->vt[i].z);
    	float comp = sqrt(v->vt[i].x * v->vt[i].x + v->vt[i].z * v->vt[i].z);

    	v->vt[i].x = comp * cos(angulo + cam->ang2);
    	v->vt[i].z = comp * sin(angulo + cam->ang2);

        //calcula a rotaçao em relaçao a y
    	angulo = rotacao(v->vt[i].y, v->vt[i].z);
    	comp = sqrt(v->vt[i].y * v->vt[i].y + v->vt[i].z * v->vt[i].z);

    	v->vt[i].y = comp * cos(angulo + cam->ang1);
    	v->vt[i].z = comp * sin(angulo + cam->ang1);

    	//adiciona camera
        v->vt[i].x += cam->x;
    	v->vt[i].z += cam->z;
    	v->vt[i].y += cam->y;
;
    	p[i].x = v->vt[i].x;
    	p[i].y = v->vt[i].y;

    }
}
