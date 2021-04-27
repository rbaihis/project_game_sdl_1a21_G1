#include "fullgame.h" 
#include "option.h" 
#include "jouer.h" 
#include  "SousMenu.h"

int main()
{
 int a=1,b=0,c=0,move=6;
 
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | 
SDL_INIT_TIMER )!=0) 
        {
           printf("Unable to initialize SDL : %s \n",SDL_GetError());
          return 1;
         }  
         
int screen_w=1400,screen_h=600;
SDL_Surface *screen=NULL;


SDL_WM_SetCaption("My Game Window",NULL);
screen=SDL_SetVideoMode( screen_w,screen_h,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE /*  |SDL_FULLSCREEN */);

SDL_Surface *image_play=NULL,*image_option=NULL,*image_quit=NULL,*image_background=NULL,*image_animation=NULL,*image_animation1=NULL,*texte=NULL,*texte1=NULL,*texte2=NULL,*texte3=NULL,*texte4=NULL,*image_load=NULL,*image_multi=NULL,*image_control ; 

SDL_Rect pos_background,back,back1,positionFont,positionFont1,positionFont2,positionFont3,positionFont4,pos_play,pos_option,pos_quit,pos_load,pos_multi,pos_control;


SDL_Event  event; // input events

Mix_Music *music=NULL;
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
               
music=Mix_LoadMUS("resources/shower.mp3");                 
Mix_PlayMusic(music,-1); //     -1 => infinite loop the song
Mix_Chunk *sound=NULL;

// text
TTF_Init();
TTF_Font *police=NULL,*police1=NULL  ;
SDL_Color  colorchoice,colorchoice1;

police1=TTF_OpenFont("resources/Plankton.ttf",30); 
colorchoice1.r=0; 
colorchoice1.g=0; 
colorchoice1.b=0;
texte1=TTF_RenderText_Blended(police1,"J=Jouer",colorchoice1);
texte2=TTF_RenderText_Blended(police1,"O=Option",colorchoice1);
texte3=TTF_RenderText_Blended(police1,"Q=Quitter",colorchoice1);
texte4=TTF_RenderText_Blended(police1,"F=Full Screen",colorchoice1);


police=TTF_OpenFont("resources/VL.otf",90); 
colorchoice.r=254; 
colorchoice.g=163; 
colorchoice.b=71;
texte=TTF_RenderText_Blended(police,"M E N U",colorchoice);



//fin text
//images
image_background=IMG_Load("resources/background.png"); 
image_animation=IMG_Load("resources/1.png");
image_animation1=IMG_Load("resources/2.png");


        // chargement images d boutons de menu        
image_play=IMG_Load("resources/play.png"); 

image_option=IMG_Load("resources/option.png"); 

image_quit=IMG_Load("resources/quit.png");

image_load=IMG_Load("resources/loada.png");

image_multi=IMG_Load("resources/multa.png");

image_control=IMG_Load("resources/csa.png");

back1.y=660;

      sound=Mix_LoadWAV("resources/sound1.wav");
 // boucle menu principal 
