#include "header.h"
#include "enigmesahar.h"

void initaaa(game t1[],SDL_Surface *screen)
{
 t1[0].img=IMG_Load("tictac");
 SDL_BlitSurface(t1[0].img,NULL,screen,NULL); 
}

// remplacement of initaaa(game t1[],SDL_Surface *screen)
void initenigmesahar(game t1[])
{
 t1[0].img=IMG_Load("tictac"); 
}
void affichertictac(game t1[],SDL_Surface *screen)
{
 SDL_BlitSurface(t1[0].img,NULL,screen,NULL); 
}
//---------------------------------------------------------


void initord(ord t2[])
{
int i=0;
for(i=1;i<10;i++)
{
t2[i].n=0;
}
t2[1].pos.x=88;
t2[1].pos.y=88;
t2[2].pos.x=284;
t2[2].pos.y=88;
t2[3].pos.x=480;
t2[3].pos.y=88;
t2[4].pos.x=88;
t2[4].pos.y=240;
t2[5].pos.x=284;
t2[5].pos.y=240;
t2[6].pos.x=480;
t2[6].pos.y=240;
t2[7].pos.x=88;
t2[7].pos.y=398;
t2[8].pos.x=284;
t2[8].pos.y=398;
t2[9].pos.x=480;
t2[9].pos.y=398;
}


int veriftab(ord t2[])
{int i=0;int s=0;
 for(i=1;i<10;i++)
 {
   s=t2[i].n+s;
 }
 return s;
 }

void put_x(SDL_Surface *screen,SDL_Rect pos)
{
TTF_Init();
TTF_Font *police = NULL; 
 SDL_Surface *texte1 = NULL; 
 SDL_Color couleurNoire = {0, 0, 0};
 police = TTF_OpenFont("se.ttf", 65); 
 texte1 = TTF_RenderText_Blended(police, "x", couleurNoire); 
 SDL_BlitSurface(texte1,NULL,screen,&pos);
 SDL_Flip(screen);
 }

void put_o(SDL_Surface *screen,SDL_Rect pos)
{TTF_Init();
 TTF_Font *police = NULL;
 SDL_Surface *texte1 = NULL;
 SDL_Color couleurNoire = {0, 0, 0};
 police = TTF_OpenFont("se.ttf", 65); 
 texte1 = TTF_RenderText_Blended(police, "o", couleurNoire);
 SDL_BlitSurface(texte1,NULL,screen,&pos);
 SDL_Flip(screen);
 }

void afficherWinX(SDL_Surface *screen)
{SDL_Rect pos;
TTF_Font *police = NULL;
 SDL_Surface *texte1 = NULL;
 SDL_Color couleurNoire = {0, 0, 0};
 TTF_Init();
 police = TTF_OpenFont("se.ttf", 150);
 texte1 = TTF_RenderText_Blended(police, "X WIN", couleurNoire);
pos.x=600;
pos.y=240;
 SDL_BlitSurface(texte1,NULL,screen,&pos);
 SDL_Flip(screen);
 }

void afficherWinO(SDL_Surface *screen)
{SDL_Rect pos;
TTF_Font *police = NULL;
 SDL_Surface *texte1 = NULL;
 SDL_Color couleurNoire = {0, 0, 0};
 TTF_Init();
 police = TTF_OpenFont("se.ttf", 150);
 texte1 = TTF_RenderText_Blended(police, "O WIN", couleurNoire);
pos.x=600;
pos.y=240;
 SDL_BlitSurface(texte1,NULL,screen,&pos);
 SDL_Flip(screen);
 }

int chekwin(int t3[],SDL_Surface *screen,int t4[])
{
if(((t3[1]+t3[2]+t3[3])==3) || ((t3[4]+t3[5]+t3[6])==3) || ((t3[7]+t3[8]+t3[9])==3) || ((t3[3]+t3[5]+t3[7])==3) || ((t3[1]+t3[5]+t3[9])==3) || ((t3[1]+t3[4]+t3[7])==3) || ((t3[2]+t3[5]+t3[8])==3) || ((t3[3]+t3[6]+t3[9])==3))
{afficherWinX(screen);
return 1;}
else
if(((t4[1]+t4[2]+t4[3])==3) || ((t4[4]+t4[5]+t4[6])==3) || ((t4[7]+t4[8]+t4[9])==3) || ((t4[3]+t4[5]+t4[7])==3) || ((t4[1]+t4[5]+t4[9])==3) || ((t4[1]+t4[4]+t4[7])==3) || ((t4[2]+t4[5]+t4[8])==3) || ((t4[3]+t4[6]+t4[9])==3))
{afficherWinO(screen);
return -1;
}
}
