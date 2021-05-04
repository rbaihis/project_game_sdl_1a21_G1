#ifndef ENIGMESAHAR_H_INCLUDED
#define ENIGMESAHAR_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "header.h"
/**
* @struct game 
* @brief struct for game 
*/
typedef struct
{SDL_Surface *img;/*!< surface. */
 SDL_Rect p;/*!< rectangle pos. */
 int board[9];/*!< int tab 9 cases. */
 int player;
 }game; 
 /**
 * @struct ord
 * @brief struct for ord
 */
typedef struct
{ int n;/*!< entier n<=9. */
  SDL_Rect pos;/*!< rectangle pos. */
}ord;

void initaaa(game t1[],SDL_Surface *screen);
void initord(ord t2[]);
int veriftab(ord t2[]);
void put_x(SDL_Surface *screen,SDL_Rect pos);
void put_o(SDL_Surface *screen,SDL_Rect pos);
void afficherWinX(SDL_Surface *screen);
void afficherWinO(SDL_Surface *screen);
int chekwin(int t3[],SDL_Surface *screen,int t4[]);

//-----------------replacement for initaaa
void initenigmesahar(game t1[]);
void affichertictac(game t1[],SDL_Surface *screen);

//----------------------------



#endif //  #include "fonction.h"
