//***************************************************//
//  GIANFRANCO DE SOUZA HARRES      - GRR: 20180103  //
//  VINICIUS AUGUSTO DILAY DE PAULA - GRR: 20182597  //
//***************************************************//
//                   GRAPHICS.C                      //
//***************************************************//
//                 Funcoes graficas                  //
//***************************************************//

#include "graphics.h"
#include "datatypes.h"

//realiza a conversao para os pontos 'caberem' na tela
void converte( persp_t *p, vert_t *v) {

    double maiorx = p[0].x;
    double menorx = p[0].x;
    double xcen, xdif, escx;

    double ycen, ydif, escy;
    double maiory = p[0].y;
    double menory = p[0].y;

    double escala;

//Passo 1
    for (int i = 1; i < v->tam; i++) {
        if (p[i].x > maiorx)
            maiorx = p[i].x;
        else if (p[i].x < menorx)
            menorx = p[i].x;

        if (p[i].y > maiory)
            maiory = p[i].y;
        else if(p[i].y < menory)
            menory = p[i].y;

    }

//Passo 2
    xcen = (maiorx + menorx) /2;
    ycen = (maiory + menory) /2;
    xdif = maiorx - menorx;
    ydif = maiory - menory;
    escx = LARG / xdif;
    escy = ALT / ydif;

   	if (escx < escy)
   		escala = escx ;
   	else
   		escala = escy ;

//Passo 3, 4 e 5
    for (int j = 0; j < v->tam; j++) {
        p[j].x = ((p[j].x - xcen) * escala)+  LARG /2 ;
        p[j].y = ((p[j].y - ycen) * escala)+ ALT / 2;
    }
}



// imprime a figura na tela
void imp_fig(persp_t *p, face_t *f, SDL_Renderer *renderer){
    int flag = 0;

    for(int i = 0; i < f->tam; i++){
        for (int j = 0; j < f->fc[i].tam; j++){
            if ((f->fc[i].faces[j]!= 0) && (f->fc[i].faces[j+1] != 0))
                lineRGBA(renderer,
                        p[f->fc[i].faces[j] - 1].x,
                        p[(f->fc[i].faces[j])-1].y,
                        p[(f->fc[i].faces[j+1]) -1].x,
                        p[(f->fc[i].faces[j+1]) -1].y, 0, 0, 0, 60);
            else if (!flag){
                lineRGBA(renderer,
                        p[f->fc[i].faces[j] -1 ].x,
                        p[f->fc[i].faces[j] -1].y,
                        p[f->fc[i].faces[0] -1].x,
                        p[f->fc[i].faces[0] -1].y, 0, 0, 0, 60);
                flag = 1;
            }
        }
    }
}
