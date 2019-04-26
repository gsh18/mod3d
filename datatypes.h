//***************************************************//
//  GIANFRANCO DE SOUZA HARRES      - GRR: 20180103  //
//  VINICIUS AUGUSTO DILAY DE PAULA - GRR: 20182597  //
//***************************************************//
//                  DATATYPES.H                      //
//***************************************************//

#ifndef __DATATYPES__
#define __DATATYPES__

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAMF 70000
#define TAMV 35000
#define ALT 600
#define LARG 800
#define PI 3.141592653589793238

// struct do vertice
struct vertice {
  int v;    //usado para leitura

  //coordenadas
  double x;
  double y;
  double z;
};

// struct das projecoes
typedef struct pers {
    double x;
    double y;
} persp_t;

//struct da camera
typedef struct camera {
    //coordenadas
    float x;
    float y;
    float z;
    //angulos para calculo
    float ang1;
    float ang2;
} cam_t;

//struct da face
struct face {
  int tam;  //num de arestas da face
  int faces[5]; //contem as faces
};

//structs das faces
typedef struct faces {
  struct face fc[TAMF];
  int tam;
} face_t;

//struct dos vertices
typedef struct vertices {
  struct vertice vt[TAMV];
  int tam;
} vert_t;

#endif
