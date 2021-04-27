#include "fullgame.h" 
#include  "jouer.h"
#include "SousMenu.h"

void jouer(int *c ,int *a, SDL_Surface *screen)
{
SM s;
int i,d=0;
SDL_Surface * image_game;
Mix_Chunk *sound=NULL;
SDL_Event  event;
sound=Mix_LoadWAV("resources/sound1.wav");
image_game=IMG_Load("resources/hello.png");
 if(*c==1)
{
while(*c==1)
{
 
       
    while(SDL_PollEvent(&event)) 
 {
 switch(event.type ) 
   { 
   case SDL_QUIT:  
      *c=0;
      *a=0;
       break;
       //------------------------
   case SDL_KEYDOWN:  
     switch(event.key.keysym.sym)
     {
       case SDLK_ESCAPE :


Afficher_SM(s,screen,i);



    break;
 
       case SDLK_q: 
         *c=0;   
         
	  Mix_PlayChannel(-1,sound,0);
       break ;
     } 
       break; 
      //---------------------------          
   }

 }






  
    SDL_BlitSurface(image_game,NULL,screen,NULL);
    SDL_Flip(screen); 
}
}

}
