#ifndef FONCTIONS_H_
#define FONCTIONS_H_


typedef struct 
{SDL_Surface *backsm;
SDL_Surface *image1,*image2,*image3,*image4;
SDL_Rect positionbacksm,posa,posb;
Mix_Chunk *sound; 
Mix_Music *music; 
int n_bouton1;
int n_bouton2;
int n_actif;
 SDL_Event event;

}SM;


SM init_SM(SM s);
void Afficher_SM(SM s,SDL_Surface *screen,int i);
int update_SM(SM s,int *g);
void liberer_SM(Mix_Chunk *sound,Mix_Music *music);
//Sauvegarde_jeu(char *ch);
//Load_game(char *ch);
#endif
