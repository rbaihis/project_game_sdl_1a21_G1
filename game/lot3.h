#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <SDL/SDL.h>
=

typedef struct
{
SDL_Surface *mm;
 SDL_Rect positionmm;
SDL_Surface *minijoueur;
 SDL_Rect posbonhomme;
}minimap;
typedef struct
{SDL_Rect posp;
}Personne;

void menu(minimap m,SDL_Rect positionbackjeu,SDL_Rect posbergila2,SDL_Rect postexte,SDL_Surface *ecran,SDL_Surface *backjeu,SDL_Surface *bergila2,SDL_Surface *texte);
void initminimap(minimap *m,SDL_Rect positionbackjeu,int redimensionnement,SDL_Rect posbergila2);//bergila2=personnage principal //bergila1=pesonnage minature
SDL_Rect MAJMinimap( SDL_Rect posJoueur, int redimensionnement);
void afficher (minimap m, SDL_Surface *ecran);
void Liberer (minimap *m);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int collisionPP( Personne p, SDL_Surface *Masque);
void affichertemps(int *temps,SDL_Surface *texte,SDL_Rect position);
#endif
