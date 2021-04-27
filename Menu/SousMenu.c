#include "fullgame.h" 
#include  "SousMenu.h"

SM init_SM(SM s)
{
//inuit background sous menu
s.backsm=IMG_Load("resources/backsm.jpg"); 
//init les 4 boutons 
s.image1=IMG_Load("resources/savea.png"); 
s.image2=IMG_Load("resources/saveb.png");  
s.image3=IMG_Load("resources/resumea.png");
s.image4=IMG_Load("resources/resumeb.png");  
//init pos background
s.positionbacksm.x=415;
s.positionbacksm.y=0;
//init pos boutons
s.posa.x=571;
s.posa.y=150;
s.posb.x=571;
s.posb.y=350;

//init son bref
s.sound=Mix_LoadWAV("resources/sound1.wav");
//init son continu
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);            
s.music=Mix_LoadMUS("resources/music.mp3"); 
//les numeros des images
s.n_bouton1=1;
s.n_bouton2=2;
//init bouton actif
s.n_actif=1;
return s;
}

void Afficher_SM(SM s,SDL_Surface *screen,int i)
{int d=1;
i=0;
s=init_SM(s);
Mix_PlayChannel(-1,s.sound,0);
Mix_PlayMusic(s.music,-1);
SDL_BlitSurface(s.backsm,NULL,screen,&s.positionbacksm);
SDL_Flip(screen);
while(d==1)
{
  while(SDL_PollEvent(&s.event)) 
 {
 switch(s.event.type ) 
   { 
   case SDL_QUIT:  
      
      d=0;
       break;

case SDL_KEYDOWN:  
 i=update_SM(s,&s.n_actif); //C'est l'interface
}
}
if(i==1)
d=0;
switch(s.n_actif)
{case 1 :
SDL_BlitSurface(s.image2,NULL,screen,&s.posa);
SDL_BlitSurface(s.image3,NULL,screen,&s.posb);
SDL_Flip(screen);
break;
case 2 :
SDL_BlitSurface(s.image1,NULL,screen,&s.posa);
SDL_BlitSurface(s.image4,NULL,screen,&s.posb);
SDL_Flip(screen);
break;

}
SDL_Flip(screen);
}

liberer_SM(s.sound,s.music);

}


int update_SM(SM s,int *g) //g est l'input
{

 switch(s.event.key.keysym.sym)
     {
       
       /*case SDLK_q: 
         a=0;   
       break ;*/
case SDLK_UP: 
           if(*g==1)
*g=2;
else
*g=1;
       break ;
case SDLK_DOWN: 
         if(*g==1)
*g=2;
else
*g=1;
       break ;
case SDLK_RETURN :
if(*g==1)
return -1;
else
return 1;

break;


}




}


void liberer_SM(Mix_Chunk *sound,Mix_Music *music)
{
Mix_FreeChunk(sound);
SDL_Quit;
Mix_FreeMusic(music);
}

/*Sauvegarde_jeu(char *ch)
{


FILE*fichier=NULL;
    fichier=fopen(ch,"w"); //ouverture du fichier

    if(fichier!=NULL)
    {
           


   fclose(fichier);
}


}

Load_game(char *ch)
{
FILE*fichier=NULL;
    fichier=fopen(ch,"r"); //ouverture du fichier

    if(fichier!=NULL)
    {
           


   fclose(fichier);
}



}*/




