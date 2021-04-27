#include "header.h"


// ****************
//Functionunction
// init init init init init init init init init init init init init init init 
int init_sdl()
{
   if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER )!=0)
   {
   printf("\n error initialasing %s",SDL_GetError());
   return 0; // affec t it to the game loop to not enter in case of error;
   }else
   return 1; 
}

// init init init init init init init init init init init init init init init 

// ***set_screen ***set_screen ***set_screen ***set_screen ***set_screen 
surface * set_screen(int width,int height)
{  
   surface *screen;
   SDL_WM_SetCaption("My Game Window","VOLTA");
   screen=SDL_SetVideoMode(width,height,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
   return screen;
}
//--------
void set_screen_void(surface ** screen,int width,int height)
{  
   
   SDL_WM_SetCaption("My Game Window",NULL);
   *screen=SDL_SetVideoMode(width,height,32,SDL_HWSURFACE | SDL_DOUBLEBUF );
}
//***set_screen ***set_screen ***set_screen ***set_screen ***set_screen 

void quit_event(SDL_Event *event , int * loop) // better used in void mode
{
  switch(event->type ) 
      { 
        case SDL_QUIT:  
        *loop=0;
        // dont forget to add the other loops to quit completly the window
        break;  
        case SDL_KEYDOWN:  
          switch(event->key.keysym.sym)
           {
             case SDLK_ESCAPE : 
             case SDLK_p: 
             *loop=0;  // quit current loop only 
              break ;
           } 
        break;     
      }
}



