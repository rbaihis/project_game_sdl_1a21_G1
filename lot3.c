#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lot3.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h> 

void menu(minimap m,SDL_Rect positionbackjeu,SDL_Rect posbergila2,SDL_Rect postexte,SDL_Surface *ecran,SDL_Surface *backjeu,SDL_Surface *bergila2,SDL_Surface *texte)
{
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		SDL_BlitSurface(backjeu, NULL, ecran, &positionbackjeu);
		SDL_BlitSurface(bergila2, NULL, ecran, &posbergila2);
		afficher (m,ecran);
		SDL_BlitSurface(texte, NULL, ecran, &postexte);
		SDL_Flip(ecran);
}
					
 SDL_Rect MAJMinimap( SDL_Rect posJoueur, int redimensionnement)
{SDL_Rect posbonhomme,posJoueurABS,camera;
camera.x=400;
camera.y=90;
posJoueurABS.x = posJoueur.x + camera.x;
posJoueurABS.y = posJoueur.y + camera.y;
posbonhomme.x=posJoueurABS.x * redimensionnement/100;
posbonhomme.y=posJoueurABS.y * redimensionnement/100;



return posbonhomme;
}
void initminimap(minimap *m,SDL_Rect positionbackjeu,int redimensionnement,SDL_Rect posbergila2)
{
(*m).positionmm=MAJMinimap(positionbackjeu,redimensionnement);
(*m).posbonhomme=MAJMinimap(posbergila2,redimensionnement);


}
void afficher (minimap m, SDL_Surface *ecran)
{

SDL_BlitSurface(m.mm, NULL, ecran, &m.positionmm);
SDL_BlitSurface(m.minijoueur, NULL, ecran, &m.posbonhomme);


}
SDL_Color GetPixel(SDL_Surface *Masque,int x,int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char*)Masque->pixels;
pPosition+=(Masque->pitch *y);
pPosition+=(Masque->format->BytesPerPixel *x);
memcpy(&col,pPosition,Masque->format->BytesPerPixel);
SDL_GetRGB(col,Masque->format,&color.r,&color.g,&color.b);
return(color);

}
void Liberer (minimap *m)
{
SDL_FreeSurface((*m).minijoueur);
SDL_FreeSurface((*m).mm);
}
int collisionPP( Personne p, SDL_Surface *Masque)
{
SDL_Color color;
int collision,X,Y,W,H,x,y,i;
SDL_Rect pos[8];

X= p.posp.x;
Y= p.posp.y;
W =p.posp.w ;
H =p.posp.h;
pos[0].x=X;
pos[0].y=Y;
pos[1].x=X+W/2;
pos[1].y=Y;
pos[2].x=X+W;
pos[2].y=Y;
pos[3].x=X;
pos[3].y=Y+H/2;
pos[4].x=X;
pos[4].y=Y+H;
pos[5].x=X+W/2;
pos[5].y=Y+H;
pos[6].x=X+W;
pos[6].y=Y+H;
pos[7].x=X+W;
pos[7].y=Y+H/2;

collision=0;
i=0;
while((i<8)&&(collision==8))
{
color = GetPixel(Masque,pos[i].x,pos[i].y);
if (color.r==0 && color.g==0 && color.b==0)
collision=1;
else i++;
}
return collision;
}
/*void affichertemps(int *temps,SDL_Surface *texte,SDL_Rect position)
{
 TTF_Font *police=NULL;
SDL_Color couleurblanc = {255, 255, 255},couleurNoire = {0, 0, 0};
char time[20]="";


			(*temps)+= 5; 
            sprintf(time, "SCORE : %d", (*temps)); 
            SDL_FreeSurface(texte); 
            texte = TTF_RenderText_Shaded(police, time, couleurNoire, couleurblanc); 
           
       


			

}
*/

