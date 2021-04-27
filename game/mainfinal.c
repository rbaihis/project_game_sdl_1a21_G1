#include "header.h"
#include "ennemi.h"
#include "perso.h"
#include "background.h"
#include "enigme.h"


int main()
{
   background b; personne p,p1; ennemi es;
   surface * screen; SDL_Event  event;
   int speed =5; int c=1; int width=1400,height=600;// window size
   SDL_Surface * a[5];
   
   c=init_sdl();
   set_screen_void(&screen,width,height);// setting screen
   
   
   //init background 
   initialiser_background( &b);
   
  // load_main_perso_p
   initPerso(&p);
   initPerso(&p1);
  
   //Enemi_load  
   initennemi( &es);
   
   es.pos_e.x=900; es.pos_e.y=300;
   p.pos_p.x=1100;
   
   a[0]=es.image;
   p.pos_p.x=300;
   while(c==1)
   {
   
   //----------********background functions 
   afficher_background(b,*screen);
   if((p.direction==0 && p.stop==1)||( p.direction==1 && p.stop==1))     
   scrolling2(&p,&b,1400,694);
   //------------------------------fin background  solo window
   
   
   
   //---------------********mohamed's perso + pollevents Debut 
    while(SDL_PollEvent(&event))
   {
    quit_event(&event,&c);
    //movement_event(&event,&p);
    // scrolling(&p,&b,width,height);
    switch(event.type ) 
   { 
   case SDL_KEYDOWN: 
        switch(event.key.keysym.sym)
        {    
            case SDLK_RIGHT: 
                   p.direction=0; 
                   p.stop=1;       
              deplacer_perso(&p);
                   break ;                     
               
            case SDLK_LEFT: 
               p.direction=1;  
               p.stop=1;      
               deplacer_perso(&p);
                    break ; 
                           
                case SDLK_LSHIFT:            
               accelrer_perso(&p);               
                    break ;

             case SDLK_UP:
                p.up=1;        
                jump_perso(&p);
                    break ;
                    
                    case SDLK_a:     
                   p.direction=2;
                    attack_perso( &p); 
                   break ;                                             
     }   
     break;
     //*****************KEY UP------------------//
       case SDL_KEYUP: 
        switch(event.key.keysym.sym)
        {                       
           
             case SDLK_UP:
                p.up=0;        
                jump_perso(&p);
                    break ;
                    
                    case SDLK_a:
                     p.num=0; 
                         
                    break ;
                    
              case SDLK_RIGHT: 
                p.stop=0;   
              
                   break ;
                   
            case SDLK_LEFT: 
                p.stop=0;
                    break ;                  
     	}   
     break;
       }
       
       switch(event.type ) 
   { 
   case SDL_KEYDOWN: 
        switch(event.key.keysym.sym)
        {    
            case SDLK_d: 
                   p1.direction=0; 
                   p1.stop=1;       
              deplacer_perso(&p1);
                   break ;                     
               
            case SDLK_q: 
               p1.direction=1;  
               p1.stop=1;      
              deplacer_perso(&p1);
                    break ; 
                           
                case SDLK_TAB:            
               accelrer_perso(&p1);               
                    break ;

             case SDLK_z:
                p1.up=1;        
                jump_perso(&p1);
                    break ;
                    
                    case SDLK_o:     
                   p1.direction=2;
                    attack_perso( &p1); 
                   break ;                              
     }   
     break;
     //*****************KEY UP------------------//
       case SDL_KEYUP: 
        switch(event.key.keysym.sym)
        {                        
             case SDLK_z:
                p1.up=0;        
                jump_perso(&p1);
                    break ;
                    
                    case SDLK_o:
                     p1.num=0; 
                         
                    break ;
                    
              case SDLK_d: 
                p1.stop=0;   
              
                   break ;
                   
            case SDLK_q: 
                p1.stop=0;
                    break ;                  
     	}   
     break;
       }
     
   }  
   deplacer_perso(&p); 
   deplacer_perso(&p1); 
   // perso 1 & 2
   afficherPerso( p, screen);
   afficherPerso( p1, screen); // to be deleted 
   
 //-------------------------- mohamed appel fin 
    
  
  
  
   //-----------------------ennemi seif appel debut 
   afficher_ennemi(es,screen);
   deplaceria( &es, p.pos_p );
   animer_ennemi( &es);
   if ((collision_bb(p,es))== 1 )
        {
          //b.pos_bg.x -= 900; no need for it scrolling do the job with perso only now 
          p.pos_p.x=0;
         // p.pos_p.x-=600;
          p.pos_p.y=380; 
         // es.image=NULL;
        }                    
   //------------------ seif fin appel
   
   
   
   
   
   
   
   
   
   
   SDL_Delay(1000/60);
   SDL_Flip(screen);
   
   
   }// end while game 
   
    // Free ES      
   for(int i=0;i<1;i++)
   {
     if(es.image==NULL) // to avoid segfault
     SDL_FreeSurface(a[0]);
    }
   
   if(es.image!=NULL) 
   SDL_FreeSurface(es.image);
   //SDL_FreeSurface(p.image);
   SDL_FreeSurface(b.image);
   SDL_FreeSurface(screen);
   SDL_Quit();
  return 0;
}
