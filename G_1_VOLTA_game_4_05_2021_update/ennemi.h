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
char *path ;
SDL_Surface * image;
SDL_Rect pos_e;  // ennemi 's position Rect


// not necessary depends how i use it.
int collision;

// necessary for random movement 
int screenheight, screenwidth;
int faster , speed ; // have to be set in main 1st
int x_vel, y_vel, x_pos, y_pos; 
//------------------------

// necessary for animation
SDL_Rect pos_s; // pos_s    used for the scrolling images of sprite sheet set 
int direction;  //      chosing wich set to display depends on the sheet is lignes 

int sprite_width; // width of sprite sheet
int sprite_height; // height of sprite sheet

int sprite_lignes;
int sprite_colonnes;
//-------------------------
}ennemi;

// *-*-*-*-Enemi_prototype_ES ---**-*-  
void initennemi(ennemi *e);//ok****
void afficher_ennemi(ennemi  e, SDL_Surface * screen);//ok***
void animer_ennemi( ennemi * e);//ok*****
void deplacer_ennemi( ennemi * es);//ok****
int  collision_bb( personne p, ennemi es);//ok*****
void deplaceria( ennemi * e, SDL_Rect pos_p );//ok*******
//----------------------------------------------------

//--------------optional
void pos_obstacle( obstacle * ob, int xpos , int ypos );
void init_object(obstacle *ob ,char * path);
void afficher_obstacle(obstacle ob, SDL_Surface * screen);





#endif //  #include "header.h"
