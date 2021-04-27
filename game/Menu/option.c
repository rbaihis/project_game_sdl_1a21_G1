#include "fullgame.h" 
#include  "option.h"


void option(int *b,int * a,SDL_Surface * screen,int *screen_w,int *screen_h)
{
SDL_Event  event;
SDL_Rect pos_background2,pos_max,pos_min,pos_sound;
SDL_Surface * image_background2=NULL,*image_max=NULL,*image_min=NULL,*image_sound=NULL;

Mix_Music *music=NULL;
int m,channel,volume=100;
volume=Mix_Volume( channel, volume);
Mix_VolumeMusic(volume);  
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
               
music=Mix_LoadMUS("resources/music.mp3");                 
Mix_PlayMusic(music,-1); 
Mix_Chunk *sound=NULL; 


image_background2=IMG_Load("resources/back+.png");

image_max=IMG_Load("resources/sounddd.png");
pos_max.x=((*screen_w)-pos_max.h)/2+117-195;
pos_max.y=(*screen_h)/2+13 ; 
   
   
image_min=IMG_Load("resources/sounddd.png");
pos_min.x=((*screen_w)-pos_min.h)/2-170;
pos_min.y=(*screen_h)/2+13 ;  
   
   
image_sound=IMG_Load("resources/mute.png");
 
sound=Mix_LoadWAV("resources/sound1.wav");

  if(*b==1)
{
while(*b==1)
{    
   
 
 
  while(SDL_PollEvent(&event)) 
 {
 switch(event.type ) 
   { 
   case SDL_QUIT:  
   *b=0;
   *a=0;
    break;
   
   case SDL_KEYDOWN:  
     switch(event.key.keysym.sym)
     {
     
       case SDLK_ESCAPE :
       case SDLK_q: 
         *b=0;  
         
	  Mix_PlayChannel(-1,sound,0);
       break ;
    

           //volume up
      case SDLK_KP_PLUS : 
        if (volume < 100 )
          {
            volume += 50;
            Mix_VolumeMusic(volume);
          
            Mix_Volume( channel, volume);
	    Mix_PlayChannel(-1,sound,0);
          }
           break;
            
      case SDLK_KP_MINUS : 
        if (volume >0 )
           {
            volume -= 50;
            Mix_VolumeMusic(volume);
          
            Mix_Volume( channel, volume);
            Mix_PlayChannel(-1,sound,0);         
           }
           
            break;
     } 
       break; 
       
       //-------------------------------------------------------------------------
       case SDL_MOUSEBUTTONUP:
      if (event.button.button == SDL_BUTTON_LEFT && ( event.motion.x>pos_max.x && event.motion.x<pos_max.x+pos_max.w && event.motion.y>pos_max.y && event.motion.y<pos_max.y+pos_max.h ) ) 
         {
          if (volume < 100 )
          {
            volume += 50;
            Mix_VolumeMusic(volume);
     
            Mix_Volume( channel, volume);
	    Mix_PlayChannel(-1,sound,0);
          }
         }
     
       else if ( event.button.button == SDL_BUTTON_LEFT &&  ( event.motion.x>pos_min.x && event.motion.x<pos_min.x+pos_min.w &&     event.motion.y>pos_min.y && event.motion.y<pos_min.y+pos_min.h ) )
       
       {
          if (volume >0 )
           {
            volume -= 50;
            Mix_VolumeMusic(volume);
   
            Mix_Volume( channel, volume);
            Mix_PlayChannel(-1,sound,0);         
           }
           
           
       }
       
       
       break;
     
   }
 }
 
       
 
    SDL_BlitSurface(image_background2,NULL,screen,NULL);
    
    
    SDL_BlitSurface(image_max,NULL,screen,&pos_max);
          

    SDL_BlitSurface(image_min,NULL,screen,&pos_min); 
    
    
     pos_sound.x=((*screen_w)-pos_sound.h)/2+170;
         pos_sound.y=(*screen_h)/2+13 ; 
        
         // moving sound volume  image    
     if(volume>90)
     {
         pos_sound.x=((*screen_w)-pos_sound.h)/2+170;
         pos_sound.y=(*screen_h)/2+13 ; 
         SDL_BlitSurface(image_sound,NULL,screen,&pos_sound); 
     }
       else if(volume<30)
          {
               pos_sound.x=((*screen_w)-pos_sound.h)/2-170;
               pos_sound.y=(*screen_h)/2+13 ; 
               SDL_BlitSurface(image_sound,NULL,screen,&pos_sound); 
          }
            else
            { 
                 pos_sound.x=((*screen_w)-pos_sound.h)/2+20;
                 pos_sound.y=(*screen_h)/2+13 ; 
                 SDL_BlitSurface(image_sound,NULL,screen,&pos_sound); 
            }
                
    
    
    SDL_Flip(screen); 
    
}//end while

}//end if 

music=Mix_LoadMUS("resources/shower.mp3"); 
Mix_PlayMusic(music,-1);

}//end 
