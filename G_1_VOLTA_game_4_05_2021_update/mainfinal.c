#include "header.h"
#include "ennemi.h"
#include "perso.h"
#include "background.h"
#include "enigme.h"
#include "enigmesahar.h"





void gameover(SDL_Surface * a, SDL_Surface * screen);

void gameover(SDL_Surface * a, SDL_Surface * screen)
{
   SDL_BlitSurface( a , NULL, screen , NULL  );
}


int main()
{
	
	SDL_Surface * go=IMG_Load("over.png");

   // declaration ,Init_SDL et Setting Screen  
   int c=1; int ggg=0,zzz=0;
   int width=1400,height=600;// window size
   surface * screen;
   SDL_Event  event;
   c=init_sdl(); // 0 if error so we dont enter the boucle de jeu 
   set_screen_void(&screen,width,height);// setting screen
   //----------------------------fin d'initialisation de fenetre 
    
    
   //init background & declaration
   background b;
   initialiser_background( &b);
   //----------------------------------end yessmin
   
   
   
  // load_main_perso_p & Declaration
  personne p,p1;
   initPerso(&p);
   initPerso(&p1);
   p.pos_p.x=1100;
   p.pos_p.x=200;
   p.vie_perso.nmbr_vie=0; 

  //----------------------------------end mouhamed
  
  
  
    // ennemi settings and declaration seif  using 3 different ennemi 
   ennemi es,es1,es2;      
   SDL_Surface * aaa[5];
   obstacle ob;
                 // order is very important 
   // ennemi 1 
   es.screenwidth = 1400 ; es.screenheight = 600;
   es.sprite_lignes=4;  es.sprite_colonnes=3;
   es.path="ennemi/wizard_sheet_800_600.png";
   initennemi( &es);
   es.direction=0;
   aaa[0]=es.image;
   es.sprite_width = es.image->w;   // needed in animation to avoid segfault 
   es.pos_e.y=400;
   
   // ennemi 2
   es2.screenwidth = 1400 ; es2.screenheight = 600;
   es2.sprite_lignes=4;  es2.sprite_colonnes=3;
   initennemi( &es2);
    es2.direction=0;
   aaa[1]=es2.image;
   es2.sprite_width = es2.image->w;
   es2.pos_e.y=350; es2.pos_e.x=1000;
   
   //obstacle 
   init_object( &ob ,"ennemi/coin.png");
   aaa[2]=ob.image;
   //--------------------------------------end seif 
   
   
  
   
   //----------enigme sahar starts
game t1[10];
ord t2[10];
int t3[10], t4[10];
int m=0,u=0,y=0;
for(y=1;y<=10;y++)
{
t3[y]=0;
}
for(m=1;m<=10;m++)
{
t4[m]=0;
}
SDL_Surface *img=NULL;
SDL_Rect pos;
//img= IMG_Load("backg.jpg");
//SDL_BlitSurface(img,NULL,screen,NULL);

int continuer=1;
int a,bbb,ccc,d,e,f,g,h,i,w,x;
//-------------------------------fin sahar


   
   
   p.vie_perso.nmbr_vie=0; 
   
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
                    ggg=1;
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
                     ggg=0;
                         
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
   //deplacer_perso(&p1); 
   // perso 1 & 2
   afficherPerso( p, screen);
   //afficherPerso( p1, screen); // for 2 players mode
 //------------------------------------------------- mohamed appel fin 
    
  
  
  
  
    
   //-----------------------ennemi seif appel debut 
   
   // avoid segfault and executing code when not needed
   
   if(es2.image!=NULL) 
   {
   afficher_ennemi(es2,screen);
   deplaceria( &es2, p.pos_p );
   animer_ennemi( &es2);
   }
   if(es.image!=NULL && b.pos_bg.x>=2500)
   {
     
     if( b.pos_bg.x ==3010  )
      {
      es.pos_e.y=300; es.pos_e.x=900;
      }
   afficher_ennemi(es,screen);
   deplacer_ennemi( &es );
   animer_ennemi( &es);
   }
   
   //-------obstacle
  
  
  
   //---------------------------------------
   if ((collision_bb(p,es))== 1 && ggg==0)
        { 
          p.pos_p.x +=  -450;
          p.vie_perso.nmbr_vie++;
           if( p.vie_perso.nmbr_vie==4)
          {
          p.vie_perso.nmbr_vie=0;
          zzz=1; 
          }
                
        }        
    else if ((collision_bb(p,es))== 1 && ggg==1 )
        {
          es.image=NULL;
          es.pos_e.y=1000;
        }       
            
         if ((collision_bb(p,es2))== 1 && ggg==0)
        {
          p.pos_p.x +=  -450;
          p.vie_perso.nmbr_vie++;
          if( p.vie_perso.nmbr_vie==4)
          {
          p.vie_perso.nmbr_vie=0;
          zzz=1; 
          }
        }        
         if ((collision_bb(p,es2))== 1 && ggg==1 )
         {
           es2.image=NULL;
           es2.pos_e.y=1000;
         }       
              
                    
   //------------------ seif fin appel
   
   
   //--------- ------------------------------------sahar debut appel
//-----------------------------------------------------------------
//-----------------------------------------------------------------
   if(b.pos_bg.x==2100 )
{

while (continuer==1)
{
initaaa(t1,screen);
initord(t2);
SDL_Flip(screen);

  SDL_Delay(40);
    SDL_WaitEvent(&event);  
    switch(event.type) 
    {
       case SDL_QUIT: 
            continuer = 0;
            break;
        case SDL_KEYDOWN: 
            switch (event.key.keysym.sym) 
            {
                case SDLK_o: 
                   
put_x(screen,t2[1].pos);
a=1;t2[1].n=1;t3[1]=1;
                   do
                   {srand(time(NULL));w=1+rand()%8;}
while(t2[w].n==1|| veriftab(t2)==9 );
t2[w].n=1;
put_o(screen,t2[w].pos);
t4[w]=1;

                   
                    break;
                case SDLK_b: 
                put_x(screen,t2[2].pos);bbb=1;t2[2].n=1;t3[2]=1;
                   do
                   {srand(time(NULL));
w=1+rand()%8;}
while(t2[w].n==1 || veriftab(t2)==9);t2[w].n=1;put_o(screen,t2[w].pos);

t4[w]=1;
                break;
                case SDLK_c: 
              put_x(screen,t2[3].pos);ccc=1;t2[3].n=1;t3[3]=1;
                    do
                   {srand(time(NULL));w=1+rand()%8;}
while(t2[w].n==1 || veriftab(t2)==9 );
t2[w].n=1;
put_o(screen,t2[w].pos);
t4[w]=1;
                break;
                case SDLK_d:
                put_x(screen,t2[4].pos);d=1;t2[4].n=1;t3[4]=1;
                   do
                   {srand(time(NULL));
w=1+rand()%8;}
while(t2[w].n==1 && veriftab(t2)!=9 );
t2[w].n=1;
put_o(screen,t2[w].pos);
t4[w]=1;
                 break;
                case SDLK_e:
                put_x(screen,t2[5].pos);e=1;t2[5].n=1;t3[5]=1;
                   do
                   {srand(time(NULL));w=1+rand()%8;}
while(t2[w].n==1 || veriftab(t2)==9);
t2[w].n=1;
put_o(screen,t2[w].pos);
t4[w]=1;

                 break;
                 case SDLK_f:
                put_x(screen,t2[6].pos);f=1;t2[6].n=1;t3[6]=1;
                   do
                   {srand(time(NULL));w=1+rand()%8;}
while(t2[w].n==1 || veriftab(t2)==9 );
t2[w].n=1;
put_o(screen,t2[w].pos);
t4[w]=1;

                 break;
                 case SDLK_g:
              put_x(screen,t2[7].pos);g=1;t2[7].n=1;t3[7]=1;
                    do
                   {srand(time(NULL));w=1+rand()%8;}
                    while(t2[w].n==1 || veriftab(t2)==9 );
                    t2[w].n=1;
                    put_o(screen,t2[w].pos);
t4[w]=1;
                 break;
                 case SDLK_h:
                put_x(screen,t2[8].pos);h=1;t2[8].n=1;t3[8]=1;u++;
                   do
                   {srand(time(NULL));w=1+rand()%8;}
                    while(t2[w].n==1 || veriftab(t2)==9 );
                    t2[w].n=1;
                    put_o(screen,t2[w].pos);
t4[w]=1;
                 break;
                 case SDLK_i:
                put_x(screen,t2[9].pos);i=1;t2[9].n=1;t3[9]=1;
                 do
                   {srand(time(NULL));w=1+rand()%8;}
                   while(t2[w].n==1 || veriftab(t2)==9 );
                   t2[w].n=1;
                   put_o(screen,t2[w].pos);
t4[w]=1;

                 break;
            }
            break;
    }
int s=0;
s=chekwin(t3,screen,t4);
SDL_Delay(1000/60);
if(s==1 || s==-1 )
{
SDL_Delay(1000);
continuer=0;
}

}

   
  } 
//------------------------------------------------------------sahar fin appel 
   
   
   
  // gameover 
  /* 
if(zzz==1 )
{ 
    
        es.image=aaa[0];
    	es2.image=aaa[1];
    	
    	gameover(go,screen);
        SDL_Flip(screen);
     	
    	SDL_Delay(3000);       
    	
    	for(int i=0;i<9;i++)
    	es.pos_e.x += 70;
    	
    	b.pos_bg.x=0;
        p.pos_p.x=100;
    	es.pos_e.x=1100;
    	es2.pos_e.y=350;
    	 SDL_Flip(screen);
    	 zzz=0;
} 

*/  
   
   printf("\n %d bg scrolling position",b.pos_bg.x);   
   SDL_Delay(1000/24);
   SDL_Flip(screen);
   
   
   }// end while game 
   
    // Free ES      
   for(int i=0;i<1;i++)
   {
     if(es.image==NULL) // to avoid segfault
     SDL_FreeSurface(aaa[0]);
    }
   
   p.vie_perso.nmbr_vie=0; 
   if(es.image!=NULL) 
   SDL_FreeSurface(es.image);
   //SDL_FreeSurface(p.image);
   SDL_FreeSurface(b.image);
   SDL_FreeSurface(screen);
   SDL_Quit();
  return 0;
  
}
