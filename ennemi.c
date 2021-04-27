#include "header.h"
#include "ennemi.h"
#include "background.h"




void initennemi(ennemi *es)
{
  es->image=IMG_Load("wizard_sheet_800_600.png" );
  
  float z=((float) es->image->w)/3; //using float in case of error when dividing by int
  
  es->pos_e.w = (int) z;
  es->pos_e.h = es->image->h/4;
  
  //i chose the comment those functions because ill be using them in optional function
 //es->pos_e.x= es->screenwidth-simple_es->pos_e.w; 
 //es->pos_e.y= screenheight -simple_es->pos_e.h;  
 
   //loding animation sheet_loading
   //es->image =IMG_Load("wizard_sheet_800_600.png");
   es->pos_s.x=0;
   es->pos_s.y=0;
   es->pos_s.w=es->image->w/3;
   es->pos_s.h=es->image->h/4;
  
  // setting speed amount ;
   es->x_vel = es->y_vel = es->speed;
 
}


void afficher_ennemi(ennemi es, SDL_Surface * screen)// cant make it work no return no pointer to pass !!!?????
{
 
    SDL_BlitSurface( es.image , &es.pos_s ,screen, &es.pos_e);
          
}



void animer_ennemi( ennemi * es)
{  
   if(es->pos_s.x==600 - es->pos_s.w)
     es->pos_s.x=0; // image back to 0 to show first image in sheet
     else
       es->pos_s.x += es->pos_s.w; // move sprite cheet image forward 
       
       es->pos_s.y = es->direction * es->pos_s.h; // setting which line f the sprite sheet will be showen 
}

void deplacer_ennemi( ennemi * es)
{
  if (es->image==NULL)
  {
  
  }
  else
{
  
  if(es->x_pos <= 0) 
  {
    es->faster++;
     
    if (es->faster >7 )
     es->image=NULL;
      
    es->x_pos= 0; 
      es->x_vel = -(es->x_vel); 
  } 
                   
   if(es->y_pos <= 0) 
   {
     es->y_pos = 0; 
     es->y_vel = -(es->y_vel) ; 
   }
    if(es->x_pos >= es->screenwidth - es->pos_s.w) 
    {
      es->x_pos= es->screenwidth - es->pos_s.w; 
      es->x_vel = -(es->x_vel); 
    }
     if(es->y_pos >= es->screenheight - es->pos_s.h)  
      {
        es->y_pos = es->screenheight - es->pos_s.h; 
        
        es->y_vel = - (es->y_vel);  
      }

        // updating position
      es->x_pos += es->x_vel * es->faster;                        
      es->y_pos += es->y_vel *es->faster ;
      	
      	
      	// affecting it to rect variable;
        es->pos_e.x = es->x_pos ;
        es->pos_e.y = es->y_pos ;    
          
	//direct animation
      if( es->x_vel < 0 ) 
      es->direction=1;
      if( es->x_vel > 0 )
        es->direction=0; 

        // attack
       if( es->x_vel < 0 && es->collision==1 ) // facing left side
      es->direction=3;
      if( es->x_vel > 0 && es->collision==1 )// face right side
        es->direction=2; 
        
}          
}



int collision_bb( personne p, ennemi es)
{
  if( (p.pos_p.x + p.pos_p.w < es.pos_e.x) || ( p.pos_p.x > es.pos_e.x +es.pos_e.w)
   || (p.pos_p.y + p.pos_p.h < es.pos_e.y) || ( p.pos_p.y > es.pos_e.y +es.pos_e.h)  )
   return 0;
     else
       return 1; 
}


void deplaceria( ennemi * e, SDL_Rect pos_p )
{
  float predist,distance; int direction;
  
  distance= sqrt((( e->pos_e.x - pos_p.x)*( e->pos_e.x - pos_p.x))+(( e->pos_e.y - pos_p.y)*( e->pos_e.y - pos_p.y)));
  printf("\n distance between ennemi an player = %.4f ", distance);
  
  if(distance < 400 && (pos_p.x + pos_p.w) < e->pos_e.x )
  {
     e->pos_e.x -= 10;
  }
  else if ( distance < 400 && (pos_p.x + pos_p.w) > (e->pos_e.x ) )
    e->pos_e.x += 10 ; 
  /*else if ( distance < 400 && pos_p.x > (e->pos_e.x + e->pos_e.y) )
  {
    e->pos_e.x += 10 ;
  }*/
  else
  e->pos_e.x = e->pos_e.x;
}

