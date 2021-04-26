/** 
* @file enigme.c
* @brief testing
* @author volta
* @version 0.1 
* @date Apr 20, 2021  
*/

#include "header.h"




/** 
* @brief To generate enigme
* @param ch chaine 
* @param n2 entier alea
* @return enigme 
*/ 

enigme generer(char *ch,enigme e,SDL_Surface *screen,int *n2)
{int i=0;


e.colorchoice.r=255; 
e.colorchoice.g=255; 
e.colorchoice.b=255; 
e.police=TTF_OpenFont("font.ttf",19);
e.texte=TTF_RenderText_Blended(e.police,"(Type A , B , or C)",e.colorchoice); //instructions 
e.positionFont.x=160; 
e.positionFont.y= 350; 
SDL_BlitSurface(e.texte ,NULL,screen,&e.positionFont);
SDL_Flip(screen);




FILE*fichier=NULL;
    fichier=fopen(ch,"r"); //ouverture du fichier

    if(fichier!=NULL)
    {
           while(i<1) //prendre une ligne du fichier selon n 
            {fgets(e.q,65,fichier);
              i++;
            }

e.colorchoice.r=255; 
e.colorchoice.g=255; 
e.colorchoice.b=255;
e.police=TTF_OpenFont("font.ttf",30);
e.texte=TTF_RenderText_Blended(e.police,e.q,e.colorchoice);//afficher la ligne de la question 
e.positionFont.x=230; 
e.positionFont.y= 70; 
SDL_BlitSurface(e.texte ,NULL,screen,&e.positionFont);
SDL_Flip(screen); 

while(i<4) //prendre les 3 reponses
            {fgets(e.r1,30,fichier);
              i++;
fgets(e.r2,30,fichier);
              i++;
fgets(e.r3,30,fichier);
              i++;
            }


   fclose(fichier);
}

i=1;
     




*n2=alea2();
if(*n2==1)
{e.positionFont1.x=250; 
e.positionFont1.y= 130; 
e.positionFont2.x=250; 
e.positionFont2.y= 200; 
e.positionFont3.x=250; 
e.positionFont3.y= 270;
}
else if(*n2==2)
{e.positionFont1.x=250; 
e.positionFont1.y= 270; 
e.positionFont2.x=250; 
e.positionFont2.y= 130; 
e.positionFont3.x=250; 
e.positionFont3.y= 200;

}
else
{e.positionFont1.x=250; 
e.positionFont1.y= 200; 
e.positionFont2.x=250; 
e.positionFont2.y= 270; 
e.positionFont3.x=250; 
e.positionFont3.y= 130;

}

e.colorchoice.r=68; 
e.colorchoice.g=217; 
e.colorchoice.b=240;
e.police=TTF_OpenFont("font.ttf",30);
e.texte=TTF_RenderText_Blended(e.police,e.r1,e.colorchoice);//afficher rep 1

SDL_BlitSurface(e.texte ,NULL,screen,&e.positionFont1);

e.colorchoice.r=68; 
e.colorchoice.g=217; 
e.colorchoice.b=240;
e.police=TTF_OpenFont("font.ttf",30);
e.texte=TTF_RenderText_Blended(e.police,e.r2,e.colorchoice);//afficher rep 2

SDL_BlitSurface(e.texte ,NULL,screen,&e.positionFont2);

e.colorchoice.r=68; 
e.colorchoice.g=217; 
e.colorchoice.b=240;
e.police=TTF_OpenFont("font.ttf",30);
e.texte=TTF_RenderText_Blended(e.police,e.r3,e.colorchoice);//afficher rep 3
 
SDL_BlitSurface(e.texte ,NULL,screen,&e.positionFont3);
SDL_Flip(screen); 
return e;
}

/** 
* @brief To generate enigme
* @param ch chaine 
* @param n2 entier alea
* @return enigme 
*/ 

void afficher(SDL_Surface *screen,enigme e)
{


e.image1=IMG_Load("back.jpg"); //afficher le background
e.positionEcran.x=0; 
e.positionEcran.y=0; 
SDL_BlitSurface(e.image1,NULL,screen,&e.positionEcran);
SDL_Flip(screen); 

e.colorchoice.r=255; 
e.colorchoice.g=255; 
e.colorchoice.b=255;  
e.police=TTF_OpenFont("font.ttf",30); 
e.texte=TTF_RenderText_Blended(e.police,"A)",e.colorchoice);//a
e.positionFont.x=220; 
e.positionFont.y= 130; 
SDL_BlitSurface(e.texte ,NULL,screen,&e.positionFont);
e.colorchoice.r=255; 
e.colorchoice.g=255; 
e.colorchoice.b=255; 
e.police=TTF_OpenFont("font.ttf",30); 
e.texte=TTF_RenderText_Blended(e.police,"B)",e.colorchoice);//b
e.positionFont.x=220; 
e.positionFont.y= 200; 
SDL_BlitSurface(e.texte ,NULL,screen,&e.positionFont);
e.colorchoice.r=255; 
e.colorchoice.g=255; 
e.colorchoice.b=255;  
e.police=TTF_OpenFont("font.ttf",30); 
e.texte=TTF_RenderText_Blended(e.police,"C)",e.colorchoice);//c
e.positionFont.x=220; 
e.positionFont.y= 270; 
SDL_BlitSurface(e.texte ,NULL,screen,&e.positionFont);
SDL_Flip(screen); 
}

/** 
* @brief To generate enigme
* @param ch chaine 
* @param n2 entier alea
* @return enigme 
*/ 
//initialiser srand
void init_alea(unsigned int n)
{
    srand(n);
}
//generation d'un nombre aléatoire entre min et max

/** 
* @brief To generate enigme
* @param ch chaine 
* @param n2 entier alea
* @return enigme 
*/ 
int alea()
{       init_alea((unsigned)time(NULL));
    return (rand()%(4))+1;
}
/** 
* @brief To generate enigme
* @param ch chaine 
* @param n2 entier alea
* @return enigme 
*/ 
int alea2()
{       init_alea((unsigned)time(NULL));
    return (rand()%(3))+1;
}
/** 
* @brief To generate enigme
* @param ch chaine 
* @param n2 entier alea
* @return enigme 
*/ 
void free_memory(TTF_Font *police,SDL_Surface *texte,Mix_Chunk *sound)//liberer l espace
{TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface( texte );
Mix_FreeChunk(sound);
SDL_Quit;
}