while(a==1)
{


while(SDL_PollEvent(&event)) 
 {
 switch(event.type ) 
   { 
  case SDL_QUIT:  
      a=0;
       break;

   case SDL_KEYDOWN:  
     switch(event.key.keysym.sym)
     {
       case SDLK_ESCAPE : 
       case SDLK_q: 
         a=0;   
       break ;
      
      case SDLK_j:
      

	  Mix_PlayChannel(-1,sound,0);
	  c=1;
	  jouer( &c ,&a, screen); //appel de la fonction jouer
      break;
      
      
      case SDLK_o:   
 
	  Mix_PlayChannel(-1,sound,0);
	  b=1;
	  option(&b,&a, screen, &screen_w, &screen_h); //appel de la fonction options
	  
      break;
      
      case SDLK_f:
      SDL_WM_ToggleFullScreen( screen); //full screen
      break;
      
      
            case SDL_VIDEORESIZE:
               screen_w = event.resize.w;
               screen_h = event.resize.h;
               break;
     }
       break; 
       
    
      
   case SDL_MOUSEMOTION:  
    if (  event.motion.x>pos_play.x && event.motion.x<pos_play.x+pos_play.w && event.motion.y>pos_play.y && event.motion.y<pos_play.y+pos_play.h)
    {    
    image_play=IMG_Load("resources/play+.png");
    SDL_BlitSurface(image_play,NULL,screen,&pos_play);

    Mix_PlayChannel(-1,sound,0);  
    }
      else if  (  event.motion.x>pos_option.x && event.motion.x<pos_option.x+pos_option.w &&     event.motion.y>pos_option.y && event.motion.y<pos_option.y+pos_option.h)
    {
     
     image_option=IMG_Load("resources/option+.png");
    SDL_BlitSurface(image_option,NULL,screen,&pos_option);

    Mix_PlayChannel(-1,sound,0); 
    }       
    else if (  event.motion.x>pos_quit.x && event.motion.x<pos_quit.x+pos_quit.w && event.motion.y>pos_quit.y && event.motion.y<pos_quit.y+pos_quit.h)
    {
    image_quit=IMG_Load("resources/quit+.png");
    SDL_BlitSurface(image_quit,NULL,screen,&pos_quit);
 
    Mix_PlayChannel(-1,sound,0);
    break;
    }       
else if (  event.motion.x>pos_load.x && event.motion.x<pos_load.x+pos_load.w && event.motion.y>pos_load.y && event.motion.y<pos_load.y+pos_load.h)
    {
    image_load=IMG_Load("resources/loadb.png");
    SDL_BlitSurface(image_load,NULL,screen,&pos_load);
 
    Mix_PlayChannel(-1,sound,0);
    break;
    }       

else if (  event.motion.x>pos_multi.x && event.motion.x<pos_multi.x+pos_multi.w && event.motion.y>pos_multi.y && event.motion.y<pos_multi.y+pos_multi.h)
    {
    image_multi=IMG_Load("resources/multb.png");
    SDL_BlitSurface(image_multi,NULL,screen,&pos_multi);
 
    Mix_PlayChannel(-1,sound,0);
    break;
    }       

else if (  event.motion.x>pos_control.x && event.motion.x<pos_control.x+pos_control.w && event.motion.y>pos_control.y && event.motion.y<pos_control.y+pos_control.h)
    {
    image_control=IMG_Load("resources/csb.png");
    SDL_BlitSurface(image_control,NULL,screen,&pos_control);
 
    Mix_PlayChannel(-1,sound,0);
    break;
    }       

     else 
    {    
    image_play=IMG_Load("resources/play.png");  
    SDL_BlitSurface(image_play,NULL,screen,&pos_play);

    image_option=IMG_Load("resources/option.png");  
    SDL_BlitSurface(image_option,NULL,screen,&pos_option);
    
    image_quit=IMG_Load("resources/quit.png");
    SDL_BlitSurface(image_quit,NULL,screen,&pos_quit); 

    image_load=IMG_Load("resources/loada.png");
    SDL_BlitSurface(image_load,NULL,screen,&pos_load);

    image_multi=IMG_Load("resources/multa.png");
    SDL_BlitSurface(image_multi,NULL,screen,&pos_multi);

   image_control=IMG_Load("resources/csa.png");
    SDL_BlitSurface(image_control,NULL,screen,&pos_control);
    }   
    break;
  
     case SDL_MOUSEBUTTONUP:
      if (event.button.button == SDL_BUTTON_LEFT && ( event.motion.x>pos_play.x && event.motion.x<pos_play.x+pos_play.w && event.motion.y>pos_play.y && event.motion.y<pos_play.y+pos_play.h ) ) 
         {
            c=1;
            jouer( &c ,&a, screen);
         }
     
       else if ( event.button.button == SDL_BUTTON_LEFT &&  ( event.motion.x>pos_option.x && event.motion.x<pos_option.x+pos_option.w &&     event.motion.y>pos_option.y && event.motion.y<pos_option.y+pos_option.h ) )
       
       {
       
 
	  Mix_PlayChannel(-1,sound,0);
	  b=1;
	  option(&b,&a, screen, &screen_w, &screen_h);
          
       }
       
       else if ( event.button.button == SDL_BUTTON_LEFT && (event.motion.x>pos_quit.x && event.motion.x<pos_quit.x+pos_quit.w && event.motion.y>pos_quit.y && event.motion.y<pos_quit.y+pos_quit.h) )
       {
          a=0;
       }
       
       break;
     
      }
     
     } 






pos_background.y=0;  
pos_background.x=0;
SDL_BlitSurface(image_background,NULL,screen,&pos_background); 





positionFont1.x=1250; 
positionFont1.y= 260; 
SDL_BlitSurface(texte1 ,NULL,screen,&positionFont1);



positionFont2.x=1250; 
positionFont2.y= 310; 
SDL_BlitSurface(texte2 ,NULL,screen,&positionFont2); 


positionFont3.x=1250; 
positionFont3.y= 360; 
SDL_BlitSurface(texte3 ,NULL,screen,&positionFont3); 


positionFont4.x=1250; 
positionFont4.y= 410; 
SDL_BlitSurface(texte4 ,NULL,screen,&positionFont4);
 

positionFont.x=(screen_w-positionFont.w)/2-10; 
positionFont.y= (screen_h-positionFont.h)/14; 
SDL_BlitSurface(texte ,NULL,screen,&positionFont); 



back.y+= move;         
back.x=180; 
SDL_BlitSurface(image_animation,NULL,screen,&back);
if(back.y>600)
     {
      back.y= (-60);
      back.y+=move;
     } 
     

back1.y -= move;         
back1.x=20; 

if(back1.y <0)
     {
      back1.y= (700);
      back1.y-=move;
     } 
  SDL_BlitSurface(image_animation1,NULL,screen,&back1);
                           
 pos_play.x= 450;
 pos_play.y= 0+positionFont.h+110;  
 SDL_BlitSurface(image_play,NULL,screen,&pos_play);
 
 pos_load.x= 450;
 pos_load.y= 0+positionFont.h+220;  
 SDL_BlitSurface(image_load,NULL,screen,&pos_load);

 pos_option.x= 450;
 pos_option.y= 0+positionFont.h+330;
 SDL_BlitSurface(image_option,NULL,screen,&pos_option);    

 pos_control.x= 700;
 pos_control.y= 0+positionFont.h+110;  
 SDL_BlitSurface(image_control,NULL,screen,&pos_control);

 pos_multi.x= 700;
 pos_multi.y= 0+positionFont.h+220;  
 SDL_BlitSurface(image_multi,NULL,screen,&pos_multi);

 pos_quit.x= 700;
 pos_quit.y= 0+positionFont.h+330;
 SDL_BlitSurface(image_quit,NULL,screen,&pos_quit);

SDL_Delay(1000/60);  
               // mise a jour
 SDL_Flip(screen);
     
}// end while c " menu " 


       // free memory
TTF_CloseFont(police);
TTF_Quit();
Mix_FreeMusic(music);
Mix_FreeChunk(sound);
SDL_Quit;


return 0;
 
} 


