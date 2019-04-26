//***************************************************//
//  GIANFRANCO DE SOUZA HARRES      - GRR: 20180103  //
//  VINICIUS AUGUSTO DILAY DE PAULA - GRR: 20182597  //
//***************************************************//
//                  WIREFRAMES.C                     //
//***************************************************//
//                Funcao principal                   //
//***************************************************//

#include "datatypes.h"
#include "graphics.h"
#include "objread.h"
#include "perspect.h"

int main(int argc, char **argv) {

    SDL_Event event;
    SDL_Window *tela = NULL;
    SDL_Renderer *renderer = NULL;
    int sair = 0;   // detecta saida do loop principal
    int teste = 0;  // usada para mudança de camera

    vert_t *vtc;
    face_t *face;
    persp_t *p;
    cam_t camera;

    p = malloc (TAMV * sizeof(persp_t));
    vtc = malloc (sizeof(vert_t));
    face = malloc (sizeof(face_t));

    camera.x = 0;
    camera.y = 0;
    camera.z = 0;
    camera.ang1 = 0;
    camera.ang2 = 0;

    //inicialiazaçao da sdl e possiveis erros
    if((SDL_Init(SDL_INIT_VIDEO)==-1)) {
        printf("ERRO : SDL não pode ser inicializado,\ntente novamente.\n");
        exit(1);
    }
    tela = SDL_CreateWindow("wireframe", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, LARG, ALT, 0);
    if ( tela == NULL ) {
        printf("ERRO: a tela não pode ser criada,\ntente novamente \n");
        exit(1);
    }

    renderer = SDL_CreateRenderer(tela, -1, 0);
    if(renderer== NULL) {
        printf("ERRO : não foi possivel iniciar o renderer,\ntente novamente.\n");
        exit(1);
    }

    //deixa a tela branca
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    //le arquivo .obj
    read_obj(argc, argv, face, vtc);

    //calcula perspectiva e projeta
    perspectiva(&camera, vtc, p);
    converte(p, vtc);
    imp_fig( p, face, renderer);
    SDL_RenderPresent(renderer);

    //recebe input do teclado
    while (!sair)
     {
         SDL_WaitEvent(&event);

         switch (event.type)
         {

            case SDL_KEYDOWN:

               switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        if ((teste == 2) || (camera.ang2 < -.1))
                            camera.ang2 = 0;
                        camera.ang2 -=.0005;
                        camera.ang1 = 0;
                        teste = 1;

                        break;

                    case SDLK_RIGHT:
                        if ((teste == 1) || (camera.ang2 > .1))
                            camera.ang2 = 0;
                        camera.ang2 += .0005;
                        camera.ang1 = 0;
                        teste = 2;

                        break;

                    case SDLK_UP:
                        if ((teste == 4) || (camera.ang1 < -.1))
                            camera.ang1 = 0;
                        camera.ang1 -= .0005;
                        camera.ang2 = 0;
                        teste = 3;

                        break;

                    case SDLK_DOWN:
                        if ((teste == 3) || (camera.ang1 > .1))
                            camera.ang1 = 0;
                        camera.ang1 += .0005;
                        camera.ang2 = 0;
                        teste = 4;

                        break;
                    //ver pq nao funfou
                    case SDL_QUIT:
                       sair = 1;
                       break;

                    case SDLK_q:
                        sair = 1;
                        break;

                    case SDLK_ESCAPE:
                        sair = 1;
                        break;

                }

                // recalcula e imprime imagem na tela
                perspectiva(&camera, vtc, p);
                converte(p, vtc);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderClear(renderer);
                imp_fig( p, face, renderer);
                SDL_RenderPresent(renderer);


    /*    case SDL_MOUSEBUTTONDOWN:
            switch (event.button.button){
                case SDL_MOUSEMOTION:
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;

                std::stringstream ss;
                ss << "X: " << mouseX << " Y: " << mouseY;

                SDL_SetWindowTitle(window, ss.str().c_str());
                break;
            }
        break;*/
         }

     }

//TEMPORARIO PARA TESTE DE LEITURA
/*
  for (int i = 0; i < face->tam; i++) {
    printf("%d %d %d %d\n",face->fc[i].faces[0], face->fc[i].faces[1], face->fc[i].faces[2], face->fc[i].faces[3]);
  }
  for (int i = 0; i < vtc->tam; i++) {
    printf("%f %f %f \n", vtc->vt[i].x, vtc->vt[i].y,vtc->vt[i].z);
  }
*/


//destroi tela e coisas do sdl
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(tela);
    SDL_Quit();
    return 0;
}
