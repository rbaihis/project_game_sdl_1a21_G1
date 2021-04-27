#include "header.h"


void initialiser_background( background * b)
{
   b->image=IMG_Load("stage1.png");
   b->pos_bg.x=0;
   b->pos_bg.y=0;
   b->pos_bg.h=b->image->h;
   b->pos_bg.w=b->image->w;
}

void afficher_background(background b,SDL_Surface  screen)
{
    SDL_BlitSurface(b.image,&b.pos_bg,&screen,NULL);
}

//****************************************************************************
void scrolling2(personne *p,background *back, int w, int h)
{   

	float one_fourth_w=(float)w/4.0;
	float four_third_w=(float)w/(4.0/3.0);
	float half_w=(float)w/2.0;
 if( p->pos_p.x >= (int) half_w && back->pos_bg.x <= back->image->w - w ) 
  {
    back->pos_bg.x+=10;
    p->pos_p.x=w/2;
        
  }
   if( p->pos_p.x<= (int) one_fourth_w && (int) back->pos_bg.x>=0 )
    {
      back->pos_bg.x-=10;
      p->pos_p.x=w/3;

    }    
     if( p->pos_p.x >= four_third_w )//stop the M_sprite from going offscreen when scrolling ends   
      {
         p->pos_p.x= (int) four_third_w;
      }

}
// *-*-*-*BACKGROUND-*-*-*-*-*-*-***-*-*BACKGROUND-*-**-*-*-*-*-*-
