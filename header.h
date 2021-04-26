#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include "ennemi.h"
#include "perso.h"
#include "background.h"
#include "enigme.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>



typedef SDL_Surface surface;
typedef SDL_Rect rect;
typedef SDL_Event event;



//basic_initial // hethom ye5dmou
//-_-_-_--_-_--_-_-_--_-__-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
int init_sdl();
void set_screen_void(SDL_Surface ** screen,int width,int height);
void quit_event(SDL_Event *event , int * loop);
// a suuprimer
/*
void loadbg(background *back);  // init backg to be deleted 
void blitbg(background *back,SDL_Surface *ecran); //blit backg to be deleted
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_--_-_-_-_-_-_-_-_
*/

#endif //  #include "header.h"
