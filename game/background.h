#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include "header.h"
#include "perso.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
SDL_Rect  camera1, camera2;
SDL_Surface *image,*im_bg1 , *im_bg2 ;
SDL_Surface *text,*title;
SDL_Rect pos_bg,pos_right,pos_left,pos_mid,postxt,postitle;
TTF_Font *police,*police2;
Mix_Music *music;
Mix_Chunk *son;
}background;


//void intialiser_back(background *b);
void afficherBack1(background *b1, SDL_Surface * screen1,int partage);
void afficherBack2(background *b2, SDL_Surface * screen2,int partage);
//void scrolling(background *back,int direction , int pasAvancement);


//init background 
// *-*-*-*-BACKGROUND*-*-*-*-*-*-*-*-BACKGROUND*-*-*-*-*-*-*-*-*-*-
void afficher_background(background b,SDL_Surface screen);
void initialiser_background( background * b);
//scrolling depends on perso_p movements
void scrolling2(personne *p,background *back, int w, int h);
//----------- 7atta t5adem yesmin codha 

#endif //  #include "header.h"

