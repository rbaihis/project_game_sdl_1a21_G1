#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


/** 
* @struct enigme
* @brief struct for enigme
*/ 


typedef struct
{
   SDL_Surface *background;
SDL_Rect positionEcran,positionFont,positionFont1,positionFont2,positionFont3;
SDL_Surface *image1,*image2,*image3,*image4;
SDL_Surface *texte; 
TTF_Font *police; 
   SDL_Event event;
   SDL_Color colorchoice;
   char q[100];
   char r1[30];
   char r2[30];
   char r3[30];
Mix_Chunk *sound;

}enigme;



void init_alea(unsigned int n);
int alea();
int alea2();
enigme generer(char *ch,enigme e,SDL_Surface *screen,int *n2);
void afficher(SDL_Surface *screen,enigme e);
void free_memory(TTF_Font *police,SDL_Surface *texte,Mix_Chunk *sound);




#endif 
