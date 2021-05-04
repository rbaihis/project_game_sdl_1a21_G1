#include "header.h"
#include "ennemi.h"
#include "background.h"


// main appel function and initialising variable below codes  
 
 
 ///--  AFFICHAGE , INITIALISATION et ANNIMATION
// !!!! important  init es.screenheigh and es.screenwidth in main is a must .
void initennemi(ennemi * e)
{  
  int ligne=4,colonne=3; // lignes et colonnes du sprite sheet
  e->image= IMG_Load("ennemi/mage660x1000.png");
  
  e->pos_e.w= e->image->w / colonne;
  e->pos_e.h= e->image->h / ligne;
  
  // animation settings
   e->pos_s.w= e->image->w / colonne;
  e->pos_s.h= e->image->h / ligne;
  e->direction=0;  // 0/1/2/3 level for a sprite sheet 3x4 sprites 
  
  // init speed , faster and velocity of the x&y   
  e->speed = 15;
  e->x_vel = e->y_vel = e->speed;
  e->faster = 1;
}

void afficher_ennemi(ennemi  e, SDL_Surface * screen)
{
   SDL_BlitSurface(e.image , &e.pos_s , screen , &e.pos_e );
}



void animer_ennemi( ennemi * e)
{
   int spritewidth= 660; // image width 
   
  // scrolling sheet left to right animation effect 
if( e->pos_s.x>= spritewidth - e->pos_s.w) 
 e->pos_s.x=0;
  else
   e->pos_s.x += e->pos_s.w;
       
  // scrolling sheet up or down to chose set of image to display 
  e->pos_s.y = e->pos_s.h * e->direction;//e->direction need to be initialised to 0/1/2/3 in main 
}

//------------------collision_bb------------------------------------------------------------

int collision_bb( personne p, ennemi es)
{
  if( (p.pos_p.x + p.pos_p.w < es.pos_e.x) || ( p.pos_p.x > es.pos_e.x +es.pos_e.w)
   || (p.pos_p.y + p.pos_p.h < es.pos_e.y) || ( p.pos_p.y > es.pos_e.y +es.pos_e.h)  )
   return 0; // return 0 where there is no collision
     else
       return 1;  // return 1 when there is collision 
}

//-------------------------------------------------------------------------------------------------


//------------ deplacement random 
void deplacer_ennemi( ennemi * es)
{
  if (es->image==NULL)
  {
     es->pos_e.y=1500;
  }
  else
{
  
  if(es->x_pos <= 0) 
  {
    es->faster++;
     
    if (es->faster >4 )
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
      es->direction=0;
      if( es->x_vel > 0 )
        es->direction=1; 

        // attack
       if( es->x_vel < 0 && es->collision==1 ) // facing left side
      es->direction=2;
      if( es->x_vel > 0 && es->collision==1 )// face right side
        es->direction=3; 
        
}          
}
//-------------------------------------------------------------------------------------------------



// ---------- artificial intelegence deplacement 
void deplaceria( ennemi * e, SDL_Rect pos_p )
{
  float distance;
  
  // calculating distance between two points using vector distane equation d(u⃗ ,v⃗ )=∥u⃗ −v⃗ ∥= √ ( ((u1−v1)2+(u2−v2)2...(un−vn)2) ).
  distance= sqrt( (( e->pos_e.x - pos_p.x)*( e->pos_e.x - pos_p.x))+(( e->pos_e.y - pos_p.y)*( e->pos_e.y - pos_p.y)) );
  
  printf("\n distance between ennemi an player = %.4f ", distance);
  
  if(distance <= 500 && (pos_p.x + pos_p.w) < e->pos_e.x )
  {
     e->pos_e.x -= 10;
      e->direction=0; // face left while moving left
      
       // attack  follow sprite sheet settings to change direction values
       if( distance<= 102 && e->direction ==0  ) // facing left side attack sheet set activate
      e->direction=2;
      
  }
  else if ( distance <= 500 && (pos_p.x + pos_p.w) > (e->pos_e.x  ) )
  {
    e->pos_e.x += 10 ; 
    e->direction=1;  // face right while looking right
    
     // attack  follow sprite sheet settings to change direction values
     if( distance<= 180 && e->direction ==1)// face right side attack sheet set activate
        e->direction=3;     
  }
  else if ( distance > 500 && (pos_p.x + pos_p.w) < (e->pos_e.x + e->pos_e.w ) )
  {
    e->pos_e.x = e->pos_e.x;
    e->direction=0; // face left while perso is far away in your left side
  }
    else if ( distance > 500 && (pos_p.x + pos_p.w) > (e->pos_e.x + e->pos_e.w ) )
  {
    e->pos_e.x = e->pos_e.x;
    e->direction=1; // face rightwhile perso is far away in your right side
  }
  


        
        // !!!! e->direction values depends on the sprite sheet photo
        
}



//----------optional_func
void init_object(obstacle *ob ,char * path)
{
  ob->image=IMG_Load(path);
  ob->pos_ob.h = ob->image->h;
  ob->pos_ob.w = ob->image->w;  
}

void pos_obstacle( obstacle * ob, int xpos, int ypos )
{
   ob->pos_ob.y = ypos;
   ob->pos_ob.x = xpos;
}

void afficher_obstacle(obstacle ob, SDL_Surface * screen)
{
   SDL_BlitSurface(ob.image , NULL, screen , &ob.pos_ob  );
}
//-------------------------------------------------------------
//-------------------------------------------------------------




/*
// main appel function and initialising variable below codes  

 
 "" main()  ""
 
      // ennemi settings and declaration seif  using 3 different ennemi 
   ennemi es,es2;      
   SDL_Surface * a[5];
                 // order is very important 
   // ennemi 1 
   es.screenwidth = 1400 ; es.screenheight = 600;
   initennemi( &es);
   es.direction=0;
   a[0]=es.image;
   es.sprite_width = es.image->w;   // needed in animation to avoid segfault 
   es.pos_e.y=350;
   
   // ennemi 2
   es2.screenwidth = 1400 ; es2.screenheight = 600;
   initennemi( &es2);
    es2.direction=0;
   a[1]=es2.image;
   es2.sprite_width = es2.image->w;
   es2.pos_e.y=350; es2.pos_e.x=1000;

   //--------------------------------------end seif 

 
 "" while(game) ""
 
 
//-----------------------ennemi seif appel debut 
   
   // avoid segfault and executing code when needed_only 
   if(es.image!=NULL && b.pos_bg.x>=3000)
   {
     
     if( b.pos_bg.x ==3010  )
      {
      es.pos_e.y=300; es.pos_e.x=900;
      }
   afficher_ennemi(es,screen);
   deplacer_ennemi( &es );
   animer_ennemi( &es);
   }
   if(es2.image!=NULL) 
   {
   afficher_ennemi(es2,screen);
   deplaceria( &es2, p.pos_p );
   animer_ennemi( &es2);
   }
   //---------------------------------------
   if ((collision_bb(p,es))== 1 )
        {
          //b.pos_bg.x -= 900; no need for it scrolling do the job with perso only now 
          p.pos_p.x +=  -450;
         // p.pos_p.x-=600;
         // es.image=NULL;
        }                    
   //------------------ seif fin appel
 
 
 
 
  ""  fin wile(game)  "" 
 
 
 for(int i=0;i<1;i++)
   {
     if(es.image==NULL) // to avoid segfault
     SDL_FreeSurface(a[0]);
    }
 if(es.image!=NULL) 
   SDL_FreeSurface(es.image);
 
 fin de program
  
 
 */
 
