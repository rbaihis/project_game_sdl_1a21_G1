#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include "header.h"
#include "perso.h"
#include "background.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


//seif   no more modification
typedef struct{
SDL_Surface * image;
SDL_Rect pos_ob; //  <== obstacle's is position rect 
SDL_Rect pos_sheet;
int screenheight, screenwidth;
int collision;
}obstacle;       //obstacle ... losing 

typedef struct{
SDL_Surface * image;
SDL_Rect pos_prize; //  <== prize is position rect 
SDL_Rect pos_sheet;
int screenheight, screenwidth;
int collision;
}prize;       // coins , hearts ......

typedef struct{
SDL_Surface * image;
SDL_Rect pos_e;  // ennemi rect for collision 
SDL_Rect pos_s; 
int direction;
int faster , speed ; // have to be set in main 1st
int x_vel, y_vel, x_pos, y_pos; 
int screenheight, screenwidth;
int collision;
}ennemi;

// *-*-*-*-Enemi_prototype_ES ---**-*-  
void initennemi(ennemi *es);//ok****
void afficher_ennemi(ennemi  es, SDL_Surface * screen);//ok***
void animer_ennemi( ennemi * es);//ok*****
void deplacer_ennemi( ennemi * es);//ok****
int collision_bb( personne p, ennemi es);//ok*****
void deplaceria( ennemi * e, SDL_Rect pos_p );//ok*******
//----------------------------------------------------
//my optional funct
void afficher_ennemi2(ennemi * es, SDL_Surface * screen); // calling animerfunction inside if used 
void deplacement_settings(ennemi * es,int s_posx ,int s_posy); // inter x and y position via parametre
void deplacement_settings2(ennemi * es,personne *p); // placing ennemi in fron of perso by just call it 


#endif //  #include "header.h"
